#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

2022.1.27

4179번 문제 불과 같은 방법으로 접근.

*/

char map[50][50];
int water[50][50];
int moveS[50][50];
bool visited[50][50];
bool visited2[50][50];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;

	int gI, gJ;
	vector<pair<int, int>> v;

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
			water[i][j] = 50 * 50 + 1;
			moveS[i][j] = 50 * 50 + 1;
			if (map[i][j] == '*') {
				v.push_back({ i, j });
				water[i][j] = 0;
			}
			if (map[i][j] == 'S') {
				gI = i;
				gJ = j;
				moveS[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> queue;
	if (!v.empty()) {
		for (auto ij : v) {
			queue.push({ ij.first, ij.second });
			visited[ij.first][ij.second] = 1;
		}
		while (!queue.empty()) {
			int i = queue.front().first;
			int j = queue.front().second;
			int sec = water[i][j];
			queue.pop();
			for (int x = 0;x < 4;x++) {
				int newI = i + moveI[x];
				int newJ = j + moveJ[x];
				if (newI < 0 || newJ < 0 || newI >= R || newJ >= C) continue;
				if (visited[newI][newJ]) continue;
				if (map[newI][newJ] == 'D' || map[newI][newJ] == 'X' || water[newI][newJ] < sec + 1) continue;
				water[newI][newJ] = sec + 1;
				visited[newI][newJ] = 1;
				queue.push({ newI, newJ });
			}
		}
	}

	queue.push({ gI, gJ });
	visited2[gI][gJ] = 1;
	while (!queue.empty()) {
		int i = queue.front().first;
		int j = queue.front().second;
		int sec = moveS[i][j];
		if (map[i][j] == 'D') {
			cout << sec << '\n';
			return 0;
		}
		queue.pop();
		for (int x = 0;x < 4;x++) {
			int newI = i + moveI[x];
			int newJ = j + moveJ[x];
			if (newI < 0 || newJ < 0 || newI >= R || newJ >= C) continue;
			if (visited2[newI][newJ]) continue;
			if (map[newI][newJ] == 'X' ||  water[newI][newJ] <= sec + 1) continue;
			moveS[newI][newJ] = sec + 1;
			visited2[newI][newJ] = 1;
			queue.push({ newI, newJ });
		}
	}
	cout << "KAKTUS\n";
}