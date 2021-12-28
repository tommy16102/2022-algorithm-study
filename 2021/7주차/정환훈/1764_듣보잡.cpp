#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/18
    아이디어 : 해쉬 맵으로
*/

map<string, int> intersection; // 해당 이름이 몇개의 집합에 속해있는지
vector<string> names;
vector<string> answers;
int n1; int n2;
void input() {

	cin >> n1 >> n2;

	for (int i = 0; i < n1; i++) { // 집합 p1
		string name;
		cin >> name;
		intersection[name]++; // p1에 속함
		names.push_back(name);
	}

	for (int i = 0; i < n2; i++) {
		string name;
		cin >> name;
		if (intersection[name] == 0) { // p1에 속해 있으면 이름 추가 ㄴ
			names.push_back(name);
		}
		intersection[name]++; // p2에 속함
	}
}

void solve() {

	for (int i = 0; i < names.size(); i++) {

		if (intersection[names[i]] == 2) { // 2개 집합 속함
			answers.push_back(names[i]);
		}
	}

	sort(answers.begin(), answers.end());
	cout << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << endl;
	}

}

int main() {
	input();
	solve();

	return 0;
}