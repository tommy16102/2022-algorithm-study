#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000001];
void input() {
	cin >> n;
}

void solve() {

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 != 0) { // 3으로만 나눠짐
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 3 != 0 && i % 2 == 0) { // 2로만 나눠짐
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else if (i % 3 != 0 && i % 2 != 0) { // 둘다 안나눠짐
			dp[i] = dp[i - 1] + 1;
		}
		else { // 둘다 나눠짐
			int t1 = min(dp[i / 2], dp[i / 3]);
			dp[i] = 1 + min(t1, dp[i - 1]);
		}
	}

	int x = n;
	cout << dp[x] << "\n";
	cout << x << " ";
	while (x > 1) {
		if (x % 3 == 0 && x % 2 != 0) { // 3으로만 나눠짐
			if (dp[x / 3] < dp[x - 1]) { // x/3으로 가는 길이 더 최소
				cout << x / 3;
				x /= 3;
			}
			else { // x-1로 가는길이 더 최소
				cout << x - 1;
				x -= 1;
			}
		} // ...
		else if (x % 3 != 0 && x % 2 == 0) {
			if (dp[x / 2] < dp[x - 1]) {
				cout << x / 2;
				x /= 2;
			}
			else {
				cout << x - 1;
				x -= 1;
			}		
		}
		else if (x % 3 != 0 && x % 2 != 0) {
			cout << x - 1;
			x -= 1;
		}
		else {
			int x3 = dp[x / 3];
			int x2 = dp[x / 2];
			int x1 = dp[x - 1];
			int t = min(x1, x2);
			int mi = min(t, x3);
			if (mi == x1) {
				cout << x - 1;
				x -= 1;
			}
			else if (mi == x2) {
				cout << x / 2;
				x /= 2;
			}
			else if (mi == x3) {
				cout << x / 3;
				x /= 3;
			}

		}
		cout << " ";
	}

	// max(dp[i/3], dp[i/2], dp[i-1])
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}