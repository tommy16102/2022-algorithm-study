#include <iostream>
#include <queue>
using namespace std;

/*

2021.08.23 우선순위 큐를 이용.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	priority_queue<int> pq;
	int num;
	cin >> N;
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
