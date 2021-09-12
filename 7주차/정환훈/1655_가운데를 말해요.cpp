#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    푼 날짜 : 2021/08/21
    아이디어 : 최대, 최소 힙을 활용
*/

int n;
priority_queue<int> max_heap; // 최대힙
priority_queue<int, vector<int>, greater<int>> min_heap; // 최소힙

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
}

void solve() {

	/*
		1. 최소 힙의 값들은 모두 최대 힙보다 크도록하고

		2. 최대 힙의 크기가 최소 힙의 크기보다 1 크거나 같도록 유지하며 값을 넣는다.

		3. 값을 넣어준 후 최대 힙과 최소 힙의 top 값을 비교해서 최소 힙의 top보다 최대 힙의 top이 더 크다면 값을 교환해준다.

		그러면 최대 힙의 top값이 중간값이 된다.
	*/


	int first;
	cin >> first;
	cout << first << '\n';
	max_heap.push(first); // 초기값은 max_heap 에 집어넣는다

	for (int i = 0; i < n - 1; i++) {
		int value;
		cin >> value;

		if (max_heap.size() > min_heap.size()) { // 2. 최대 힙의 크기가 최소 힙의 크기보다 1 크거나 같도록 유지하며 값을 넣는다.
			min_heap.push(value);
		}
		else {
			max_heap.push(value);
		}

		if (max_heap.top() > min_heap.top()) { // 1. 최소 힙의 값들은 모두 최대 힙보다 크도록하고
											  // 3. 값을 넣어준 후 최대 힙과 최소 힙의 top 값을 비교해서 최소 힙의 top보다 최대 힙의 top이 더 크다면 값을 교환해준다.
			int max_top = max_heap.top();
			int min_top = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			min_heap.push(max_top);
			max_heap.push(min_top);
		}


		cout << max_heap.top() << '\n';
	}
}

int main() {

	input();
	solve();

	return 0;
}