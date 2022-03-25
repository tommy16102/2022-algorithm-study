#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int dist[1001];
int ans[1001];
int N, M, X;
const int MAX = 1000 * 10000 + 1;
int answer = 0;

void dijkstra(int n) {
	for (int i = 1;i <= N;i++) dist[i] = MAX;
	pq.push({ 0,n });
	dist[n] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();

		for (int i = 0;i < v[now].size();i++) {
			int next = v[now][i].first;
			int plusVal = v[now][i].second + val;
			if (plusVal < dist[next]) {
				pq.push({ plusVal, next });
				dist[next] = plusVal;
			}
		}
	}

	if (n == X) {
		for (int i = 1;i <= N;i++) {
			ans[i] = dist[i];
		}
	}
	else {
		answer = max(answer, ans[n] + dist[X]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	while (M--) {
		int A, B, T;
		cin >> A >> B >> T;
		v[A].push_back({ B,T });
	}

	memset(dist, MAX, sizeof(dist));
	dijkstra(X);
	
	for (int i = 1;i <= N;i++) {
		if (i == X) continue;
		memset(dist, MAX, sizeof(dist));
		dijkstra(i);
	}

	cout << answer;
}