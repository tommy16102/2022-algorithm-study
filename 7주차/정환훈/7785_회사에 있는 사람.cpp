#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/18
    아이디어 : 해쉬 맵 사용...  endl 쓰지말고 ...
*/

map<string, bool> people;
vector<string> names;
int n;
void input() {
	cin >> n;
}

void solve() {

		
	for (int i = 0; i < n; i++) {
		string who; // 누가
		string in; // 들어왔어? 나갔어?
		cin >> who >> in;

		if (people.count(who))  { // 이미 안에 들어와 있음
			if (in == "enter") { // 들어옴 <- 논리적으로 말이 되나?
				people[who] = true;
		
			}
			else { // 나감
				people[who] = false;
			}
			continue;
		}

		names.push_back(who); // 처음 들어오는 경우에만 이름 목록 추가
		people[who] = true;
	}

	sort(names.begin(), names.end(), greater<>());

	for (int i = 0; i < names.size(); i++) {
		if (people[names[i]] == true) {
			cout << names[i] << "\n";
		}
	}
}

int main() {
	input();
	solve();

	return 0;
}