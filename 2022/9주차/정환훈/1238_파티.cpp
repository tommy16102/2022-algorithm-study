#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int x;
int dist[1001][1001];
vector<pair<int, int>> v[1001];
const int INF = 1000000000;
void input() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
}

void dijkstra(int start) {
	// min heap형태의 priority_queue 선언
	// cost, next node 형태로 저장 -> first를 기준으로 정렬되기 때문에
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start][start] = 0;
	pq.push({ 0,start});
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[start][cur] < cost) 
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = cost + v[cur][i].second;
			if (next_cost < dist[start][next]) {
				dist[start][next] = next_cost;
				pq.push({ next_cost ,next });
			}
		}
	}
}

void solve() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dist[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	int m = 0;

	for (int i = 1; i <= n; i++) {
		if (m < dist[i][x] + dist[x][i])
			m = dist[i][x] + dist[x][i];;
	}

	cout << m;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}