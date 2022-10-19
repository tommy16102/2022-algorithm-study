#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n; int m;
int v[2001];
int dp[2001][2001];
pair<int, int> p[1000001];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s; int e;
		cin >> s >> e;
		p[i] = { s, e };
	}
}

void solve() {

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n - 1; i++) {
		if (v[i] == v[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	// i : 구간의 길이, j : 구간의 시작
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (v[j] == v[i+j] && dp[j + 1][i + j - 1] == 1) {
				dp[j][i + j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << dp[p[i].first][p[i].second] << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	
	return 0;
}
