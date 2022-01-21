#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

/*

2022.1.21

BFS를 통해 상하좌우,대각선으로 연결된 섬의 개수를 찾았다

*/

int map[50][50];
bool visited[50][50];

int moveI[8] = { -1,-1,0,1,1,1,0,-1 };
int moveJ[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0;i < 50;i++) {
			for (int j = 0;j < 50;j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> map[i][j];
			}
		}

		int count = 0;
		queue<pair<int, int>> queue;
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					queue.push({ i,j });
					while (!queue.empty()) {
						int qI = queue.front().first;
						int qJ = queue.front().second;
						queue.pop();
						for (int k = 0;k < 8;k++) {
							int newI = qI + moveI[k];
							int newJ = qJ + moveJ[k];
							if (newI < 0 || newJ < 0 || newI >= h || newJ >= w || visited[newI][newJ]) continue;
							if (map[newI][newJ] == 1) {
								queue.push({ newI,newJ });
								visited[newI][newJ] = 1;
							}
						}
					}
					count++;
				}
				else continue;
			}
		}
		cout << count << '\n';
	}
}