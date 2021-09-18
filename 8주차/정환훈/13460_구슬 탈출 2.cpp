#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210829

int n; int m;
pair<int, int> red_start; // red 초기 위치
pair<int, int> blue_start; // blue 초기 위치
pair<int, int> goal; // goal
char board[11][11]; // board 초기 상황
int answer = -1;
vector<int> answers;
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			board[i][j] = 'x';
		}
	}

	for (int i = 1; i <= n; i++) { // 세로 1~n
		for (int j = 1; j <= m; j++) { // 가로 1~m
			char temp;
			cin >> temp;
			board[i][j] = temp;
			if (temp == 'R') {
				red_start = make_pair(i, j);
			}
			else if(temp == 'B'){
				blue_start = make_pair(i, j);
			}
			else if (temp == 'O') {
				goal = make_pair(i, j);
			}
		}
	}

	//for (int i = 0; i < 15; i++) {
	//	for (int j = 0; j < 15; j++) {
	//		cout << board[i][j] << " ";
	//	}
	//	cout << endl;
	//}

}


pair<int, int> letsgo(int dir, pair<int, int> ball) {

	switch (dir) {
	case 0: // down
		while (board[ball.first + 1][ball.second] != '#') { // 벽 아닐때까지 이동
			ball.first++;
			if (board[ball.first][ball.second] == 'O') { // 구멍 만나면 탈출
				break;
			}
		}
		break;
	case 1: // right
		while (board[ball.first][ball.second + 1] != '#') {
			ball.second++;
			if (board[ball.first][ball.second] == 'O') {
				break;
			}
		}
		break;
	case 2: // up
		while (board[ball.first - 1][ball.second] != '#') {
			ball.first--;
			if (board[ball.first][ball.second] == 'O') {
				break;
			}
		}
		break;
	case 3: // left
		while (board[ball.first][ball.second - 1] != '#') {
			ball.second--;
			if (board[ball.first][ball.second] == 'O') {
				break;
			}
		}
		break;
	}

	return ball;
}

bool isgoal(pair<int, int> ball) { // 골임?
	if (board[ball.first][ball.second] == 'O')
		return true;

	return false;
}


void dfs(int depth, pair<int, int> red, pair<int, int> blue) {


	if (depth == 11) // 최대 횟수 10번
		return;

	if (isgoal(blue)) { // 파랑이 구멍에 빠짐
		return;
	}

	if (isgoal(red)) {
		answers.push_back(depth);
		return;
	}

	for (int i = 0; i < 4; i++) {
		pair<int, int> n_red = letsgo(i, red); // 다음 red의 좌표
		pair<int, int> n_blue = letsgo(i, blue); // 다음 blue의 좌표
		if (n_red.first == n_blue.first && n_red.second == n_blue.second && !isgoal(n_red)) { // 겹쳐지는 경우 해결[goal 아닐 경우에만]
			switch (i) {
			case 0: // down
				if (red.first < blue.first)		//R
												//B
					n_red.first--;
				else							// B
					n_blue.first--;				// R

				//cout << n_red.first << " " << n_blue.first << endl;
				break;
			case 1: // right

				if (red.second < blue.second) // RB
					n_red.second--;
				else
					n_blue.second--;
				break;
			case 2: // up

				if (red.first < blue.first)	//R
												//B
					n_blue.first++;
				else							// B
					n_red.first++;				// R
				break;
			case 3: // left
				if (red.second < blue.second)
					n_blue.second++; // RB
				else
					n_red.second++; // BR
				break;
			}
		}
		dfs(depth + 1, n_red, n_blue);
	}

}


void solve() {

	dfs(0, red_start, blue_start);
	if (answers.size() == 0) {
		cout << -1; return;
	}
	sort(answers.begin(), answers.end());
	cout << answers[0];

}

int main() {

	input();
	solve();
	return 0;
}