#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/15
    아이디어 : dfs
*/

int n; // 세로선 몇개?
int m; // 놓을 수 있는 다리 몇개?
int h; // 놓을 수 있는 길 몇개?
bool ladder[11][30];
vector<int> answers;

void input() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int t1; int t2;
		cin >> t1 >> t2;
		ladder[t2][t1] = true;
	}
}



bool test() {

	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[now][j] == true) {
				now++;
			}
			else if (ladder[now - 1][j] == true) {
				now--;
			}
		}

		if (now != i) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {

	if (cnt >= 4) return;

	if (test()) {
		answers.push_back(cnt);
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[j][i] == true) continue;
			if (ladder[j - 1][i] == true) continue;
			if (ladder[j + 1][i] == true) continue;

			ladder[j][i] = true;
			dfs(i, cnt + 1);
			ladder[j][i] = false;
		}
	}


}

void solve() {

	dfs(1, 0);


	if (answers.empty()) {
		cout << -1;
		return;
	}
	sort(answers.begin(), answers.end());
	cout << answers[0];
	

}

int main() {

	input();
	solve();

	return 0;
}