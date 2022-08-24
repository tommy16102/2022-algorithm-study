#include <bits/stdc++.h>
using namespace std;

int n;

// 우선순위 큐
priority_queue<int, vector<int>, greater<int>> heap;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		heap.push(t);
	}
}

void solve() {
	int answer = 0;
	if (heap.size() == 1) {
		cout << 0;
		return;
	}

	while (heap.size() != 1) {
		int n1 = heap.top();
		heap.pop();
		int n2 = heap.top();
		heap.pop();
		answer += n1 + n2;
		int p = n1 + n2;
		heap.push(p);
	}

	cout << answer;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();

	return 0;
}	