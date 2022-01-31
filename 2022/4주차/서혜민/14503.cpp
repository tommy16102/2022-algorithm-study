#include <iostream>
#include <queue>
using namespace std;

/*

2022.1.31

시작지점부터 DFS를 통해 탐색이 가능한 좌측 지점으로 탐색을 하며,
탐색이 불가능한 경우, 후진을 하여 모든 탐색이 끝날 때까지 재귀를 돈다.

*/

int N, M;
int place[51][51];
bool visited[51][51];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

void dfs(int i, int j, int dir, int cnt) {
	if (!visited[i][j] && place[i][j] == 0) {
		visited[i][j] = 1;
		cnt++;
	}
	
	int notn = 0;
	for (int x = 0;x < 4;x++) {
		int newDir = (dir + 3 - x) % 4;
		int newI = i + moveI[newDir];
		int newJ = j + moveJ[newDir];

		if (newI<0 || newJ<0 || newI>=N || newJ>=M) continue;

		if (!visited[newI][newJ] && !place[newI][newJ]) {
			dfs(newI, newJ, newDir, cnt);
		}
		else notn++;
	}

	if (notn== 4) {
		int newDir = (dir + 2) % 4;
		int newI = i + moveI[newDir];
		int newJ = j + moveJ[newDir];
		if (newI >= 0 && newJ >= 0 && newI < N && newJ < M) {
			if (place[newI][newJ]) {
				cout << cnt << '\n';
				exit(0);
			}
			else dfs(newI, newJ, dir, cnt);
		}
	}
}

int main() {

	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> place[i][j];
		}
	}
	dfs(r, c, d, 0);
}
