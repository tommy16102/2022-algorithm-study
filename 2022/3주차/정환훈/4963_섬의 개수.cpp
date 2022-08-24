#include <bits/stdc++.h>
using namespace std;
int m[51][51];
bool v[51][51];
int dw[8] = { -1,-1,0,1,1,1,0,-1 };
int dh[8] = { 0,1,1,1,0,-1,-1,-1 };
int w; int h;
bool flag = false;

void clear() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			m[i][j] = 0;
			v[i][j] = false;
		}
	}
}

void input() {
	clear();
	cin >> w >> h;
	if (w == 0 && h == 0) {
		flag = true;
		return;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> m[i][j];
		}
	}
}

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dw[i];
		int ny = y + dh[i];
		if (nx >= 0 && nx < 50 && ny >= 0 && ny < 50) {
			if (!v[nx][ny] && m[nx][ny] == 1) {
				v[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
}

void solve() { 
	int answer = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == 1 && v[i][j] == false) {
				dfs(i, j);
				answer++;
			}
		}
	}
	cout << answer << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		input();
		if (flag)
			break;
		solve();
	}
}