#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210831

int t;
string p;
int n;
string s;
bool rev = false;
deque<int> ary;
bool err = false;
int f_cursor = 0;
int b_cursor = 0;
int del = 0;

void print(deque<int> p) { // 출력

	if (err) { // 에러일 경우
		cout << "error\n";
		err = false;
		return;
	}

	if (rev) { // 뒤집어져 있으면 뒤에서부터 출력
		cout << "[";
		for (auto iter = p.rbegin() + b_cursor; iter < p.rend() - f_cursor; iter++) { // bcursor + fcursor 만큼 빼고 출력
				cout << *iter;
				if (iter != p.rend() - f_cursor - 1)
					cout << ",";
		}
		cout << "]\n";
	}
	else{ // 앞에서부터 출력
		cout << "[";
		for (auto iter = p.begin() + f_cursor; iter < p.end() - b_cursor; iter++) {
				cout << *iter;
				if (iter != p.end() - b_cursor - 1)
					cout << ",";
		}
		cout << "]\n";

	}
}

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
}

void R() { // 뒤집기 연산
	rev = !rev;
}

void D() { // 삭제 연산 => 각각의 상황에서 커서 옮기기

	if (del++ >= ary.size()) {
		err = true;
		del = 0;
	}

	else if (rev) {
		b_cursor++;
	}
	else {
		f_cursor++;
	}
}

vector<string> split(string s, string divid) { // 파싱을 위한 split 함수 ctrl cv
	vector<string> v;
	int start = 0;
	int d = s.find(divid);
	while (d != -1) {
		v.push_back(s.substr(start, d - start));
		start = d + 1;
		d = s.find(divid, start);
	}
	v.push_back(s.substr(start, d - start));

	return v;
}

void parse() { // 파싱

	if (s == "[]") // 예외처리
		return;
	string tp = s.substr(1, s.size() - 2);
	vector<string> sv = split(tp, ",");
	for (int i = 0; i < sv.size(); i++) {
		ary.push_back(stoi(sv[i]));
	}

}

void solve() {
	for (int i = 0; i < t; i++) {
		cin >> p >> n >> s;

		parse(); // 파싱
		del = 0; // 초기화 과정
		rev = false;
		f_cursor = 0;
		b_cursor = 0;

		for (int j = 0; j < p.size(); j++) { // [1,2,3,4]

			if (err) {
				err = false;
				break;
			}

			if (p[j] == 'R') {
				R();
			}
			else if (p[j] == 'D') {
				D();
				if (err)
					break;
			}
			else {
				err = true;
				break;
			}
		}

		print(ary);
		ary.clear();


	}

}

int main() {

	input();
	solve();

	return 0;
}