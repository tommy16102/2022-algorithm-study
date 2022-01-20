#include <bits/stdc++.h>
using namespace std;

int n; int m;
vector<int> connected[500000];
bool visited[500000];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from;
		int to;
		cin >> from >> to;
		connected[from].push_back(to);
		connected[to].push_back(from);
	}

}

void solve() {

	int ans = 0;
	for (int i = 1; i <= n; i++) { // 정점 개수만큼
		queue<int> q; // 다음에 방문할 목록
		if (!visited[i]) { // 방문 안했으면
			ans++;
			q.push(i); // 해당 노드로부터 시작
			visited[i] = true;
			while (!q.empty()) {
				int now = q.front(); // 현재 노드
				q.pop();
				for (int j = 0; j < connected[now].size(); j++) { // 현재 노드에서 이어진 길들만큼 bfs
					if (!visited[connected[now][j]]) { // 안 간길은 방문처리
						q.push(connected[now][j]);
						visited[connected[now][j]] = true;
					}
				}
			}
		}
	}

	cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}