/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
17144 미세먼지 안녕!
2022/03/20 이호준
# 아이디어
1. 조건에 맞추어 구현. 좌표 공간 조작하기..
정말로 빡구현이다. 실수가 많았다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0, 1, 0 , -1 };

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int r, c, t;

	cin >> r >> c >> t;

	vector<vector<int>> map(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	// 에어컨 상하 찾기
	pair<int, int> up;
	pair<int, int> down;
	for (int i = 0; i < r; i++) {
		if (map[i][0] == -1) {
			up = { i, 0};
			down = { i + 1, 0 };
			break;
		}
	}

	while (t != 0) {
		t--;
		vector<vector<int>> map2(r, vector<int>(c, 0));
		map2[up.first][up.second] = -1;
		map2[down.first][down.second] = -1;
		// 미세먼지 전파
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					int current_value = map[i][j];
					int add_value = current_value / 5;
					map2[i][j] += current_value;
					for (int a = 0; a < 4; a++) {
						int next_x = i + dx[a];
						int next_y = j + dy[a];
						if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c) {
							if (map[next_x][next_y] >= 0) {
								map2[next_x][next_y] += add_value;
								map2[i][j] -= add_value;
							}
						}
					}
				}
			}
		}
		/*for (auto a : map2) {
			for (auto b : a)
				cout << b << " ";
			cout << "\n";
		}*/
		//공기 청정기 가동
		

		//up
		int current_x = up.first - 1;
		int current_y = up.second;
		while (1) {

			if (current_x == up.first && current_y == up.second) {
				map2[current_x][current_y + 1] = 0;
				break;
			}

			if (current_x < 0) {
				current_x = 0;
				current_y = 1;
			}
			if (current_y >= c) {
				current_y = c - 1;
				current_x = 1;
			}
			if (current_x > up.first) {
				current_x = up.first;
				current_y = c - 2;
			}
			
			if (current_y == 0) {
				if (make_pair(current_x + 1, current_y) != up) {
					map2[current_x + 1][0] = map2[current_x][0];
				}
				current_x--;
			}else if (current_x == 0) {
				map2[0][current_y - 1] = map2[0][current_y];
				current_y++;
			}
			else if (current_y == c - 1) {
				map2[current_x - 1][c - 1] = map2[current_x][c - 1];
				current_x++;
			}
			else if (current_x == up.first) {
				map2[current_x][current_y + 1] = map2[current_x][current_y];
				current_y--;
			}
		}

		// down

		current_x = down.first + 1;
		current_y = down.second;
		while (1) {

			if (current_x == down.first && current_y == down.second) {
				map2[current_x][current_y + 1] = 0;
				break;
			}

			if (current_x < down.first) {
				current_x = down.first;
				current_y = c - 2;
			}
			if (current_y >= c) {
				current_y = c - 1;
				current_x = r - 2;
			}
			if (current_x >= r) {
				current_x = r -1;
				current_y = 1;
			}

			if (current_y == 0) {
				if (make_pair(current_x - 1, current_y) != down) {
					map2[current_x - 1][0] = map2[current_x][0];
				}
				current_x++;
			}
			else if (current_x == r - 1) {
				map2[current_x][current_y - 1] = map2[current_x][current_y];
				current_y++;
			}
			else if (current_y == c-1) {
				map2[current_x + 1][c - 1] = map2[current_x][c - 1];
				current_x--;
			}
			else if (current_x == down.first) {
				map2[current_x][current_y + 1] = map2[current_x][current_y];
				current_y--;
			}
		}

		map = map2;
	}

	int sum = 2;

	for (auto a : map) {
		for (auto b : a)
			sum += b;
	}

	cout << sum;

	return 0;
}