#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/06
    아이디어 : dx[i], dy[i]로 갈 수 있는 방향 모두 표시 후
    모든 양 위치 찾아서 양의 네방향이 .이면 벽으로 막아버리기

*/

int r; int c;
char** d;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool canletgo() { // 바로 옆에 있어서 못 막는 경우
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (d[i][j] == 'S') {


				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];


					if (x >= 0 && x < r && y >= 0 && y < c) {
						if (d[x][y] == 'W') { // 바로 맞닿은 자리에 늑대가 있다
							return false;
						}
					}

				}
			}
		}
	}
	return true;
}


int main() {

	cin >> r >> c;

	d = new char*[r];
	for (int i = 0; i < r; i++) {
		d[i] = new char[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> d[i][j];
		}
	}


	if (!canletgo()) {
		cout << 0;
		return 0;
	}

	cout << endl << 1 << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (d[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k]; 
					int y = j + dy[k];
					if (x >= 0 && x < r && y >= 0 && y < c) {
						if (d[x][y] == '.') {
							d[x][y] = 'D';
						}
					}

				}
			}
		}
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << d[i][j];
		}
		cout << endl;
	}

	return 0;
}

