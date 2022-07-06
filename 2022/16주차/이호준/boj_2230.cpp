/*******************************************************************
Algorithm Study
Baekjoon OJ 투포인터
2230 수고르기
2022/07/05 이호준
# 아이디어
1. 투포인터 기본알고리즘 사용
2. 투포인터알고리즘으로 풀어야한다는 것을 이해하면 됨.
*******************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2100000000
using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> list(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	int left = 0, right = 0;
	int current_value = INF;
	while (left < n) {
		int check = list[right] - list[left];
		if (check >= m) {
			if (current_value > check) {
				current_value = check;
			}
			// right 이동시 check 가 더 커짐.
			left++;
		}
		else {
			right++;
			if (right == n) {
				right = n - 1;
				left++;
			}
		}
	}

	cout << current_value;

	return 0;
}