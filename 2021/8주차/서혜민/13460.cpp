#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*

2021.09.03 서혜민

13459와 같은 방법으로 진행한 뒤, 이동한 횟수를 출력.

*/

string board[10];
bool visited[10][10][10][10];
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0;i < N;i++) cin >> board[i];

	int rx = -1, ry, bx = -1, by;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (rx >= 0 && bx >= 0) break;
			if (board[i][j] == 'R') {
				rx = i; ry = j;
			}
			if (board[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	queue<pair<int, int>> rqueue;
	queue<pair<int, int>> bqueue;
	rqueue.push({ rx, ry });
	bqueue.push({ bx, by });
	visited[rx][ry][bx][by] = 1;
	int count = 0;

	while (!rqueue.empty()) {
		int size = rqueue.size();
		while (size--) {
			int rx = rqueue.front().first;
			int ry = rqueue.front().second;
			int bx = bqueue.front().first;
			int by = bqueue.front().second;
			if (board[rx][ry] == 'O' && board[bx][by] != 'O') {
				cout << count << endl;
				return 0;
			}
			rqueue.pop();
			bqueue.pop();

			for (int i = 0;i < 4;i++) {
				int newrx = rx;
				int newry = ry;
				int newbx = bx;
				int newby = by;

				int rcount = 0, bcount = 0;
				while (board[newrx + moveX[i]][newry + moveY[i]] != '#' && board[newrx][newry] != 'O') {
					newrx += moveX[i];
					newry += moveY[i];
					rcount++;
				}

				while (board[newbx + moveX[i]][newby + moveY[i]] != '#' && board[newbx][newby] != 'O') {
					newbx += moveX[i];
					newby += moveY[i];
					bcount++;
				}
				if (board[newbx][newby] == 'O') continue;

				if (newrx == newbx && newry == newby) {
					if (rcount > bcount) {
						newrx -= moveX[i];
						newry -= moveY[i];
					}
					else {
						newbx -= moveX[i];
						newby -= moveY[i];
					}
				}
				if (!visited[newrx][newry][newbx][newby]) {
					rqueue.push({ newrx,newry });
					bqueue.push({ newbx,newby });
					visited[newrx][newry][newbx][newby] = 1;
				}
			}
		}
		count++;
		if (count > 10) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
