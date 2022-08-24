#include <bits/stdc++.h>
using namespace std;

int n; int e;
int v1; int v2;
vector<pair<int, int>> v[801];
int d[801];
const int INF = 100000000;
void input() {

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int from; int to; int cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost,to });
		v[to].push_back({ cost,from });
	}

	cin >> v1 >> v2;
}

void clear() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
}

void dijkstra(int start) {

	clear();

	// 최소 pq(비용, 인덱스) 선언
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 시작값 넣기
	d[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) { // 모든 v에 대하여

		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < v[now].size(); i++) { // 현재 노드와 연결된 정점들 전부 살펴보기
			int n_cost= v[now][i].first;
			int next = v[now][i].second;

			if (d[next] > cost + n_cost) {
				d[next] = cost + n_cost;
				pq.push({ d[next], next });
			}
		}

	}



}

void solve() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	// 1 -> v1 -> v2 -> n
	// 1 -> v2 -> v1 -> n
	dijkstra(1);
	int s_v1 = d[v1];
	int s_v2 = d[v2];
	dijkstra(v1);
	int v1_v2 = d[v2];
	int v2_v1 = d[v2];
	int v1_n = d[n];
	dijkstra(v2);
	int v2_n = d[n];

	if (s_v1 == INF && s_v2 == INF) { // s->v1, s->v2 둘다 없음
		cout << -1;
		return;
	}
	if (v1_v2 == INF) { // v1->v2 길 없음
		cout << -1;
		return;
	}
	if (v1_n == INF && v2_n == INF) { // v1->n, v2->n 둘다 없음
		cout << -1;
		return;
	}


	int r1 = s_v1 + v1_v2 + v2_n;
	int r2 = s_v2 + v2_v1 + v1_n;
	int ans = min(r1, r2);

	cout << ans;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}