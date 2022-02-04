#include <iostream>
#include <queue>
using namespace std;

/*

2022.2.4

아기 상어의 시작점을 기준으로 BFS를 통해 먹을 수 있는 물고기의 위치로 이동하여
반복적으로 BFS를 통해 더는 먹을 물고기가 없을 때까지 이동을 해나간다.

이때 이동을 할 때마다, 먹은 횟수 cnt, 물고기 크기 size, 소요 시간 sec을 업데이트.

*/

int map[21][21];
bool visited[21][21];
int map2[21][21];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int sec = 0, cnt = 0, size = 2, sI, sJ;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) sI = i, sJ = j;
		}
	}

	map[sI][sJ] = 0;
	while (1) {
		int count = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (map[i][j] != 0 && map[i][j] < size) count++;
			}
		}

		if (!count) {
			cout << sec << '\n';
			return 0;
		}
		
		map2[sI][sJ] = 0;

		queue<pair<int, int>> queue;
		queue.push({sI,sJ});
		visited[sI][sJ] = 1;
		int min = N * N + 1;
		while (!queue.empty()) {
			int i = queue.front().first;
			int j = queue.front().second;
			int sec = map2[i][j];
			if (map[i][j] != 0 && map[i][j] < size && sec < min) min = sec;
			queue.pop();
			for (int x = 0;x < 4;x++) {
				int newI = i + moveI[x];
				int newJ = j + moveJ[x];
				if (newI<1 || newJ<1 || newI>N || newJ>N) continue;
				if (sec + 1 > min || map[newI][newJ] > size) continue;
				if (visited[newI][newJ]) continue;
				visited[newI][newJ] = 1;
				map2[newI][newJ] = sec + 1;
				queue.push({newI,newJ});
			}
		}
	
		bool out = false;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (i == sI && j == sJ) continue;
				if (min == map2[i][j] && map[i][j]!=0 && map[i][j]<size) {
					sI = i;
					sJ = j;
					out = 1;
				}
				if (out) break;
			}
			if (out) break;
		}
		if (out) {
			map[sI][sJ] = 0;
			sec += map2[sI][sJ];
			cnt++;
			if (cnt >= size) {
				size++;
				cnt = 0;
			}
		}
		else {
			cout << sec << '\n';
			return 0;
		}

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				visited[i][j] = 0;
				map2[i][j] = 0;
			}
		}
	}
}
