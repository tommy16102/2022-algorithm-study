#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <limits.h>
#define MAX INT_MAX
using namespace std;

long long dist[501];
vector<pair<int, int>> v[501];

int main() {
	int N, M;
	cin >> N >> M;

	while (M--) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}

	for (int i = 1;i <= N;i++) dist[i] = MAX;
	dist[1] = 0;
	bool cycle = false;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (dist[j] == MAX) continue;

			for (int k = 0;k < v[j].size();k++) {
				int next = v[j][k].first;
				long long nextVal = v[j][k].second + dist[j];
				if (dist[next] > nextVal) {
					dist[next] = nextVal;
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2;i <= N;i++) {
			long long cnt = dist[i];
			if (cnt == MAX) cnt = -1;
			cout << cnt << '\n';
		}
	}
}
