/*******************************************************************
Algorithm Study
Baekjoon OJ DP
2133 타일 채우기
2022/01/19 이호준
# 아이디어
1. 풀지 못했다.
홀수 개수는 0이라는 것을 알았으나
그 이후를 풀지 못했다..

개념은 이해했으나 백준에 풀지않았고 다시 풀도록 하겠다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int DP[35];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    if (N % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] += (DP[j] * 2);
        }
    }
    cout << DP[N] << endl;

    return 0;
}
