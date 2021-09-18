#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int board[15] = {0,}; // 각 세로번째가 몇번째 가로칸에 놓여있는지?
int answer;

/*
    푼 날짜 : 2021/08/14
    아이디어 : DFS 및 백트래킹
*/

void input() {
	cin >> N;
}

bool cango(int sero) {
	for (int i = 0; i < sero; i++) { // 현재까지 놓여진 퀸들이
		if (board[i] == board[sero]) // 같은 가로칸에 있는지?
			return false;
		if (sero - i == abs(board[sero] - board[i])) // 대각선에 있는지?
			return false;
	}
	return true;
}

void dfs(int sero) {
	if (sero == N) { // 끝 칸까지 잘 놓았음
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) { // 모든 가로칸에 시도해보기
		board[sero] = i;
		if (cango(sero)) { // 갈 수 있으면
			dfs(sero + 1); // 다음 세로칸으로 이동
		}
	}

}

void solve() {

	dfs(0);
	cout << answer;

}

int main() {

	input();
	solve();

	return 0;
}
