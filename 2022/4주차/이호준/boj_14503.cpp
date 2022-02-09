/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
14503 로봇청소기
2022/02/08 이호준
# 아이디어
1. 문제가 제시한대로 BFS실행
dx와 dy를 시계방향으로 설계하여 ++을 통해 direction조정
그리고 피드백 결과 %4를 이용하면 if을 이용한 예외연산 필요없이 한줄로 간단하게 해결할 수 있다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool visited[51][51];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;


	int start_x, start_y, direction;

	cin >> start_x >> start_y >> direction;
	direction = 3 - direction;

	/*if (direction == 0)
		direction = 3;
	else if (direction == 1)
		direction = 2;
	else if (direction == 2)
		direction = 1;
	else if (direction == 3)
		direction = 0;*/

	vector<vector<int>> map(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int clean = 0;
	if (!map[start_x][start_y]) {
		visited[start_x][start_y] = true;
		map[start_x][start_y] = 2;
		clean++;
	}
	bool finish = false;
	while (1) {

		if (finish) {
			break;
		}


		// 청소
		for (int i = 0; i < 5; i++) {

			//cout << start_x << " " << start_y << "\n";

			// 2.c
			if (i == 4) {
				int back_x = start_x - dx[direction];
				int back_y = start_y - dy[direction];
				if (back_x < 0 || back_x >= n || back_y < 0 || back_y >= m) {
					finish = true;
					break;
				}
				else {
					if (map[back_x][back_y] != 1) {
						i = -1;
						start_x = back_x;
						start_y = back_y;
						continue;
					}
					else {
						finish = true;
						break;
					}	
				}
			}

			// 방향전환
			direction++;
			if (direction > 3)
				direction = 0;

			int test_x = start_x + dx[direction];
			int test_y = start_y + dy[direction];
			
			// 2.a
			if (test_x >= 0 && test_x < n && test_y >= 0 && test_y < m) {
				if (!visited[test_x][test_y] && map[test_x][test_y] == 0) {
					visited[test_x][test_y] = true;
					map[test_x][test_y] = 2;
					start_x = test_x;
					start_y = test_y;
					clean++;
					break;
				}
			}
		}
	}

	cout << clean;

	return 0;
}