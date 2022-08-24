#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int dist[101][101];
const int INF = 1000000000;

void input() {
	cin >> n >> m;
}


void solve() {

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int from; int to; int t;
		cin >> from >> to >> t;
		dist[from][to] = min(dist[from][to], t);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << '\n';
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