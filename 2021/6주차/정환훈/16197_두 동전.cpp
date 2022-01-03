#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/15
    아이디어 : DFS
*/

int n; int m;
char board[22][22]; // 사방 테두리에 떨어짐을 의미하는 'x'를 추가
pair<int, int> x; // 동전1
pair<int, int> y; // 동전2
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> answers;

void input() {

	bool turn = false; // 동전1 -> 동전2 좌표 체크할 때 임시변수

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			board[i][j] = 'x';
		}
	}

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') { // 동전 좌표면
				if (turn == false) { // 처음에는 x
					x.first = i; x.second = j;
					turn = true;
				}
				else { // 두번째는 y
					y.first = i; y.second = j;
				}
			}
		}
	}

	//for (int i = 0; i < n + 2; i++) {
	//	for (int j = 0; j < m + 2; j++) {
	//		cout << board[i][j];
	//	}
	//	cout << endl;
	//}

}

bool isout(pair<int, int> n) { // 동전이 떨어졌는지?
	if (board[n.first][n.second] == 'x') {
		return true;
	}
	return false;
}

void dfs(int depth, pair<int, int> x, pair<int, int> y) {



	if (x.first == y.first && x.second == y.second) // 두개 동전이 겹치면 희망이 없다
		return;

	bool xout = isout(x);	
	bool yout = isout(y);

	if (xout == true && yout == true) { // 둘다 떨어지는 경우
		return;
	}

	if ((xout == true && yout == false) || (xout == false && yout == true)) { // 정답인 경우
		answers.push_back(depth);
		return;
	}

	if (depth == 10) { // 10번 누른 경우 끝
		return;
	}


	for (int i = 0; i < 4; i++) {
		int xnx = x.first + dx[i];
		int ynx = y.first + dx[i];
		int xny = x.second + dy[i];
		int yny = y.second + dy[i];

		pair<int, int> nx = make_pair(xnx, xny); // 다음 동전 x의 좌표
		pair<int, int> ny = make_pair(ynx, yny); // 다음 동전 y의 좌표

		if (board[xnx][xny] == '#') { // 사실 벽이어서 못 가는 곳이었으면 제자리
			nx.first = x.first;
			nx.second = x.second;
		}
		if (board[ynx][yny] == '#') { // y가 벽에 충돌시
			ny.first = y.first;
			ny.second = y.second;
		}

		dfs(depth + 1, nx, ny);		
	}

}


void solve() {
	dfs(0, x, y);
	if (answers.empty()) {
		cout << -1;
	}
	else {
		sort(answers.begin(), answers.end());
		cout << answers[0];
	}
}

int main() {

	input();
	solve();

	return 0;
}