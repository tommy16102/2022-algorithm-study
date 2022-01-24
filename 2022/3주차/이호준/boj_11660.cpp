/*******************************************************************
Algorithm Study
Baekjoon OJ DP
11660 구간 합 구하기 5
2022/01/24 이호준
# 아이디어
1. 각 행에 각 열까지의 합을 넣어놓고 구간의 합을 구간합의 합을 이용한 연산을 통해 구한다.
4가지 경우의 수로 나눌 수 있다.
한 점
같은 행의 두점
같은 열의 두점
그외 경우의 수
*******************************************************************/
#include <iostream>

int dp[1025][1025];

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;

    cin >> x >> y;

    for (int i = 0; i < x; i++)
    {
        int sum = 0;
        for (int j = 0; j < x; j++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            dp[i][j] = sum;
        }
    }

    for (int i = 0; i < y; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == c && b == d)
        {
            cout << (b != 1 ? dp[a - 1][b - 1] - dp[a - 1][b - 2] : dp[a - 1][b - 1]) << '\n';
        }
        else if (a == c)
        {
            cout << (b != 1 ? dp[a - 1][d - 1] - dp[a - 1][b - 2] : dp[a - 1][d - 1]) << '\n';
        }
        else if (b == d)
        {
            int temp = 0;
            for (int i = a - 1; i <= c - 1; i++)
            {
                temp += (b != 1 ? dp[i][b - 1] - dp[i][b - 2] : dp[i][b - 1]);
            }
            // cout << (b != 1 ? dp[a - 1][b - 1] - dp[a - 1][b - 2] + dp[c - 1][d - 1] - dp[c - 1][d - 2] : dp[a - 1][b - 1] + dp[c - 1][d - 1]) << '\n';
            cout << temp << '\n';
        }
        else
        {
            int min_x = a < c ? a : c;
            int max_x = a > c ? a : c;
            int max_y = b > d ? b : d;
            int min_y = b < d ? b : d;
            int temp = 0;
            if (min_y != 1)
            {
                for (int i = min_x - 1; i <= max_x - 1; i++)
                {
                    temp += (dp[i][max_y - 1] - dp[i][min_y - 2]);
                }
            }
            else
            {
                for (int i = a - 1; i <= c - 1; i++)
                {
                    temp += dp[i][max_y - 1];
                }
            }
            cout << temp << '\n';
        }
    }

    return 0;
}