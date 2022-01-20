#include <bits/stdc++.h>
using namespace std;

string s;
vector<pair<int,bool>> st;

void input() {
	cin >> s;
}

void solve() {
	int n = 0;

	for (int i = 0; i < s.size(); i++) {
		if (i <= s.size() - 1 && s[i] == '(' && s[i + 1] == ')') {
			// 레이저
			for (int j = 0; j < st.size(); j++) {
				if (st[j].second == false) { // 처음 잘릴때만 구별
					st[j].second = true;
					n += 1;
				}
				n += 1; // 나머지 조각
			}
			i += 1; // i+=2로 건너뜀
		}
		else if (s[i] == '(') {
			st.push_back({ 1, false });
		}
		else if (s[i] == ')') {
			st.pop_back();
		}
	}

	cout << n;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

}