#include <bits/stdc++.h>
using namespace std;

int n;
int pos[202];
int dp[202];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i];
	}
}

void solve() {

	int r = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		// 3 7 5 2 6 1 4
		for (int j = 1; j < i; j++) {
			if (pos[j] < pos[i] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		r = max(r, dp[i]);
	}
	cout << n - r; // 이동횟수 = 전체 수열 길이 - 최대증가 부분수열 길이
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();

	return 0;
}	