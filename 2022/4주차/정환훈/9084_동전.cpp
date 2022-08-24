#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int m;
int coins[22];
int dp[10002];
void input() {
	for (int i = 0; i < 10002; i++) {
		dp[i] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	cin >> m;
}


void solve() {

	dp[0] = 1; // 아무것도 안쓰는 경우
	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[m] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}
	return 0;
}