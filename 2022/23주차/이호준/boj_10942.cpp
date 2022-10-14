/*******************************************************************
10942 팰린드롬?
2022/10/14 이호준
# 아이디어
1. DP
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;


int arr[2001];

int dp[2001][2001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n; i++){
        dp[i][i] = 1;
    }

    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i+1])
            dp[i][i + 1] = 1;
    }

    for(int a = 2; a < n; a++){
        for(int i = 0; i + 1 < n && i + a < n; i++){
            if(dp[i + 1][i + a - 1] && arr[i] == arr[i+a])
                dp[i][i + a] = 1;
        }
    }
    

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-1] <<"\n";
    }

    return 0;
}