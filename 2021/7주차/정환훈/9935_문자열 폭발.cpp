#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    푼 날짜 : 2021/08/19
    아이디어 : stack
*/

using namespace std;
string target;
string bomb;
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> target >> bomb;
}


void solve() {
	string answer = "";
	for (int i = 0; i < target.size(); i++) {
		answer += target[i]; // 주어진 문자열 그대로 집어넣다가

		if (answer.back() == bomb.back()) { // bomb 뒷글자 발견하면
			string temp = "";
			for (int j = answer.length() - bomb.size(); j < answer.length(); j++) { // bomb인지 검증
				temp += answer[j];
			}
			if (temp == bomb) { // bomb면
				for (int j = 0; j < bomb.size(); j++) {
					answer.pop_back(); // 그만큼 다 날려버리기
				}
			}
		}

	}
	if (answer.size() == 0) // 다 터져부림
		answer = "FRULA";
	cout << answer;

}

int main() {

	input();
	solve();

	return 0;
}