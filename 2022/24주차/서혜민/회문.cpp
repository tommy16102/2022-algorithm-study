#include <iostream>
#include <string>
using namespace std;

int ans;

int check(string s, int l, int r, bool res) {
	while (l < r) {
		if (s[l] != s[r]) {
			if (res) {
				if (check(s, l + 1, r, false) == 0 || check(s, l, r - 1, false) == 0) return 1;
			}
			return 2;
		}
		l++;
		r--;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		cout << check(s, 0, s.length()-1, true) << '\n';
	}
}
