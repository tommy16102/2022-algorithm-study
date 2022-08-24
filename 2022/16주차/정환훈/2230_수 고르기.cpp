#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; int m; vector<int> a;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
}

void solve() {
	sort(a.begin(), a.end());
	int l = 0; int r = 0;
	int ans = 2000000001;
	while (l < n && r < n) {
		if (a[r] - a[l] == m) {
			cout << m;
			return;
		}
		if (a[r] - a[l] < m) {
			r++;
		}
		else {
			ans = min(ans, a[r] - a[l]);
			l++;
		}

	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	return 0;
}