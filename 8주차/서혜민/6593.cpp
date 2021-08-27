#include <string>
#include <iostream>
#include <queue>
using namespace std;

/*

2021.09.03 서혜민

동서남북+ 상,하 이동가능하므로 3차원 배열을 이용하여 bfs를 통해 경로의 길이를 저장해가며 탐색을 하도록 하였다.

*/

string s[30][30];

int moveX[6] = {0,0,1,-1,0,0};
int moveY[6] = {0,0,0,0,1,-1};
int moveZ[6] = {1,-1,0,0,0,0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0;i < L;i++) {
			for (int j = 0;j < R;j++) {
				cin >> s[i][j];
			}
		}

		queue<pair<int,pair<int,int>>> queue;

		bool canGo = 0;
		int count[30][30][30] = { 0, };
		bool visited[30][30][30] = { 0, };

		for (int i = 0;i < L;i++) {
			if (canGo) break;
			for (int j = 0;j < R;j++) {
				if (canGo) break;
				for (int k = 0;k < C;k++) {
					if (canGo) break;
					if (s[i][j][k] == 'S' && !visited[i][j][k]) {
						queue.push({ i,{j,k} });
						visited[i][j][k] = 1;
					}
					else continue;
					while (!queue.empty()) {
						int z = queue.front().first;
						int x = queue.front().second.first;
						int y = queue.front().second.second;
						if (s[z][x][y] == 'E') {
							canGo = 1;
							cout << "Escaped in " << count[z][x][y] << " minute(s)." << '\n';
							break;
						}
						queue.pop();
						for (int a = 0;a < 6;a++) {
							int newZ = z + moveZ[a];
							int newX = x + moveX[a];
							int newY = y + moveY[a];
							if (newZ >= 0 && newZ < L && newX >= 0 && newX < R && newY >= 0 && newY < C) {
								if (!visited[newZ][newX][newY] && s[newZ][newX][newY]!='#') {
									count[newZ][newX][newY] = count[z][x][y] + 1;
									queue.push({ newZ,{newX,newY} });
									visited[newZ][newX][newY] = 1;
								}
							}
						}
					}
					if(!canGo) cout << "Trapped!" << '\n';
				}
			}
		}
	}
}
