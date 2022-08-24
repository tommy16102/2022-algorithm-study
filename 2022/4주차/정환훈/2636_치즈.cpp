#include <bits/stdc++.h>
using namespace std;
int r;
int c;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int m[101][101];
bool air[101][101];
bool v[101][101];
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			v[i][j] = false;
			air[i][j] = false;
		}
	}
}


void solve() {
	int count = 0;
	int t = 0;
	int last = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] == 1) // 초기 치즈 개수 세기
				count++;
		}
	}

	while (count > 0) { // 치즈 존재하면
		t++;
		queue<pair<int, int>> q; // 00에서 시작하는 큐
		q.push({ 0,0 });
		v[0][0] = true;
		air[0][0] = true;

		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			int y = now.first;
			int x = now.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx >= 0 && nx < c && ny >= 0 && ny < r && !v[ny][nx] && m[ny][nx] == 0) { // 공기인 애들 계속 bfs로 탐색으로 확인
					air[ny][nx] = true;
					v[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}

		vector<pair<int, int>> p;
		int remove = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				v[i][j] = false; // v 재사용
				if (m[i][j] == 1) { // 치즈인 칸에서
					for (int k = 0; k < 4; k++) { // 상하좌우 확인
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (nx >= 0 && nx < c && ny >= 0 && ny < r && air[ny][nx]) { // 상하좌우에 공기가 차있으면
							p.push_back({ i,j }); // 해당 블럭 확인 후 다음 블럭 확인
							break;
						}
					}
				}
			}
		}
		remove = p.size();
		for (int r = 0; r < remove; r++) { // 치즈 제거
			int y = p[r].first;
			int x = p[r].second;
			air[y][x] = true;
			m[y][x] = 0;
		}

		if (count - remove == 0) {
			last = remove;
		}
		count -= remove;

	}

	cout << t << '\n' << last;

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	
	return 0;
}