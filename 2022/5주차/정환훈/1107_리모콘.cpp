#include <bits/stdc++.h>
using namespace std;

int n;
int m;
bool broken[10];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		broken[t] = true;
	}
}
bool canmake(int x) {

	string t = to_string(x);
	for (int i = 0; i < t.size(); i++) {
		if (broken[t[i] - '0']) {
			return false;
		}
	}
	return true;
}

void solve() {
	if (n == 100) {
		cout << 0;
		return;
	}

	int ans = abs(n - 100); // 100에서 +-만했을때 기본값
	for (int i = 0; i <= 1000000; i++) { // 전수조사
		int t = 0;
		if (canmake(i)) { // 해당 숫자를 만들 수 있으면
			t += abs(i - n); // +-누르는 횟수
			t += to_string(i).size(); // 리모콘 누르는 횟수
			ans = min(ans, t);
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