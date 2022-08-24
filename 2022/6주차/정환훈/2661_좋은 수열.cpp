#include <bits/stdc++.h>
using namespace std;
int n;

void input() {
	cin >> n;
}

bool isgood(string s) { // 좋은수열인지 판단
	for (int i = 0; i < s.size(); i++) { // 앞 문자열 시작 인덱스
		for (int j = 1; j + i <= s.size(); j++) { // 길이 : j글자
			string sub = s.substr(i, j);
			string sub2 = s.substr(i + j, j);
			if (sub == sub2)
				return false;
		}
	}
	return true;
}

bool flag = false;

void recursive(string s) {

	if (flag) // 최솟값 찾음
		return;

	if (!isgood(s)) // 이미 틀림
		return;

	if (s.size() >= n) { // 발견
		cout << s << endl;
		flag = true;
		return;
	}
	recursive(s + "1");
	recursive(s + "2");
	recursive(s + "3");
}

void solve() {
	recursive("1");
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}