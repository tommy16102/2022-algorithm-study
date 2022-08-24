#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> students;
int b;
int c;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		students.push_back(t);
	}
	cin >> b >> c;
}

void solve() {
	long long ans = 0;
	for (int i = 0; i < students.size(); i++) {
		students[i] -= b;
		ans++;
	}

	for (int i = 0; i < students.size(); i++) {
		if (students[i] > 0) {
			ans += 1 + students[i] / c;
			if (students[i] % c == 0)
				ans--;
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