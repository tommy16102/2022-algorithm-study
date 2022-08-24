#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
int board[101][101];
int calc[101][101];
bool used[101][101];

void print() {
	cout << "======================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";

		}
		cout << endl;
	}
	cout << "======================\n";
}

vector<int> up() {
	for (int i = 1; i < n; i++) { // 맨위 +1행부터
		for (int j = 0; j < n; j++) { // 열

			// board[i][j] = 현재 검사하는 위치
			// board[k][j] = 숫자 처음 발견하는 위치(합쳐지는 위치)
			if (board[i][j] == 0)
				continue;


			int k = i - 1; // 윗쪽 처음 숫자 만난 행

			while (k >= 0 && board[k][j] == 0) { // 숫자 발견할때까지 올라감
				k--;
			}
			if (k == -1) { // 그 위에 숫자가 없음
				board[0][j] = board[i][j];
				board[i][j] = 0;
			}
			
			else { // 숫자 있음
				if (board[k][j] == board[i][j] && !used[k][j]) { // 동일한 숫자 합침
					board[k][j] *= 2;
					board[i][j] = 0;
					used[k][j] = true;
				}
				else { // 다른 숫자, 아래 있던 숫자 위로 당김
					if (k != i - 1) {
						board[k + 1][j] = board[i][j];
						board[i][j] = 0;
					}
					
				}
			}
		}
	}

	vector<int> state;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			state.push_back(board[i][j]);
			used[i][j] = false;
		}
	}

	return state;
}

vector<int> down() {

	for (int i = n - 2; i >= 0; i--) { // 맨 아래-1 행부터
		for (int j = 0; j < n; j++) { // 열

			// board[i][j] = 현재 검사하는 위치
			// board[k][j] = 숫자 처음 발견하는 위치(합쳐지는 위치)
			if (board[i][j] == 0)
				continue;

			int k = i + 1; // 아랫쪽 처음 숫자 만난 행

			while (k < n && board[k][j] == 0) { // 숫자 발견할때까지 내려감
				k++;
			}
			if (k == n) { // 그 아래 숫자가 없음
				board[n - 1][j] = board[i][j];
				board[i][j] = 0;
			}
			else { // 숫자 있음
				if (board[k][j] == board[i][j] && !used[k][j]) { // 동일한 숫자 합침
					board[k][j] *= 2;
					board[i][j] = 0;
					used[k][j] = true;
				}
				else { // 다른 숫자, 아래 있던 숫자 위로 당김
					if (k != i + 1) {
						board[k - 1][j] = board[i][j];
						board[i][j] = 0;
					}

				}
			}
		}
	}


	vector<int> state;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			state.push_back(board[i][j]);
			used[i][j] = false;
		}
	}

	return state;

}

vector<int> left() {
	for (int i = 0; i < n; i++) { // 행
		for (int j = 1; j < n; j++) { // 열
			// board[i][j] = 현재 검사하는 위치
			// board[i][k] = 숫자 처음 발견하는 위치(합쳐지는 위치)
			if (board[i][j] == 0)
				continue;

			int k = j - 1; // 왼쪽 처음 숫자 만난 행

			while (k >= 0 && board[i][k] == 0) { // 숫자 발견할때까지 왼쪽감
				k--;
			}

			if (k == -1) { // 그 왼쪽 숫자가 없음
				board[i][0] = board[i][j];
				board[i][j] = 0;
			}
			else { // 숫자 있음
				if (board[i][k] == board[i][j] && !used[i][k]) { // 동일한 숫자 합침
					board[i][k] *= 2;
					board[i][j] = 0;
					used[i][k] = true;
				}
				else { // 다른 숫자, 아래 있던 숫자 위로 당김
					if (k != j - 1) {
						board[i][k + 1] = board[i][j];
						board[i][j] = 0;
					}

				}
			}
		}
	}
	vector<int> state;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			state.push_back(board[i][j]);
			used[i][j] = false;
		}
	}

	return state;
}

vector<int> right() {
	for (int i = 0; i < n; i++) { // 행
		for (int j = n - 2; j >= 0; j--) { // 열
			// board[i][j] = 현재 검사하는 위치
			// board[i][k] = 숫자 처음 발견하는 위치(합쳐지는 위치)
			if (board[i][j] == 0)
				continue;

			int k = j + 1; // 오른쪽 처음 숫자 만난 행

			while (k < n && board[i][k] == 0) { // 숫자 발견할때까지 우로감
				k++;
			}
			if (k == n) { // 그 오른쪽 숫자가 없음 우측 끝으로 옮겨짐
				board[i][n - 1] = board[i][j];
				board[i][j] = 0;
			}
			else { // 숫자 있음
				if (board[i][k] == board[i][j] && !used[i][k]) { // 동일한 숫자 합침
					board[i][k] *= 2;
					board[i][j] = 0;
					used[i][k] = true;
				}
				else { // 다른 숫자, 아래 있던 숫자 위로 당김
					if (k != j + 1) {
						board[i][k - 1] = board[i][j];
						board[i][j] = 0;
					}

				}
			}
		}
	}
		vector<int> state;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				state.push_back(board[i][j]);
				used[i][j] = false;
			}
		}
		return state;
}



void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}


void solve() {

	// 현재 숫자 상태 벡터로 기억
	vector<int> state;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			state.push_back(board[i][j]);
		}
	}
	queue<pair<pair<vector<int>, int>, int>> q; // <<숫자상태, tries>, 상하좌우(1234)>

	q.push({ { state, 0 }, -1 });
	while (!q.empty()) {
		vector<int> now = q.front().first.first;
		int tries = q.front().first.second;
		if (tries >= 6) // 5회까지 최댓값
			break;
		q.pop();

		for (int i = 0; i < n; i++) { // 보드에 현재 상태값 복원
			for (int j = 0; j < n; j++) {
				board[i][j] = now[i * n + j];
			}
		}

		for (int i = 0; i < n; i++) { // 최댓값 기억하기 ( 사실 다 끝나고 해도 될 거 같긴 하다 )
			for (int j = 0; j < n; j++) {
				ans = max(board[i][j], ans);
			}
		}


		for (int i = 0; i < 4; i++) {
			vector<int> next_state;
			switch (i) {
			case 0:
				next_state = up();
				q.push({ { next_state, tries + 1 },1 });
				break;
			case 1:
				next_state = left();
				q.push({ { next_state, tries + 1 },2 });
				break;
			case 2:
				next_state = down();
				q.push({ { next_state, tries + 1 },3 });
				break;
			case 3:
				next_state = right();
				q.push({ { next_state, tries + 1 },4 });
				break;
			}
			for (int i = 0; i < n; i++) { // 같은 board 가지고 연산하므로 다시 clear
				for (int j = 0; j < n; j++) {
					board[i][j] = now[n * i + j];
				}
			}
		}
	}



	cout << ans;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}