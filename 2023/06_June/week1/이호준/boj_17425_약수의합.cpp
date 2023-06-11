/*******************************************************************
Algorithm Study
Baekjoon 17425 약수의 합
2023/06/10 이호준
# 아이디어
1. 누적합
*******************************************************************/
#include <iostream>
#define MAX 1000001

using namespace std;
typedef long long ll;

ll dp[MAX];
int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t, n;
    ll sum = 0;
    cin >> t;

    for(int i = 1; i <= MAX; ++i){
        for(int j = i; j <= MAX; j+=i){
            dp[j] += i;
        }
    }

    for(int i = 2; i <= MAX; i++){
        dp[i] += dp[i-1];
    }

    while (t--){
        cin >> n;
        cout << dp[n] <<"\n";
    }

    return 0;
}