#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;

int lcs[1001][1001];

void input() {
	cin >> s1 >> s2;
}

void solve() {


	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
			}
			else if (s1[i - 1] == s2[j - 1]) { // 동일한 문자열 발견
				lcs[i][j] = lcs[i - 1][j - 1] + 1; // 이전 문자열 dp값 + 1
			}
			else { // 다른 문자열
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]); // 좌나 위에서 큰값 선택
			}
		}
	}

	cout << lcs[s1.size()][s2.size()] << '\n';
	int a = s1.size();
	int b = s2.size();
	string s = "";;
	while (lcs[a][b] != 0) { // 0 만날때까지 돌아감
		if (lcs[a][b] == lcs[a][b - 1]) { // 좌로가도 같음
			b -= 1;
		}
		else if (lcs[a][b] == lcs[a - 1][b]) { // 위로가도 같음
			a -= 1;
		}
		else { // 대각선으로 가야함
			s += s1[a - 1]; // lcs 역추적
			a -= 1; b -= 1;
		}
	}
	reverse(s.begin(), s.end()); // reverse
	cout << s;

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}