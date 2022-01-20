#include <bits/stdc++.h>
using namespace std;

string str;
int n;
void input() {
	cin >> str;
	cin >> n;
}



void solve() {
	// 커서를 기준으로 왼쪽 stack, 오른쪽 stack을 선언한다.
	stack<char> left;
	stack<char> right;

	for (int i = 0; i < str.size(); i++) {
		left.push(str[i]);
	}

	// abcd
	for (int i = 0; i < n; i++) {
		char cmd;
		char c;
		cin >> cmd;
		if (cmd == 'L') { // 좌 이동
			if (!left.empty()) {
				char l = left.top();
				left.pop();
				right.push(l);
			}
		}
		else if (cmd == 'D') { // 우 이동
			if (!right.empty()) {
				char r = right.top();
				right.pop();
				left.push(r);
			}
		}
		else if (cmd == 'B') { // 삭제
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (cmd == 'P') { // 추가
			cin >> c;
			left.push(c);
		}
	}

	string lstr = "";
	string rstr = "";
	while (!left.empty()) {
		lstr += left.top();
		left.pop();
	}
	reverse(lstr.begin(), lstr.end()); // left str만 반대로 뒤집어준다

	while (!right.empty()) {
		rstr += right.top();
		right.pop();
	}

	cout << lstr + rstr;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}