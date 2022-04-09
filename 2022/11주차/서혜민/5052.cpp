#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];

		sort(v.begin(), v.end());

		bool sub = false;
		for (int i = 0;i < v.size() - 1;i++) {
			if (v[i] == v[i + 1].substr(0, v[i].length())) sub = true;
			if (sub) break;
		}

		if (sub) cout << "NO\n";
		else cout << "YES\n";
	}
}
