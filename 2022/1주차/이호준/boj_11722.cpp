/*******************************************************************
Algorithm Study
Baekjoon OJ DP
11722 가장 긴 감소하는 부분 순열
2022/01/05 이호준
# 아이디어
1. DP 문제

현재 index까지 해당하는 감소하는 순열을 찾아 저장한다.

※ 가장 긴 증가하는 부분 순열 시리즈를 풀면서 복습해야함.
*******************************************************************/
#include <iostream>

int A[1001];
int dp[1001];

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int answer = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (A[i] < A[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (answer < dp[i])
            answer = dp[i];
    }
    cout << answer << '\n';

    return 0;
}