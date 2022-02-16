/*******************************************************************
Algorithm Study
Baekjoon OJ BF
1107 리모콘
2022/02/15 이호준
# 아이디어
1. 최적의 상태를 찾으려는데 그것이 너무 어려웠다.
그래서 BruteForce로 0부터 찾아갔더니 통과.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool out[10];


bool check(int now) {

	string s = to_string(now);
	for (int i = 0; i < s.length(); i++) {
		if (out[s[i] - 48]) {
			return false;
		}

	}

	return true;

}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int target, num;
	
	cin >> target >> num;

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		out[temp] = true;
	}

	string st = to_string(target);

	int minimum = abs(target - 100);
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = abs(target - i) + to_string(i).length();
			minimum = min(minimum, tmp);
		}

	}

	cout << minimum << endl;

	return 0;
}

