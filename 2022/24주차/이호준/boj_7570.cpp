/*******************************************************************
7570 줄 세우기
2022/10/27 이호준
# 아이디어
1. DP
2. 최장증가수열
*******************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, x;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> x;
        dp[x] = dp[x - 1] + 1;
    }

    cout << n - *max_element(dp, dp+n);

    return 0;
}

