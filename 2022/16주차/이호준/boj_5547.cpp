/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
5547 일루미네이션
2022/07/06 이호준
# 아이디어
1. 정육각형 BFS -> 좌표를 분석하여 6개의 방향으로 이동, 이때 짝수와 홀수가 다르다는 것을 확인해야함 (문제에서도 확인가능)
2. 외각을 찾아 선택해야하므로 행과 열의 좌표에 1씩 여유를 두어 좌표를 넘어가도 확인할 수 있도록 한다. 
   즉, 외각을 찾을 때 좌표공간을 넘어가는 곳이 생기는데 (건물이 끝단에 존재할경우 외각의 위치는 좌표공간을 넘어감)
   이때, 행과 열에 1씩 여유공간을 두고 빈공간으로 체크해서 
   건물과 빈공간의 유무로 외각 변의 위치를 찾아서 개수를 증가시키는 논리를 동일하게 사용할 수 있도록 한다.
*******************************************************************/
#include <iostream>
#include <queue>
using namespace std;

int graph[102][102];
int R, C;

int even_dir[6][2] = { {1,-1},{1,0},{-1,-1},{-1,0},{0,-1},{0,1} };
int odd_dir[6][2] = { {1,0},{1,1},{-1,0},{-1,1},{0,-1},{0,1} };

int bfs(int x, int y) {
	int result = 0;
	queue<pair<int, int>>q;
	q.push({ x, y });

	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();
		//행이 짝수일 때
		if (current_x % 2 == 0) {
			for (int i = 0; i < 6; i++) {
				int next_x = current_x + even_dir[i][0];
				int next_y = current_y + even_dir[i][1];
				if (next_x >= 0 && next_x <= R + 1 && next_y >= 0 && next_y <= C + 1) {
					if (graph[next_x][next_y] == 0) {
						q.push({ next_x,next_y });
						graph[next_x][next_y] = -1;
					}
					else if (graph[next_x][next_y] == 1) {
						result++;
					}

				}
			}
		}
		//행이 홀수일 때
		else {
			for (int i = 0; i < 6; i++) {
				int next_x = current_x + odd_dir[i][0];
				int next_y = current_y + odd_dir[i][1];
				if (next_x >= 0 && next_x <= R + 1 && next_y >= 0 && next_y <= C + 1) {
					if (graph[next_x][next_y] == 0) {
						q.push({ next_x,next_y });
						graph[next_x][next_y] = -1;
					}
					else if (graph[next_x][next_y] == 1) {
						result++;
					}
				}
			}
		}
	}

	return result;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> graph[i][j];
		}
	}

	cout << bfs(0, 0);

	return 0;
}