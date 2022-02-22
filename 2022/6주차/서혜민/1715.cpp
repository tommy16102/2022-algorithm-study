#include <iostream>
#include <queue>
using namespace std;

/*

2.22

작은 수부터 하나씩 꺼내서 합쳐서 다시 우선순위 큐에 넣는다.
이때, 묶음카드가 하나만 있으면, 비교할 필요가 없으니 0.

*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	
	if (pq.size() == 1) {
		cout << 0;
		return 0;
	}

	int cnt = 0, part = 0, sum = 0;

	while (1) {
		if (cnt < 2) {
			part += pq.top();
			sum += pq.top();
			pq.pop();
			cnt++;
			if (pq.empty()) {
				cout << sum;
				return 0;
			}
			if (cnt == 2) {
				pq.push(part);
				cnt = part = 0;
			}
		}
	}
}
