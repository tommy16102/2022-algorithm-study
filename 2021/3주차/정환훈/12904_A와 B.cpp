#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈
    푼 날짜 : 2021/07/23

    기본 아이디어 : S와 T를 받은 다음 vector<char>화 시킴
    그런다음 뒷글자가 A로 끝나는 경우와 B로 끝나는 경우 나눠서
    뒤에서부터 T->S가 만들어지는지 확인.
*/

int main() {

	string S;
	string T;

	vector<char> start;
	vector<char> end;

	cin >> S >> T;
	int flag = 0;

	for (int i = 0; i < S.size(); i++) {
		start.push_back(S[i]);
	}
	for (int i = 0; i < T.size(); i++) {
		end.push_back(T[i]);
	}



	while (true) {

		if (start.size() == end.size()) {

			for (int i = 0; i < start.size(); i++) {
				if (start[i] != end[i]) {
					flag = 1;
				}
			}
			if (flag == 0) {
				cout << 1;
			}
			else {
				cout << 0;
			}

			return 0;
		}

		char last_char = end.back();
		switch (last_char) {

		case 'A':
			end.pop_back();
			//cout << "case A" << endl;
			//for (int i = 0; i < start.size(); i++) {
			//	cout << end[i];
			//}
			//cout << endl;
			break;

		case 'B':
			end.pop_back();
			reverse(end.begin(), end.end());
			//cout << "case B" << endl;
			//for (int i = 0; i < start.size(); i++) {
			//	cout << end[i];
			//}
			//cout << endl;
			break;

		default:
			cout << 0;
			return 0;

		}
	}


	return 0;
}