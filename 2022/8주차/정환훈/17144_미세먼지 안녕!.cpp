#include <bits/stdc++.h>
using namespace std;

int r;
int c;
int t;

pair<int, int> ac = { 0,0 };
int board[100][100];
int save[100][100];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void input() {
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				if (ac.first == 0) {
					ac.first = i;
				}
				else {
					ac.second = i;
				}
			}
		}
	}
}
void print() {

	cout << "==============================\n";

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << "==============================\n";
}

void solve() {
	/*
	미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
	(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
	인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
	확산되는 양은 Ar,c/5이고 소수점은 버린다.
	(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.

	공기청정기가 작동한다.
	공기청정기에서는 바람이 나온다.
	위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
	바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
	공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

	*/



	for (int time = 0; time < t; time++) {



		// 확산
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				save[i][j] = board[i][j];
			}
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (save[i][j] != 0 && save[i][j] != -1) {
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny >= 1 && ny <= r && nx >= 1 && nx <= c && board[ny][nx] != -1) {
							board[ny][nx] += save[i][j] / 5;
							board[i][j] -= save[i][j] / 5;
						}
					}
				}
			}
		}

		//cout << "====================확산끝\n";

		// 공기청정기 작동
		int first = ac.first;
		int sec = ac.second;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				save[i][j] = board[i][j];
			}
		}
		board[first][2] = 0;
		for (int i = 2; i <= c - 1; i++) {
			board[first][i + 1] = save[first][i];
		}
		for (int i = first - 1; i >= 1; i--) {
			board[i][c] = save[i + 1][c];
		}
		for (int i = c - 1; i >= 1; i--) {
			board[1][i] = save[1][i + 1];
		}
		for (int i = 1; i < first - 1; i++) {
			board[i + 1][1] = save[i][1];
		}


		board[sec][2] = 0;
		for (int i = 2; i <= c - 1; i++) {
			board[sec][i + 1] = save[sec][i];
		}
		for (int i = sec + 1; i <= r; i++) {
			board[i][c] = save[i - 1][c];
		}
		for (int i = c - 1; i >= 1; i--) {
			board[r][i] = save[r][i + 1];
		}
		for (int i = r - 1; i >= sec + 1; i--) {
			board[i][1] = save[i + 1][1];
		}
		//cout << "====================공기청정기끝\n";
	}


	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] != -1)
				ans += board[i][j];
		}
	}

	cout << ans;

}


void test() {


	// 공기청정기 작동
	int first = ac.first;
	int sec = ac.second;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			save[i][j] = board[i][j];
		}
	}
	board[first][2] = 0;
	for (int i = 2; i <= c - 1; i++) {
		board[first][i + 1] = save[first][i];
	}
	for (int i = first - 1; i >= 1; i--) {
		board[i][c] = save[i + 1][c];
	}
	for (int i = c - 1; i >= 1; i--) {
		board[1][i] = save[1][i + 1];
	}
	for (int i = 1; i < first - 1; i++) {
		board[i + 1][1] = save[i][1];
	}


	board[sec][2] = 0;
	for (int i = 2; i <= c - 1; i++) {
		board[sec][i + 1] = save[sec][i];
	}
	for (int i = sec + 1; i <= r; i++) {
		board[i][c] = save[i - 1][c];
	}
	for (int i = c - 1; i >= 1; i--) {
		board[r][i] = save[r][i + 1];
	}
	for (int i = r - 1; i >= sec + 1; i--) {
		board[i][1] = save[i + 1][1];
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