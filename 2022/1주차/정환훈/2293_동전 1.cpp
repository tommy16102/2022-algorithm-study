#include <bits/stdc++.h>
using namespace std;

int n; int k;
int coins[1000];
int dp[50000];

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> coins[i];
	}
}

void solve() {
	dp[0] = 1;
	for (int i = 1; i <= n; i++) { // 주어진 코인들(오림차순) 전부 사용
		for (int j = coins[i]; j <= k; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];
    
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}