#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> s;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}
}

void solve() {
	sort(s.begin(), s.end()); // 사전순 정렬
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // 전수조사
			string ls = s[i]; string rs = s[j];
			if (rs.substr(0, ls.size()) == ls) { // 접두사인 단어 발견 시
				s[i] = "NULL"; // 해당 단어를 "NULL"로 교체 -> 조건상 영어소문자만 들어오므로 겹칠일 없음
			}
		}
	}
	int answer = n; // 정답은 단어 개수에서
	for (int i = 0; i < n; i++) {
		if (s[i] == "NULL") // 접두사인 단어 개수를 제외한 값
			answer--;
	}
	cout << answer;
}

int main(void) {
	input();
	solve();
}