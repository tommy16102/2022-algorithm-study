#include <bits/stdc++.h>
using namespace std;
int r;
int c;
char m[51][51];
bool v[51][51];
pair<int, int> goal;
pair<int, int> start;
queue<pair<int, int>>waters;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'D') { // 도착지
				goal = { i,j };
			}
			if (m[i][j] == '*') { // 물
				waters.push({ i,j });
			}
			if (m[i][j] == 'S') { // 시작지
				start = { i,j };
				v[i][j] = true;
			}
		}
	}
}

void solve() {
	queue<pair<int, int>> moves;
	moves.push(start);
	int tries = 0;
	while (!moves.empty()) { // 움직일 수 있는 경로 없을때까지
		int ws = waters.size(); // 새롭게 생긴 물들만큼
		for (int i = 0; i < ws; i++) { // bfs
			pair<int, int> wnow = waters.front();
			waters.pop();
			int x = wnow.first;
			int y = wnow.second;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					if (m[nx][ny] == '.' || m[nx][ny] == 'S') {
						m[nx][ny] = '*';
						waters.push({ nx,ny });
					}
				}
			}
		}

		int s = moves.size(); // 새롭게 생긴 움직임만큼
		tries++;
		for (int i = 0; i < s; i++) { // bfs
			pair<int, int> now = moves.front();
			moves.pop();
			int x = now.first;
			int y = now.second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					if (m[nx][ny] == 'D') { // 도착
						cout << tries;
						return;
					}
					if (m[nx][ny] == '.' && !v[nx][ny]) { // 중복방문 방지
						v[nx][ny] = true;
						moves.push({ nx,ny });
					}
				}
			}
		}
	}

	cout << "KAKTUS";

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}