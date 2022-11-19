#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
void input() {
	cin >> n;
	v = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}
void solve() {
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int median;
	vector<int> mid;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			median = v[i];
		}
		else {
			if (v[i] <= median) left.push(v[i]);
			else right.push(v[i]);
		}
		if (i % 2 == 0) {
			if (left.size() > right.size()) {
				right.push(median);
				median = left.top();
				left.pop();
			}
			else if (left.size() < right.size()) {
				left.push(median);
				median = right.top();
				right.pop();
			}
			mid.push_back(median);
		}
	}
	cout << n / 2 + 1 << '\n';
	for (int i = 0; i < mid.size(); i++) {
		cout << mid[i] << " ";
		if (i + 1 % 10 == 0) cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}
	return 0;
}
