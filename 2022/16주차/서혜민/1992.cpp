#include <iostream>
#include <string>
using namespace std;

char arr[65][65];

string calc(pair<int, int> l, int len) {
	int count1 = 0;
	int count0 = 0;
	for (int i = l.first; i < l.first + len; i++) {
		for (int j = l.second; j < l.second + len; j++) {
			if (arr[i][j] == '0') count0++;
			if (arr[i][j] == '1') count1++;
		}
	}

	string s = "";
	if (count1 == len * len) {
		s += "1";
	}
	else if (count0 == len * len) {
		s += "0";
	}
	else {
		len /= 2;
		s = "(";
		s += calc(l, len);
		s += calc({ l.first, l.second + len }, len);
		s += calc({l.first+len, l.second},len);
		s += calc({l.first+len, l.second+len},len);
		s += ")";
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	string answer = calc({ 0,0 }, N);
	cout << answer;
}
