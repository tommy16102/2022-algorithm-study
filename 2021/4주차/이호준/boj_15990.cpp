/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
15990 1, 2, 3 더하기5
2021/07/28 이호준
# 아이디어
1. 같은 수를 두번이상 가진 합을 구해서 전체에서 빼면되지 않을까?
dp로 해결할 수 없는것 같다. 왜냐하면 3으로 중복이 되는 case는 6에서 처음 3+3으로 등장하는데
이걸 기준으로 하면 겹치는 것들이 많이 존재.

2. 뒷자리 숫자를 신경쓰면서 dp를 진행한다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 9;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> count(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> count[i];
    }

    int max = *max_element(count.begin(), count.end());
    vector<vector<unsigned int>> dp(max + 1, vector<unsigned int>(4, 0));
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    if (max <= 3)
    {
        for (auto &a : count)
        {
            cout << (a == 1 ? 1 : a == 2 ? 1
                                         : 3)
                 << "\n";
            return 0;
        }
    }
    for (int n = 4; n <= max; n++)
    {
        if (n - 1 >= 0)
        {
            dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % mod;
        }
        if (n - 2 >= 0)
        {
            dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % mod;
        }
        if (n - 3 >= 0)
        {
            dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % mod;
        }
    }
    for (auto a : count)
    {
        cout << (dp[a][1] + dp[a][2] + dp[a][3]) % mod << "\n";
    }
    return 0;
}
/*
	1 

	2 = 2 + 0

	3 = 1+ 2
	  = 3
	  = 2+1
	
	4 = 1 + 3 - > 3

	5 = 

	2 = 1 + 1
	  = 2 

	3 // = 1 + 1 + 1
	  = 1 + 2
	  = 2 + 1
	  = 3
   4 //  = 1 + 1 + 1 + 1
     //  = 1 + 1 + 2
	 = 1 + 2 + 1
	 // = 2 + 1 + 1
	 // = 2 + 2
	 = 3 + 1
	 = 1 + 3
*/