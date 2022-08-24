#include <bits/stdc++.h>
using namespace std;


int n; int m;
int x; int y;
int board[25][25];
int k;
vector<int> cmd;
void input() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		cmd.push_back(c);
	}
}

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로
pair<int, int> dir[5] = { { 0,0 }, { 0,1 }, { 0,-1 }, { -1,0 }, { 1,0 } };

int up = 0; int down = 0; int left = 0; int right = 0; int front = 0; int back = 0;

void solve() {

	for (int i = 0; i < cmd.size(); i++) {
		int ny = y + dir[cmd[i]].first;
		int nx = x + dir[cmd[i]].second;
		if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
			y = ny; x = nx;

			switch (cmd[i]) {

			case 1: {// up->right right->down down->left left->up
				int temp = up;
				up = ::left;
				::left = down;
				down = ::right;
				::right = temp;
				break;
			}
			case 2: {
				int temp = up;;
				up = ::right;
				::right = down;
				down = ::left;
				::left = temp;;
				break; // up->left left->down down->right right->up
			}
			case 3: { // up->back back->down down->front front->up
				int temp = up;
				up = front;
				front = down;
				down = back;
				back = temp;
				break; 
			}
			case 4: { // up->front front->down down->back back->up
				int temp = up;
				up = back;
				back = down;
				down = front;
				front = temp;
				break;
			}
			}


			if (board[y][x] == 0) { // 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
				board[y][x] = down;
			}
			else { // 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
				down = board[y][x];
				board[y][x] = 0;
			}
			cout << up << '\n';
		}
	}

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();	


	return 0;
}