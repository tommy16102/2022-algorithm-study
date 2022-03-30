#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	deque<pair<int, int>> dq(N);

	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		dq[i] = { a, b };
	}

	int now = 0, cnt = 0;

	sort(dq.begin(), dq.end(), comp);

	while (!dq.empty()) {
		if (now <= dq.front().first) {
			now = dq.front().second;
			cnt++;
		}
		dq.pop_front();
	}

	cout << cnt;
}