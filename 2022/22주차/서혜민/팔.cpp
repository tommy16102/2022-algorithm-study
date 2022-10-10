#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int ans = 0;

	if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == s2[i]) {
				if (s1[i] == '8') ans++;
				else continue;
			}
			else break;
		}
	}
	cout << ans;
}
