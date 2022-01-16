#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*

2022.01.16 서혜민

단순히 string의 insert 및 다른 함수를 사용해서 풀었을 땐 시간 초과 발생.
deque를 사용해서 커서의 좌측에 오는 문자들은 deqL, 우측의 문자들은 deqR에 넣었을 땐 시간 초과 X.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int M;
	cin >> M;

	deque<char> deqL, deqR;
	for (int i = 0;i < str.length();i++) deqL.push_back(str[i]);

	while (M--) {
		char op, ch;
		cin >> op;
		if (op == 'P') {
			cin >> ch;
			deqL.push_back(ch);
		}
		else if (op == 'L') {
			if (deqL.size() > 0) {
				deqR.push_front(deqL.back());
				deqL.pop_back();
			}
		}
		else if (op == 'D') {
			if (deqR.size() > 0) {
				deqL.push_back(deqR.front());
				deqR.pop_front();
			}
		}
		else {
			if (deqL.size() > 0) {
				deqL.pop_back();
			}
		}
	}
	
	string answer;
	while (!deqL.empty()) {
		answer += deqL.front();
		deqL.pop_front();
	}

	while (!deqR.empty()) {
		answer += deqR.front();
		deqR.pop_front();
	}

	cout << answer << '\n';
}
