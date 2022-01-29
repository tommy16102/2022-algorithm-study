#include <iostream>
#include <queue>
using namespace std;

/*

2022.1.29

전체 판에서 가장 먼저 나오는 0을 기준으로 BFS 탐색을 하면서 1을 탐색하게 되면,
이를 0으로 바꿔주는 방식을 모든 1을 탐색할 때까지 반복한다.

치즈 칸의 수는 첫 입력을 받았을 때 전체 치즈의 칸 수에서, BFS 탐색을 할 때
0으로 바꿔줄 때마다 칸 수를 감소시킨다.

*/

int pan[101][101];
bool visited[101][101];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sero, garo;
	int count = 0, pCount = 0 ;
	cin >> sero >> garo;

	for (int i = 1;i <= sero;i++) {
		for (int j = 1;j <= garo;j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 1) count++;
		}
	}

	queue<pair<int, int>> q;
	int h = 0;
	while (count) {
		pCount = count;
		bool findZero = 0;
		for (int i = 1;i <= sero;i++) {
			for (int j = 1;j <= garo;j++) {
				if (pan[i][j] == 0) {
					q.push({ i,j });
					visited[i][j] = 1;
					findZero = 1;
				}
				if (findZero) break;
			}
			if (findZero) break;
		}

		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			for (int x = 0;x < 4;x++) {
				int newI = i + moveI[x];
				int newJ = j + moveJ[x];
				if (newI<1 || newJ<1 || newI>sero || newJ>garo || visited[newI][newJ]) continue;
				visited[newI][newJ] = 1;
				if (pan[newI][newJ] == 0) q.push({ newI,newJ });
				else if (pan[newI][newJ] == 1) {
					pan[newI][newJ] = 0;
					count--;
				}
			}
		}

		for (int i = 1;i <= sero;i++) {
			for (int j = 1;j <= garo;j++) {
				visited[i][j] = 0;
			}
		}
		h++;
	}
	cout << h << '\n' << pCount << '\n';
}
