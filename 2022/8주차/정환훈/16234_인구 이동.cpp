#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n; int l; int r;
int board[101][101];
int area[101][101];
bool v[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void print() {
	cout << "===================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "===================\n";
}

bool check() {

	for (int i = 0; i < n; i++) { // 검사하면서 항상 초기화
		for (int j = 0; j < n; j++) {
			area[i][j] = 0;
			v[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) { // 국경 열릴 곳 있는지 탐색
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
					int gap = abs(board[ny][nx] - board[i][j]);
					if (gap >= l && gap <= r) {
						return true;
					}
				}
			}
		}
	}

	return false;
}


void bfs(int i, int j, int a) { // bfs로 각각 영역에 숫자 붙이기
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		int y = now.first;
		int x = now.second;
		area[y][x] = a;
		v[y][x] = true;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !v[ny][nx]) {
				int gap = abs(board[ny][nx] - board[y][x]);
				if (gap >= l && gap <= r) {
					q.push({ ny,nx });
					v[ny][nx] = true;
				}
			}
		}
	}
}

void solve() {
	int t = 0;
	//print();
	while (check()) {
		t++;
		int a = 1;

		for (int i = 0; i < n; i++) { // 111 222 3333 영역 표시
			for (int j = 0; j < n; j++) {
				if (area[i][j] == 0 && !v[i][j]) {
					bfs(i, j, a);
					a++;
				}
			}
		}

		vector<pair<int, int>> pos[2501]; // 최대 50*50
		int sum[2501];
		for (int i = 0; i < 2500; i++) {
			sum[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum[area[i][j]] += board[i][j]; // 인구 총합
				pos[area[i][j]].push_back({ i,j }); // 해당 국가 좌표
			}
		}
		for (int i = 1; i < 2501; i++) { // area : 1 ~ 2500
			for (int j = 0; j < pos[i].size(); j++) {
				board[pos[i][j].first][pos[i][j].second] = sum[i] / pos[i].size();
			}
		}
		//print();
	}
	cout << t;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}