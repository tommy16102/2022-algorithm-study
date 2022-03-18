/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
13458 시험감독
2022/03/18 이호준
# 아이디어
1. 나눗셈을 이용하여 문제 풀이
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, b, c;

	cin >> n;

	vector<int> candidates(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> candidates[i];
	}
	
	cin >> b >> c;

	long long answer = 0;
	for (int i = 0; i < n; i++) {
		int current = candidates[i];
		current-= b;
		if (current > 0) {
			answer += (current / c);
			current % c != 0 ? answer += 1 : NULL;
		}
		answer += 1;
	}
	cout << answer;

	return 0;
}