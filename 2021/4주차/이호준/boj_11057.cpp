/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
11057 오르막 수 
2021/07/28 이호준
# 아이디어
1. 0 : 0 ~ 9
   1 : 1 ~ 9 
   2 : 2 ~ 9
   ---
   9 : 9
  결국 i~9까지인데 많은 숫자 들이 겹친다. 생각해 보면 나보다 큰 모든 수에 영향을 겹치게 준다
  0은 1개, 1은 2개, 9는 10개에 영향을 준다.
  1이라면 0인 것들에 ..
  2라면 1인 것들에...
  dp[i][j] = dp[i - 1][j] + dp[i][j - 1] // 동일 + 증가

※ for문 3개를 쓸려했으나 너무 많은 것 같아 줄여봄 (효율성 높이기 중복 줄이기 역삼각형 중첩을 줄여보자)
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
ll dp[1001][10];
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int N;
    cin >> N;
    ll answer = 0;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }
    for (auto a : dp[N])
        answer += a % 10007;
    cout << answer % 10007;
    return 0;
}

/*
1 1 1 1 1 1 1 1 1 1 1
1 2 3 4 5 6 7 8 9 10

0 이면 0 ~ 9
1 이면 1 ~ 9
9 이면 9
*/