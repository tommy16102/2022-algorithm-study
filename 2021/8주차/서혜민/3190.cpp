#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*

2021.09.03 서혜민

방향을 정하는 right, left, up, down변수.
default는 right 방향이므로 right만 1 나머지는 0.

deque에 좌표(1,1)을 저장 후, 해당 방향으로 진행하면서, 해당 좌표가 사과이면 deque에 추가로 좌표를 저장하고,
사과가 아니라면 좌표의 최상위에 있는, 즉 꼬리의 좌표를 pop해준다.
또한 뱀이 속한 기존의 0이었던 board 배열 내 값을 1로 바꿔주고. pop해준 좌표는 0으로 다시 바꿔준다.

이 과정을 해당 방향으로 진행하는 새로운 좌표가 벽에 닿거나, 뱀이 속한, 즉 board 배열 내 값이 1일 때까지 진행한다.

*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int K;
	cin >> K;

	char board[101][101];
	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 101;j++) {
			board[i][j] = '0';
		}
	}

	while (K--) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 'A';
	}

	int L;
	cin >> L;

	vector<pair<int, char>> v;
	while (L--) {
		int x;
		char c;
		cin >> x >> c;
		v.push_back({ x,c });
	}

	deque<pair<int, int>> deque;
	deque.push_back({ 1,1 });
	board[1][1] = 1;

	bool right = 1;
	bool left = 0, up = 0, down = 0;

	int second = 0;

	int count = 0;
	//범위 1~N
	while (1) {
		int x = deque.back().first;
		int y = deque.back().second;
		if (second == v[count].first) {
			if (v[count].second == 'L') {
				if (right) {
					up = 1;
					down = 0, left = 0, right = 0;
				}
				else if (left) {
					down = 1;
					up = 0, left = 0, right = 0;
				}
				else if (up) {
					left = 1;
					up = 0, down = 0, right = 0;
				}
				else if (down) {
					right = 1;
					up = 0, down = 0, left = 0;
				}
			}
			else if (v[count].second == 'D') {
				if (right) {
					down = 1;
					up = 0, left = 0, right = 0;
				}
				else if (left) {
					up = 1;
					down = 0, left = 0, right = 0;
				}
				else if (up) {
					right = 1;
					up = 0, down = 0, left = 0;
				}
				else if (down) {
					left = 1;
					up = 0, down = 0, right = 0;
				}
			}
			count++;
		}


		if (left) {	
			if (y - 1 < 1) break;
			if (board[x][y - 1] == 1) break;

			if (board[x][y - 1] != 'A') {
				board[deque.front().first][deque.front().second] = 0;
				deque.pop_front();
			}
			deque.push_back({ x,y - 1 });
			board[x][y - 1] = 1;
		}
		else if (right) {
			if (y + 1 > N) break;
			if (board[x][y + 1] == 1) break;

			if (board[x][y +1] != 'A') {
				board[deque.front().first][deque.front().second] = 0;
				deque.pop_front();
			}
			deque.push_back({ x,y + 1 });
			board[x][y + 1] = 1;
		}
		else if (up) {
			if (x - 1 <1) break;
			if (board[x-1][y] == 1) break;

			if (board[x-1][y] != 'A') {
				board[deque.front().first][deque.front().second] = 0;
				deque.pop_front();
			}
			deque.push_back({ x-1,y });
			board[x - 1][y] = 1;
		}
		else if (down) {
			if (x+1>N) break;
			if (board[x+1][y] == 1) break;

			if (board[x+1][y] != 'A') {
				board[deque.front().first][deque.front().second] = 0;
				deque.pop_front();
			}
			deque.push_back({ x+1,y });
			board[x + 1][y] = 1;
		}
		second++;
	}
	cout << ++second << '\n';
}
