#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[31];
// 2x1 1x2
// 3x2 dp[1]+dp[2] + dp[2]+dp[1]
// 3x2 = 3
// 3x4 = 9+2 = 11
// 3x6 = 3*dp[4] + 2*dp[2] + 2
// 3x8 = 3*dp[6] + 2*dp[4] + 2*dp[2]
// 3x10 = 3*dp[8] + 2*dp[6] + 2*dp[4] + 2*dp[2]
// ------ // 13 22 31
// ------ // 15 24 33 42 51
// ------ // 17 26 35 44 53 62 71

void input() {
	cin >> n;
}

void solve() {

	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	for (int i = 4; i <= 30; i++) {
		int d = 0;
		if (i % 2 != 0) {
			dp[i] = 0;
		}
		else {
			d += 3 * dp[i - 2]; // 3*dp[4]
			for (int j = 2; j < i-2; j += 2) {
				d += 2 * dp[j];
			}
			d += 2;
			dp[i] = d;
		}
	}
	cout << dp[n];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}