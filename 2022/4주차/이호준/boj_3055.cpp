/*******************************************************************
Algorithm Study
Baekjoon OJ GRAPH
3055 탈출
2022/02/08 이호준
# 아이디어
1. BFS
불!, 아기상어와 비슷한 흐름
문제의 조건대로 BFS설계

2가지 방법론 존재
1. BFS의 level이용
2. 각각 따로 BFS를 실시하여 해당 block까지 걸리는 time을 비교
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

#define max_int 51

using namespace std;


int r, c;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

queue<pair<int, int>> q;
queue<pair<int, int>> water_q;

pair<int, int> gool;
pair<int, int> start;

int water_day[max_int][max_int];
int check[max_int][max_int];

void water_bfs(vector<vector<char>> & map) {
	while (!water_q.empty()) {
		int x = water_q.front().first;
		int y = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (water_day[nx][ny] == 0 && map[nx][ny] == '.') {
					water_day[nx][ny] = water_day[x][y] + 1;
					water_q.push({ nx, ny });
				}
			}
		}
	}
}

void bfs(vector<vector<char>> &map) {
	q.push({ start.first, start.second });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (check[nx][ny] == 0 && (map[nx][ny] == '.' || map[nx][ny] == 'D')) {
					// 도착점은 바로 큐에 넣어줍니다.
					if (water_day[nx][ny] == 0) {
						check[nx][ny] = check[x][y] + 1;
						q.push({ nx, ny });
					}
					else {
						// 이동하려는 칸이 다음날 물이 차오르지 않는다면 큐에 넣어줍니다.
						if (water_day[nx][ny] > check[x][y] + 1) {
							check[nx][ny] = check[x][y] + 1;
							q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> r >> c;

	vector<vector<char>> map(r, vector<char>(c, ' '));


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 'D') {
				gool = { i, j };
			}
			else if (temp == 'S') {
				start = { i, j };
			}
			else if (temp == '*') {
				water_q.push({ i, j });
			}
		}
	}

	water_bfs(map);
	bfs(map);

	if (check[gool.first][gool.second] != 0) {
		printf("%d\n", check[gool.first][gool.second]);
	}else {
		printf("KAKTUS\n");
	}

	return 0;
}