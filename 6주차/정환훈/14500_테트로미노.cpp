#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/13
    아이디어 : 브루트포스(중에서도 브루트)
*/

int n; int m;
int map[500][500] = { 0 };
int answer = 0;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs() {


	for (int i = 0; i < n; i++) { // 긴거
		for (int j = 0; j < m - 3; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n-3; i++) { // 긴거2
		for (int j = 0; j < m; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (answer < s) {
				answer = s;
			}
		}
	}


	for (int i = 0; i < n - 1; i++) { // 네모
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}



	for (int i = 0; i < n - 2; i++) { // L
		for (int j = 0; j < m -1; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { // ┌ : L 90도
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 2; i++) { // ㄱ : L 180도
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 1; i < n; i++) { // ┘ : L 270도
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 2; i < n; i++) { // L 가로대칭
		for (int j = 0; j < m-1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 2][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 2; i++) { // 둘째 가로대칭
		for (int j = 0; j < m-1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 2; i++) { // 셋째 가로대칭
		for (int j = 0; j < m-1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { // 넷째 가로대칭
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (answer < s) {
				answer = s;
			}
		}
	}




	for (int i = 0; i < n - 2; i++) { // 초록색
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 1; i < n; i++) { // 초록색 90 회전
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
			if (answer < s) {
				answer = s;
			}
		}
	}


	for (int i = 2; i < n; i++) { // 초록색 대칭1
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i - 1][j] + map[i - 1][j + 1] + map[i - 2][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { // 초록색 대칭2
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { // 보라돌이
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { // 보라돌이
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 1; i < n - 1; i++) { // 보라돌이 90
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i + 1][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 1; i < n; i++) { // 보라돌이 180
		for (int j = 0; j < m - 2; j++) {
			int s = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
			if (answer < s) {
				answer = s;
			}
		}
	}

	for (int i = 0; i < n - 2; i++) { // 보라돌이 270
		for (int j = 0; j < m - 1; j++) {
			int s = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if (answer < s) {
				answer = s;
			}
		}
	}


	cout << answer;
}

void solve() {
	dfs();
}

int main() {

	input();
	solve();

	return 0;
}
