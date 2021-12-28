#include <iostream>
using namespace std;

/*

2021.08.09 서혜민

0,0부터 dfs를 통해서 해당 위치의 숫자가 0이라면 1부터 9까지 입력을 했을 때,
세로, 가로, 사각형 조건을 모두 만족시키면, dfs함수를 재귀호출하여, 다시
0,0부터 이 과정을 반복한다.

*/

int sudoku[9][9];

bool jCheck(int n) {
	int count[10] = { 0, };
	for (int i = 0;i < 9;i++) {
		if (sudoku[n][i] != 0) count[sudoku[n][i]]++;
		if (count[sudoku[n][i]] >= 2) return false;
	}
	return true;
}

bool iCheck(int n) {
	int count[10] = { 0, };
	for (int i = 0;i < 9;i++) {
		if (sudoku[i][n] != 0) count[sudoku[i][n]]++;
		if (count[sudoku[i][n]] >= 2) return false;
	}
	return true;
}

bool squareCheck(int x, int y) {
	int count[10] = { 0, };
	int newX = x / 3 * 3;
	int newY = y / 3 * 3;
	for (int i = newX;i <= newX + 2;i++) {
		for (int j = newY;j <= newY + 2;j++) {
			if (sudoku[i][j] != 0) count[sudoku[i][j]]++;
			if (count[sudoku[i][j]] >= 2) return false;
		}
	}
	return true;
}

void dfs() {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (sudoku[i][j] == 0) {
				for (int k = 1;k <= 9;k++) {
					sudoku[i][j] = k;
					if (jCheck(i) && iCheck(j) && squareCheck(i, j)) {
						dfs();
					}
					sudoku[i][j] = 0;
				}
				return;
			}
			if (i == 8 && j == 8) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						cout << sudoku[i][j] << ' ';
					}
					cout << '\n';
				}
				exit(0);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> sudoku[i][j];
		}
	}
	dfs();
}
