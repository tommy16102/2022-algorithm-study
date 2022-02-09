/*******************************************************************
Algorithm Study
Baekjoon OJ Graph
2636 치즈
2022/02/08 이호준
# 아이디어
1. 문제가 제시한 흐름대로 구현
	1. 외각 찾기
	2. 치즈 녹이기
	반복진행
DFS이용
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { 1, 0, 0, -1 };

bool visited[101][101];

int R, C;
int cheese;


// 외각 찾기
void findC(int x, int y, vector<vector<int>> & map) {
	if (map[x][y] == 0) {
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C) {
				if (!visited[next_x][next_y]) {
					if (map[next_x][next_y] == 0) {
						visited[next_x][next_y] = true;
						findC(next_x, next_y, map);
					}
					if (map[next_x][next_y] == 1) {
						map[next_x][next_y] = 2;
					}
				}
			}
		}
	}
}

void meltCheese(int x, int y, vector<vector<int>> & map) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 녹는치즈
			if (map[i][j] == 2) {
				map[i][j] = 0;
				cheese--;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	vector<vector<int>> map(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) {
				cheese++;
			}
		}
	}

	int time = 0;
	int lastcheese = cheese;
	while (1) {

		time++;
		// 외각 치즈 찾기
		visited[0][0] = true;
		findC(0, 0, map);

		/*for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/
		
		// 치즈 녹이기
		meltCheese(0, 0, map);

		// 탈출 확인
		if (!cheese) {
			break;
		}
		else {
			lastcheese = cheese;
		}
		// 초기화
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visited[i][j] = false;
			}
		}

	}

	cout << time << "\n";
	cout << lastcheese << "\n";

	return 0;
}