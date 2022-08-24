#include <bits/stdc++.h>
using namespace std;

int n;
int l;
int sx; int sy;
int ex; int ey;
pair<int, int> start;
pair<int, int> goal;
int dx[8] = { -1,-2,-2,-1,+1,+2,+2,+1 };
int dy[8] = { +2,+1,-1,-2,-2,-1,+1,+2 };
bool visited[300][300];

void input() {
	cin >> l;
	cin >> sx >> sy;
	cin >> ex >> ey;
	start = { sx,sy };
	goal = { ex,ey };
	// 각 시도마다 visited 초기화
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			visited[i][j] = false;
		}
	}
}

void solve() {

	queue<pair<pair<int, int>, int>> q; // ( (x,y), tries )
	q.push({ start,0 }); // 시작 지점, 0회 시도

	while (!q.empty()) { // bfs
		pair<int, int> now = q.front().first;
		int tries = q.front().second;
		q.pop();

		if (now.first == goal.first && now.second == goal.second) { // goal 도착
			cout << tries << '\n';
			return;
		}

		for (int i = 0; i < 8; i++) { // 갈수있는 경로 파악
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx >= 0 && nx <= l - 1 && ny >= 0 && ny <= l - 1 && !visited[nx][ny]) {
				visited[nx][ny] = true; // 해당 지역 방문 처리 후 진행
				q.push({ { nx, ny }, tries + 1 });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		input();
		solve();
	}
}