/*******************************************************************
Algorithm Study
Baekjoon OJ Priority queue
1715 카드 정렬하기
2022/02/22 이호준
# 아이디어
1. priority queue를 이용해서 가장 작은 것들 부터 합치도록 구현.
함정 몇번의 비교가 필요한지를 구하는 것인데 이때 1개일 경우 비교가 필요없으므로 0번의 비교가 필요하다.
*******************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	priority_queue<int, vector<int>, greater<>> q;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		q.push(number);
	}

	long long answer = 0;
	long long current = 0;

	if (q.size() == 1) {
		answer = 0;
		q.pop();
	}

	while (!q.empty()) {

		if (!current) {
			current = q.top();
		}
		else {
			current += q.top();
			//cout << current << " " << q.top() << endl;
			answer += current;
			q.push(current);
			current = 0;
		}
		q.pop();
	}

	cout << answer;

	return 0;
}

/*

	30 30 30 10 20
	10 20 
*/