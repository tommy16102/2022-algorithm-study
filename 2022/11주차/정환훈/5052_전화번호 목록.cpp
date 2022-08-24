#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> strs;
void input() {
	cin >> n;
	strs.clear();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		strs.push_back(str);
	}
}

void solve() {
	sort(strs.begin(), strs.end());

	// 문자열 정렬 후 두 개씩 살펴본다.

	for (int i = 0; i < strs.size(); i++) {
		if (i + 1 != strs.size()) {

			if (strs[i].size() > strs[i + 1].size())
				continue;

			if (strs[i] == strs[i + 1].substr(0, strs[i].size())) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
	
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}


	return 0;
}