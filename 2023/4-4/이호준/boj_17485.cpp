/*******************************************************************
Algorithm Study
Baekjoon 17485 진우의 달 여행
2023/04/28 이호준
# 아이디어
1. DP
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

int dp[1002][1002][3];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> costs(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> costs[i][j];
    }

    fill(&dp[0][0][0], &dp[n][m][3], INF);
    
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 3; j++)
            dp[0][i][j] = costs[0][i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j == 1){
                dp[i][j][1] = dp[i-1][j][2] + costs[i][j];
                dp[i][j][2] = min(dp[i-1][j + 1][1], dp[i-1][j + 1][0]) + costs[i][j];
            }else if (j == m){
                dp[i][j][0] = min(dp[i-1][j - 1][1], dp[i-1][j - 1][2]) + costs[i][j];
                dp[i][j][1] = dp[i-1][j][0] + costs[i][j];
            }else{
                dp[i][j][0] = min(dp[i-1][j - 1][1], dp[i-1][j - 1][2]) + costs[i][j];
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + costs[i][j];
                dp[i][j][2] = min(dp[i-1][j + 1][0], dp[i-1][j + 1][1]) + costs[i][j];
            }
        }
    }

    int answer = INF;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 3; j++)
            answer = min(answer, dp[n][i][j]);
    }

    cout << answer;
    
    return 0;
}