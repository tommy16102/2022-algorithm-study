#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*

2021.09.03 

front와 back으로 접근 가능한 deque를 통해 bool형 변수인 front를 줘서
r을 나오면 !를 통해 이전의 값과 다른 값을 가지게 하며 
d가 나올 때 front가 1이면 앞에서부터 pop_front, front가 0이면 뒤에서부터 pop_back해나간다.

*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	
	while (T--) {
		string p;
		cin >> p;
		
		int n;
		cin >> n;

		string arr;
		cin >> arr;

		deque<int> deque;

		arr = arr.substr(1, arr.length() - 2);
		if (arr != "") {
			int startIndex = 0;
			while (1) {
				int findIndex = arr.find(',', startIndex);
				if (findIndex == -1) {
					deque.push_back(stoi(arr.substr(startIndex)));
					break;
				}
				int count = findIndex - startIndex;
				deque.push_back(stoi(arr.substr(startIndex, count)));
				startIndex = findIndex + 1;
			}
		}

		bool front = true;
		bool error = false;

		for (int i = 0;i < p.length();i++) {
			if (p[i] == 'R') {
				front = !front;
			}
			else {
				if (deque.empty()) {
					cout << "error" << '\n';
					error = true;
					break;
				}
				else if (front) {
					deque.pop_front();
				}
				else {
					deque.pop_back();
				}
			}
		}
		if (!error) {
			if (deque.empty()) cout << "[]" << '\n';
			else {
				string answer = "[";
				if (front) {
					while (!deque.empty()) {
						answer += to_string(deque.front());
						deque.pop_front();
						answer += ",";
					}
				}
				else {
					while (!deque.empty()) {
						answer += to_string(deque.back());
						deque.pop_back();
						answer += ",";
					}
				}

				answer[answer.length() - 1] = ']';
				cout << answer << '\n';
			}
		}
		
	}
}
