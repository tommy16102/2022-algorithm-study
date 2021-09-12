#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

/*
    푼 날짜 : 2021/08/18
    아이디어 : pq
*/

priority_queue<int, vector<int>, greater<int>> pq;
int n;

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
}

void print_max() {
	if (pq.empty()) {
		cout << 0 << "\n";
	}
	else {
		cout << pq.top() << "\n";
		pq.pop();
	}
}

void add(int x) {
	pq.push(x);
}

void solve() {

	for (int i = 0; i < n; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			print_max();
		}
		else {
			add(cmd);
		}
	}
}

int main() {
	input();
	solve();

	return 0;
}