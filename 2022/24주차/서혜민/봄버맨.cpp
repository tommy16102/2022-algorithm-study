#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string board[201];
queue<pair<int, int>> q;
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };
int R, C, N;

int main() {

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) cin >> board[i];

	if (N % 2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << 'O';
			}
			cout << endl;
		}
	}
	else {
		int cnt = 1;
		while (cnt < N) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (board[i][j] == 'O') q.push({ i, j });
					board[i][j] = '0';
				}
			}
			while (!q.empty()) {
				int nowI = q.front().first;
				int nowJ = q.front().second;
				board[nowI][nowJ] = '.';
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nextI = nowI + moveI[i];
					int nextJ = nowJ + moveJ[i];
					if (nextI < 0 || nextJ < 0 || nextI >= R || nextJ >= C) continue;
					board[nextI][nextJ] = '.';
				}
			}
			cnt += 2;
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

}
