/*******************************************************************
Algorithm Study
Baekjoon 1943 동전분배
2023/04/19 이호준
# 아이디어
1. DP (0-1 Knapsack)
내가 가진다
내가 가지지 않는다 -> 남이 가진다.
목표 나는 총 합의 반을 가진다. -> 나머지 합이 반이다.. (총 합 N -> N/2를 만들 수 있냐?)
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool dp[50001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 3;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> coins;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int price, count;
            cin >> price >> count;
            sum += (price * count);
            coins.push_back({price, count});
        }
        if(sum % 2 != 0){
            cout << 0 <<"\n";
            continue;
        }
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(auto coin : coins){
            for(int i = sum / 2; i >= coin.first; i--){
                if(dp[i - coin.first]){
                    for(int k = 0; k < coin.second; k++){
                        // for (k = 1; k <= coin.second; k++)
                        //     dp[i - coin.first + k * coin.first]
                        if (i + k * coin.first > sum / 2)
                            break;
                        dp[i + k * coin.first] = true;
                    }
                }
            }
        }

        if(dp[sum/2])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
        
    }
    
    return 0;
}