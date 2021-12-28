#include <queue>
#include <iostream>
using namespace std;

/*

2021.08.23 내림차순의 우선순위 큐를 이용.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	int num;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(num);
	}
}
