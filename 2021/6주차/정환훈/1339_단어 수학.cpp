#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/12
    아이디어 : 그리디
*/

int n; 
vector<pair<int, char>> alphabet; // 숫자와 매핑되는 알파벳
vector<string> s;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		s.push_back(temp);
	}
	for (int i = 0; i < 26; i++) {
		alphabet.push_back(make_pair(0, 'A' + i));
	}
}


void solve() {

	for (int i = 0; i < n; i++) { // 알파벳에 각각의 값 부여
		for (int j = s[i].size() - 1; j >= 0; j--) {
			int c = s[i][j] - 'A'; // 끝에서부터 만난 알파벳 인덱스가 뭔지 알아내기
			alphabet[c].first += pow(10, s[i].size() - 1 - j); // 알파벳의 자리에 따른 보정
		}
	}

	sort(alphabet.begin(), alphabet.end(), greater<>()); // 가장 큰 수 가지는 알파벳부터 나열



	int k = 9;
	int id = 0;
	while (k >= 0) { // 이제 각 알파벳에 9부터 0까지 할당함 <int, char>
		alphabet[id].first = k;
		k--; id++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			for (int t = 0; t < 26; t++) {
				if (s[i][j] == alphabet[t].second) { // 알파벳을 숫자로 변환하는 과정
					s[i][j] = alphabet[t].first + '0';
					break;
				}
			}
		}
	}

	
	vector<int> transformed;
	for (int i = 0; i < n; i++) {
		string str = "";
		for (int j = 0; j < s[i].size(); j++) { // 각각의 알파벳 스트링들을 숫자로 변환
			str += s[i][j];
		}
		transformed.push_back(stoi(str)); // 해서 모으기
	}

	int res = 0;
	for (int i = 0; i < transformed.size(); i++) { // 모은 값들 다 더하기
		res += transformed[i];
	}

	cout << res;

}

int main() {

	input();
	solve();

	return 0;
}
