#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

/*

2021.09.06

다익스트라 알고리즘을 통한 정점의 최소 길이 찾기.

*/
const int MAX = 20001;

int minCourse[MAX];
vector<pair<int, int>> vv[MAX];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, e;
	cin >> V >> e;

	int k;
	cin >> k;
	
	for (int i = 1;i <= V;i++) minCourse[i] = INT_MAX;
	minCourse[k] = 0;

	int u, v, w;
	while (e--) {
		cin >> u >> v >> w;
		vv[u].push_back({ v ,w });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,k });

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (minCourse[current] < distance) continue;
		
		for (int i = 0;i < vv[current].size();i++) {
			int next = vv[current][i].first;
			int nextDistance = distance + vv[current][i].second;
			if (minCourse[next] > nextDistance) {
				minCourse[next] = nextDistance;
				pq.push({ -nextDistance,next });
			}
		}
	}

	for (int i = 1;i <= V;i++) {
		if (minCourse[i] == INT_MAX) cout << "INF\n";
		else cout << minCourse[i] << '\n';
	}
}
