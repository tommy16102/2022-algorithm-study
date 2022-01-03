#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

/*

1753과 같은 다익스트라 알고리즘을 통한 from에서 to까지의 최단거리 찾기.

*/

int minCourse[1001];
vector<pair<int, int>> v[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int from, to, cost;
	while (M--) {
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	cin >> from >> to;

	fill_n(minCourse, 1001, INT_MAX);
	minCourse[from] = 0;

	queue<pair<int, int>> queue;
	queue.push({ 0,from });

	while (!queue.empty()) {
		int cost = -queue.front().first;
		int now = queue.front().second;
		queue.pop();
		if (cost > minCourse[now]) continue;

		for (int i = 0;i < v[now].size();i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;

			if (minCourse[next] > cost + nextCost) {
				minCourse[next] = cost + nextCost;
				queue.push({ -minCourse[next],next });
			}
		}
	}
	cout << minCourse[to] << endl;
}
