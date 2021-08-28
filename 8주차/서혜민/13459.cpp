#include <string>
#include <iostream>
#include <queue>
using namespace std;

/*

2021.09.03 서혜민

먼저 R과 B의 좌표를 찾아내서, r과 b의 좌표를 저장하는 각각의 큐에 삽입 후, 상하좌우로 #을 만나기전까지나, O를 만날때까지 이동을 시켜주면서,
최종 좌표에서의 값이 둘 다 0이라면 continue를 하고, 그렇지 않고 같다면 이동횟수가 더 적은 좌표만 그대로 유지하고, 이동횟수가 큰 좌표는 한번 덜 이동시킨 좌표로 저장한다.
이렇게 bfs를 통해 R만 O를 만나고, B는 O를 만나지 않을때까지 count를 증가시켜가면서 bfs 탐색을 하며 10이 넘어가거나 queue가 비어서 while문을 빠져나오게되면 0을 출력해준다.

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
				if (count <= 10) cout << 1 << endl;
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
				while (board[newrx + moveX[i]][newry + moveY[i]] != '#' && board[newrx][newry]!='O') {
					newrx += moveX[i];
					newry += moveY[i];
					rcount++;
				}

				while (board[newbx + moveX[i]][newby + moveY[i]] != '#' && board[newbx][newby]!='O') {
					newbx += moveX[i];
					newby += moveY[i];
					bcount++;
				}
				if (board[newrx][newry] == 'O' && board[newbx][newby] == 'O') continue;

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
				cout << newrx << " " << newry << " " << newbx << " " << newby << endl;
				if (!visited[newrx][newry][newbx][newby]) {
					rqueue.push({ newrx,newry });
					bqueue.push({ newbx,newby });
					visited[newrx][newry][newbx][newby] = 1;
				}
			}
		}
		count++;
		if (count > 10) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}
