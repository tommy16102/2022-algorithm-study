#include <bits/stdc++.h>
using namespace std;

// (-1,-1) (0,-1) (1,0) (0,1) (-1,1) (-1,0)
// (0,-1) (1,-1) (1,0) (1,1) (0,1) (-1,0)

pair<int, int> even[6] = { {-1,-1}, {0,-1}, {1,0}, {0,1}, {-1,1}, {-1,0} };
pair<int, int> odd[6] = { {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,0} };

int w; int h;
int ans = 0;
int board[102][102];
bool v[102][102];
void input() {
	cin >> w >> h;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			board[i][j] = -1;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> board[j][i];
		}
	}
	
}

void bfs(int i, int j) { // 0,0부터 시작해서 만질 수 있는 벽들 개수 세기
	v[i][j] = true;
	queue<pair<int, int>> q;
	int walls = 0;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		if (y % 2 == 0) {
			for (int k = 0; k < 6; k++) {
				int ny = y + even[k].second;
				int nx = x + even[k].first;
				if (nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1) {
					if (board[nx][ny] == -1 && !v[nx][ny]) {
						v[nx][ny] = true;
						q.push({ nx,ny });
					}
					if (board[nx][ny] == 1)
						walls++;
					if (board[nx][ny] == 0 && !v[nx][ny]) {
						v[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		else {
			for (int k = 0; k < 6; k++) {
				int ny = y + odd[k].second;
				int nx = x + odd[k].first;
				if (nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1) {
					if (board[nx][ny] == -1 && !v[nx][ny]) {
						v[nx][ny] = true;
						q.push({ nx,ny });
					}
					if (board[nx][ny] == 1)
						walls++;
					if (board[nx][ny] == 0 && !v[nx][ny]) {
						v[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	ans += walls;
	
}

void solve() {
	bfs(0, 0);
	cout << ans;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}