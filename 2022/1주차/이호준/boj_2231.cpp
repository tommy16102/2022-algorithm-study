/*******************************************************************
Algorithm Study
Baekjoon OJ DP
2231 반복순열
2022/01/05 이호준
# 아이디어
1. 같은 알고리즘으로 다음 숫자를 생성하기 때문에 같은 숫자가 나오면 반복순열을 발견하는 것이다.
그러므로 count횟수 저장하여 count가 2되는 순간 dfs를 탈출하고 count가 1인 반복되지 않은 number의 수를 찾으면 된다.

순열을 모두 저장하여 첫번째로 count==2가 되는 순간에 탈출하고 그 숫자를 순열에서 찾아
인덱스로 계산하여 처리할려했으나 메모리 초과가 발생하였다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;

vector<int> visited(MAX, 0);
vector<int> input;
// int DFS(int num, int P);
void DFS(int num, int P);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, P, answer;
    cin >> A >> P;
    DFS(A, P);

    int count = 0;
    for (int i = 0; i <= MAX; i++)
    {
        if (visited[i] == 1)
            count++;
    }
    printf("%d\n", count);
    return 0;
}

int calc(int A, int P)
{
    int temp = A;
    int sum = 0;
    while (temp > 0)
    {
        sum += (int)(pow(temp % 10, P));
        temp /= 10;
    }
    return sum;
}
void DFS(int num, int P)
{
    visited[num]++;
    if (visited[num] > 2)
        return;
    DFS(calc(num, P), P);
}

// int main(void) {
//	int A, P, answer;
//	cin >> A >> P;
//	input.push_back(A);
//	answer = DFS(A, P);
//
//	int count = 0;
//	/*for (int i = 0; i <= MAX; i++) {
//		if (visited[i] == 1)
//			count++;
//		else
//			continue;
//	}*/
//	for (int i = 0; i <= MAX; i++) {
//		if (input[i] == answer) {
//			count = i;
//			break;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
// }

// int DFS(int num, int P) {
//	visited[num]++;
//	if (visited[num] > 2) return num;
//	int next = calc(num, P);
//	input.push_back(next);
//	DFS(next, P);
// }
