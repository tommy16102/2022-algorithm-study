/*******************************************************************
Algorithm Study
Baekjoon 22871 징검다리건너기(Large)
2023/06/10 이호준
# 아이디어
1. DP
*******************************************************************/
#include <iostream>
#include <algorithm>

#define MAX 5001

using namespace std;

typedef long long ll;
 
int N = 5001;
int n;
ll arr[MAX], dp[MAX];
 
ll go(int x) {
    if (x == n - 1) return 0;
    ll& ret = dp[x];
    if (ret != 0) return ret;
 
    ret = 1e10;
    for (int i = x + 1; i < n; i++) {
        ret = min(ret, max(go(i), (i - x) * (1 + abs(arr[x] - arr[i]))));
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << go(0);
 
    return 0;
}
