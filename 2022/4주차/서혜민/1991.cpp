#include <iostream>
#include <vector>
using namespace std;

/*

2022.1.30

함수 내 함수를 실행하는 순서를 바꿔서 구현.

*/

vector<pair<char, char>> v[26];

void front(char c) {
	char left = v[c - 'A'][0].first;
	char right = v[c - 'A'][0].second;
	cout << c;
	if (left != '.') front(left);
	if (right != '.') front(right);
}

void mid(char c) {
	char left = v[c - 'A'][0].first;
	char right = v[c - 'A'][0].second;
	if (left != '.') mid(left);
	cout << c;
	if (right != '.') mid(right);
}

void back(char c) {
	char left = v[c - 'A'][0].first;
	char right = v[c - 'A'][0].second;
	if (left != '.') back(left);
	if (right != '.') back(right);
	cout << c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;	
	while (N--) {
		char a, b, c;
		cin >> a >> b >> c;
		v[a - 'A'].push_back({ b,c });
	}
	front('A');
	cout << '\n';
	mid('A');
	cout << '\n';
	back('A');
}
