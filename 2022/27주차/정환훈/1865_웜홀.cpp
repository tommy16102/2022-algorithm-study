#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, w;
const int INF = 987654321;
int d[10101];
vector<pair<int,int>> graphs[505];
void input() {
	cin >> n >> m >> w;
	for (int i = 0; i < 10101; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < 505; i++) {
		graphs[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graphs[s].push_back({ e, t });
		graphs[e].push_back({ s, t });
	}
	for (int i = 0; i < w; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graphs[s].push_back({ e, -t });
	}
}

void solve() {
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < graphs[j].size(); k++) {
				int next = graphs[j][k].first;
				int cost = graphs[j][k].second;
				if (/*d[next] != INF && */d[next] > d[j] + cost) {
					d[next] = d[j] + cost;
					if (i == n) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
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
