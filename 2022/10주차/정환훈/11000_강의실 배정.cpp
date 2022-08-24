#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s; int t;
		cin >> s >> t;
		v.push_back({ s,t });
	}
}

void solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}
	cout << pq.size();
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}