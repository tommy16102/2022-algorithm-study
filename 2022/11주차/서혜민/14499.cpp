#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int dice[7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	while (K--) {
		int move;
		cin >> move;

		int s = dice[6];

		if (move == 1) {
			if (y < M - 1) y++;
			else continue;
			dice[6] = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[5];
			dice[5] = s;
		}
		else if (move == 2) {
			if (y > 0) y--;
			else continue;
			dice[6] = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[3];
			dice[3] = s;

		}
		else if (move == 3) {
			if (x > 0) x--;
			else continue;
			dice[6] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[4];
			dice[4] = s;
		}
		else {
			if (x < N - 1) x++;
			else continue;
			dice[6] = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[2];
			dice[2] = s;
		}
		if (!map[x][y]) map[x][y] = dice[6];
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << '\n';
	}
}
