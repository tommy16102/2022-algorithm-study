#include <bits/stdc++.h>
using namespace std;

int n;
int m;
vector < pair<int, int>> v[1001];
int start; int goal;
int d[1001];
int parent[1001];
const int INF = 1000000000;
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost,to });
	}
	cin >> start >> goal;
}

void dij(int start) {

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// pq의 거리 > 현재 d보다 크면 무시
		if (cur_cost > d[cur]) continue;
		// 없으면 시간초과

		for (int i = 0; i < v[cur].size(); i++) {
			int next_cost = v[cur][i].first;
			int next = v[cur][i].second;
			if (d[next] > cur_cost + next_cost) {
				parent[next] = cur; // 경로 추적용
				d[next] = cur_cost + next_cost;
				pq.push({ d[next], next });
			}
		}
	}
}


void solve() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	dij(start);
	cout << d[goal] << '\n';
	int t = goal;
	vector<int> r;
	while (t) {
		r.push_back(t);
		t = parent[t];
	}
	cout << r.size() << '\n';
	reverse(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " ";
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}