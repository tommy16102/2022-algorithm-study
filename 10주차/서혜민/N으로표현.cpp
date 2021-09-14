#include <string>
#include <vector>
#include <limits.h>
using namespace std;

/*

2021.09.14

dp가 아닌 dfs를 통해 풀었다.
0부터 시작하여 입력받은 N으로 만들 수 있는 모든 수를 사칙연산을 통해서 계산하여 number가 되었을 때 그때의 사용된 N의 개수의 최소값을 구해줬다.

*/

int arr[6] = { 1,11,111,1111,11111,111111 };
int answer = -1;

void dfs(int num, int N, int now, int cnt) {
    if (cnt > 8) return;
    if (now == num && (answer == -1 || cnt < answer)) answer = cnt;
    for (int i = 0;i < 6;i++) {
        dfs(num, N, now + (N * arr[i]), cnt + i + 1);
        dfs(num, N, now - (N * arr[i]), cnt + i + 1);
        dfs(num, N, now * (N * arr[i]), cnt + i + 1);
        dfs(num, N, now / (N * arr[i]), cnt + i + 1);
    }
}

int solution(int N, int number) {
    dfs(number, N, 0, 0);
    return answer;
}
