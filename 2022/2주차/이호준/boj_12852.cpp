/*******************************************************************
Algorithm Study
Baekjoon OJ DP
12852 1로 만들기 2
2022/01/07 이호준
# 아이디어
1. 99% 시간초과가 발생하여 왜 그런지 찾느라 오래걸렸다. 구글에 %2, %3의 방식으로 풀었길래 변경하였으나 똑같이 99%에서 시간초과였다.

=> 출력하는 과정에서 trace배열의 index를 접근하는 시간이 오래걸렸다. cout << trace[target] << " "로 하면 trace에 접근하느 시간이
2배이므로 이것으로 시간초과가 발생하였다. 배열에 굳이 접근할 필요가 없었는데 로직이 중복되어 시간초과가 발생하였다.
출력이라고 대충할 것이 아니라 모든 코드를 정확히 작성해야겠다.
좀 더 신경쓰고 중복 로직을 없애는 것을 항상 확인해야겠다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int trace[1000001];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;

    cin >> target;

    vector<int> dp(target + 1, 1000001);
    dp[1] = 0;
    for (int i = 1; i < target + 1 / 2; i++)
    {
        if (i + 1 <= target && dp[i + 1] > dp[i] + 1)
        {
            dp[i + 1] = dp[i] + 1;
            trace[i + 1] = i;
        }
        if (i * 2 <= target && dp[i * 2] > dp[i] + 1)
        {
            dp[i * 2] = dp[i] + 1;
            trace[i * 2] = i;
        }
        if (i * 3 <= target && dp[i * 3] > dp[i] + 1)
        {
            dp[i * 3] = dp[i] + 1;
            trace[i * 3] = i;
        }
    }

    cout << dp[target] << endl;
    while (1)
    {
        cout << target << " ";
        target = trace[target];
        if (target == 0)
            break;
    }

    return 0;
}