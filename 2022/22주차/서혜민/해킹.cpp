#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {

		for (int i = 0; i <= 10000; i++) dist[i] = 987654321;
		vector<pair<int, int>> v[10001];

		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a, s });
		}

		
		dist[c] = 0;

		pq.push({ 0, c });
		while (!pq.empty()) {
			int now = pq.top().second;
			int val = pq.top().first;
			pq.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i].first;
				int nextVal = v[now][i].second;
				if (dist[next] > val + nextVal) {
					dist[next] = val + nextVal;
					pq.push({ dist[next], next });
				}
			}
		}

		int ans = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 987654321) {
				cnt++;
				ans = max(ans, dist[i]);
			}
		}

		cout << cnt << ' ' << ans << endl;
	}
}
