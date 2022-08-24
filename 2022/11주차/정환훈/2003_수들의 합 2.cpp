#include <bits/stdc++.h>
using namespace std;

int n; int m;
vector<int> seq;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		seq.push_back(t);
	}
}


int getSumByRecur(int a, int b) {
	if (a == b)
		return seq[a];
	int k = (a + b) / 2; // (1,5) => (1,3) + (3,5) => (1,2) + (2,3) + (3,4) + (4,5)
	// (0,1) = (0,0) + (1,1)
	return getSumByRecur(a, k) + getSumByRecur(k + 1, b);

}

void solve() {
	int ans = 0;
	//for (int i = 0; i < n; i++) {
	//	dp[i][i] = seq[i];
	//}

	//for (int len = 2; len <= n; len++) {
	//	for (int i = 0; i < n; i++) {
	//		int j = i + len - 1;
	//		if (j >= n) { break; }
	//		int k = (i + j) / 2;
	//		dp[i][j] = dp[i][k] + dp[k + 1][j];
	//	}
	//}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (dp[i][j] == m)
	//			ans++;
	//	}
	//}


	//for (int i = 0; i < n; i++) {
	//	for (int j = i; j < n; j++) {
	//		if (getSumByRecur(i, j) == m)
	//			ans++;
	//	}
	//}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += seq[j];
			if (sum == m) {
				ans++;
				break;
			}
		}

	}

	cout << ans;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}