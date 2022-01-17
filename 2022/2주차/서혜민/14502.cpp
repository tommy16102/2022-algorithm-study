#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

2022.1.17

재귀를 통해서 빈 칸에 벽을 3개 세우고, BFS를 통해 3개의 바이러스 칸에서 모두 확산을 시킨 뒤,
존재하는 빈 칸의 개수 중 가장 큰 수를 구함.
이 때, 기존의 입력을 받은 map 배열 외에, 벽을 세우기 위한 copyMap과, BFS탐색을 위한 bfsMap을 선언하여,
copy함수 => copy(원본 시작 주소, 원본 끝 주소, 복사본 시작 주소)를 통해 배열 복사.

*/

int N, M;
int count = 0;
int map[9][9];
int copyMap[9][9];
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { -1,0,1,0 };
vector<pair<int, int>> v;

void bfs() {
	int bfsMap[9][9];
	copy(&copyMap[0][0], &copyMap[0][0] + 9 * 9, &bfsMap[0][0]);

	for (int i = 0;i < v.size();i++) {
		queue<pair<int, int>> queue;
		queue.push({ v[i].first,v[i].second });

		while (!queue.empty()) {
			int x = queue.front().first;
			int y = queue.front().second;
			queue.pop();

			for (int i = 0;i < 4;i++) {
				int newX = x + moveX[i];
				int newY = y + moveY[i];
				if (newX<1 || newY<1 || newX>N || newY>M) continue;
				if (bfsMap[newX][newY] == 0) {
					bfsMap[newX][newY] = 2;
					queue.push({ newX,newY });
				}
			}
		}
	}

	int safe = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (bfsMap[i][j] == 0) safe++;
		}
	}

	if (safe > ::count) ::count = safe;
}

void wall(int cnt, int x, int y) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (copyMap[i][j] == 0 && (i >= x || j >= y)) {
				copyMap[i][j] = 1;
				wall(cnt + 1, i, j);
				copyMap[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (map[i][j] == 0) {
				copy(&map[0][0], &map[0][0] + 9 * 9, &copyMap[0][0]);
				copyMap[i][j] = 1;
				wall(1,i,j);
				copyMap[i][j] = 0;
			}
		}
	}

	cout << ::count << '\n';
}
