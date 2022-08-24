#include <bits/stdc++.h>
using namespace std;
char m[1002][1002];
bool v[1002][1002];
bool used[1002][1002];
int r; int c;
pair<int, int> start;
pair<int, int> fstart;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void input() {

	for (int i = 0; i <= 1001; i++) { // 가장자리(탈출) = 'x'로 표시
		for (int j = 0; j <= 1001; j++) {
			m[i][j] = 'x';
		}
	}

	cin >> r >> c;	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'J') { // 시작지점
				start = { i,j };
			}
			if (m[i][j] == 'F') { // 불 시작지점
				fstart = { i,j };
			}
		}
	}
}

void print() { // 디버깅용 출력
	cout << "==========================\n";
	for (int i = 0; i <= r+1; i++) {
		for (int j = 0; j <= c+1; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "==========================\n";
}


void solve() {
	queue<pair<int, int>> q;
	pair<int, int> f = fstart;

	q.push(start);
	v[start.first][start.second] = true;
	int tries = 0;

	// 불 퍼뜨림
	// J 이동

	while (!q.empty()) {
		queue<pair<int, int>> fq; // 현재 위치에서 새롭게 생긴 불 좌표들 목록
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (m[i][j] == 'F' && !used[i][j]) { // 새롭게 생긴 불일 경우
					fq.push({ i,j });
					used[i][j] = true;
				}
			}
		}

		int fs = fq.size(); // 새롭게 생긴 불들을 bfs로 퍼뜨림
		for (int i = 0; i < fs; i++) {
			pair<int, int> nowf = fq.front();
			int fx = nowf.first;
			int fy = nowf.second;
			fq.pop();
			for (int k = 0; k < 4; k++) {
				int nfx = fx + dx[k];
				int nfy = fy + dy[k];
				if (m[nfx][nfy] == '.' || m[nfx][nfy] == 'J') {
					m[nfx][nfy] = 'F';
				}
			}
		}

		//print();

		int s = q.size(); // 현재 J가 이동 가능한 가짓수
		tries++;
		for (int i = 0; i < s; i++) { // bfs
			pair<int, int> now = q.front();
			int x = now.first;
			int y = now.second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (m[nx][ny] == 'x') { // 골 도착
					cout << tries;
					return;
				}
				if ((m[nx][ny] == '.' || m[nx][ny] == 'J') && !v[nx][ny]) { // 이동
					m[nx][ny] = 'J';
					q.push({ nx,ny });
					v[nx][ny] = true;
				}
			}
		}
		//print();
	}
	// 도착 못한 경우
	cout << "IMPOSSIBLE";
	// 검사
	// 불 이동
	// J 이동
	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}