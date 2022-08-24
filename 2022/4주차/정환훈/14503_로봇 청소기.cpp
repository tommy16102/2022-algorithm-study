#include <bits/stdc++.h>
using namespace std;
int n; int m;
int sr; int sc;
int dir;
int chart[51][51];
bool v[51][51];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void input() {
	cin >> n >> m;
	cin >> sr >> sc >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chart[i][j];
		}
	}
}

void solve() {
	int r = sr; int c = sc;
	int ans = 0;
	while (1) {

		if (!v[r][c]) {
			v[r][c] = true;
			ans++;
		}

		// 0123 북동남서
		int nr = r; int nc = c;
		bool cleared[4] = { false,false,false,false };

		for (int i = 0; i < 4; i++) {
			nr = r + dx[i];
			nc = c + dy[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && (v[nr][nc] || chart[nr][nc] == 1)) {
				cleared[i] = true;
			}
		}

		nr = r; nc = c;

		if (cleared[0] && cleared[1] && cleared[2] && cleared[3]) { // 네 방향 모두 청소됨
			dir = dir; // 바라보는 방향 유지
			int back = (dir + 2) % 4; // 뒷방향
			switch (back) { // 후진
			case 0:
				nr = r - 1;
				break;
			case 1:
				nc = c + 1;
				break;
			case 2:
				nr = r + 1;
				break;
			case 3:
				nc = c - 1;
				break;
			}
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && chart[nr][nc] == 0) { // 후진 가능
				r = nr; c = nc;
			}
			else {
				cout << ans;
				return;
			}
		}

		else {
			int left = (dir + 3) % 4;
			dir = left; // 왼쪽으로 회전 한 후
			switch (dir) {
			case 0:
				nr = r - 1;
				break;
			case 1:
				nc = c + 1;
				break;
			case 2:
				nr = r + 1;
				break;
			case 3:
				nc = c - 1;
				break;
			}

			if (nr >= 0 && nr < n && nc >= 0 && nc < m && !v[nr][nc] && chart[nr][nc] == 0) { // 왼쪽 청소 가능
				r = nr; // 한칸 전진
				c = nc;
			}

			else { // 왼쪽 청소 불가능
				// 아무것도 안함
			}

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