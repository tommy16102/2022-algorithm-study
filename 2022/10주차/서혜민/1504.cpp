#include <iostream>
#include <vector>
#include <queue>
#define MAX 800 * 200000 + 1
using namespace std;

vector<pair<int, int>> v[801];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[801];

void clear() {
	for (int i = 0;i < 801;i++) dist[i] = MAX;
}

void find(int n) {
	pq.push({ 0, n });
	dist[n] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		for (int i = 0;i < v[now].size();i++) {
			int next = v[now][i].first;
			int nextVal = v[now][i].second;
			if (dist[next] > val + nextVal) {
				dist[next] = val + nextVal;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, E;
	cin >> N >> E;

	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	for (int i = 0;i < 801;i++) {
		dist[i] = MAX;
	}

	int oneToV1, oneToV2;
	find(1);
	oneToV1 = dist[v1];
	oneToV2 = dist[v2];

	clear();

	int v1Tov2, v1ToN;
	find(v1);
	v1Tov2 = dist[v2];
	v1ToN = dist[N];

	clear();

	int v2ToV1, v2ToN;
	find(v2);
	v2ToV1 = dist[v1];
	v2ToN = dist[N];

	int r1 = oneToV1 + v1Tov2 + v2ToN;
	int r2 = oneToV2 + v2ToV1 + v1ToN;

	int ans = min(r1, r2);
	if (ans >= MAX) cout << -1 << endl;
	else cout << ans << endl;
}
