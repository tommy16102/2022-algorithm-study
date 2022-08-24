#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int board[3][3];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
vector<int> answer = { 1,2,3,4,5,6,7,8,0 };
unordered_map<string, bool> v; // 해당 상태 방문했는지

void input() {
	string start = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
			start += to_string(board[i][j]);
		}
	}
	v[start] = true; // 시작 상태 방문 체크
}

bool check(vector<int> test) { // 현재 상태가 정답인지 체크
	for (int i = 0; i < test.size(); i++) {
		if (test[i] != answer[i])
			return false;
	}
	return true;
}


void solve() {

	queue<vector<int>> q;
	vector<int> start;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			start.push_back(board[i][j]);
		}
	}
	q.push(start);
	

	int t = -1;
	while (!q.empty()) {
		t++;
		int qsize = q.size();
		for (int j = 0; j < qsize; j++) {
			vector<int> now = q.front();
			pair<int, int> zero; // 0 위치 찾기
			for (int i = 0; i < now.size(); i++) {
				if (now[i] == 0) {
					zero = { i / 3, i % 3 };
				}
			}
			int y = zero.first;
			int x = zero.second;
			q.pop();
			if (check(now)) { // 현재상태 정답
				cout << t;
				return;
			}
			for (int k = 0; k < 4; k++) { // bfs
				int ny = dy[k] + y;
				int nx = dx[k] + x;

				if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3) {
					// (ny,nx)의 위치와 (y,x)의 위치를 바꿈
					vector<int> next = now;
					int temp = next[3 * ny + nx]; // temp = a
					next[3 * ny + nx] = next[3 * y + x]; // a = b
					next[3 * y + x] = temp; // b = temp
					string vtest = "";
					for (int t = 0; t < next.size(); t++) {
						vtest += to_string(next[t]);
					}
					if (!v[vtest]) { // 다음 상태 방문 체크
						q.push(next);
						v[vtest] = true;
					}
				}
			}
		}
	}

	cout << -1;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}