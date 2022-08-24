#include <bits/stdc++.h>
using namespace std;

int n;
int love[401][4];
int pos[21][21];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
vector<int> students;
void input() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int who;
		cin >> who;
		students.push_back(who);
		for (int j = 0; j < 4; j++) {
			cin >> love[who][j];
		}
	}
}

int calc(int i, int j, int who) {
	int lovers = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			for (int x = 0; x < 4; x++) {
				if (love[who][x] == pos[ni][nj]) {
					lovers++;
				}
			}
		}
	}
	if (lovers == 0) return 0;
	return pow(10, lovers - 1);
}

void solve() {


	for (int i = 0; i < students.size(); i++) {
		int now = students[i];
		/*
			1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
			2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
			3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
		*/
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += calc(i, j, pos[i][j]);
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