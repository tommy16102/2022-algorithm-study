#include <bits/stdc++.h>
using namespace std;

int n;
int board[126][126];
bool v[126][126];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int t = 0;

void input() {

	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			board[i][j] = 0;
			v[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}


void solve() {

	// 도착점에서 상하좌우 살피면서 탐색할건데,
	// 상하좌우 가능성 중 현재 cost가 가장 작은 좌표를 골라 탐색.
	// 방문처리 해준 후, pq에서 0,0 좌표가 뽑히면 해당 pair의 cost 출력


	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
	// {cost, {y, x}}
	pq.push({ board[n - 1][n - 1],{n - 1,n - 1} });
	v[n - 1][n - 1] = true;
	while (!pq.empty()) {
		pair<int,pair<int,int>> now = pq.top();
		int now_cost = now.first;
		int now_y = now.second.first;
		int now_x = now.second.second;
		pq.pop();
		if (now_y == 0 && now_x == 0) {
			cout << "Problem " << t << ": " << now_cost << '\n';
		}
		for (int i = 0; i < 4; i++) {
			int ny = now_y + dy[i];
			int nx = now_x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !v[ny][nx]) {
				int next_cost = now_cost + board[ny][nx];
				v[ny][nx] = true;
				pq.push({ next_cost,{ny,nx} });
			}
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	while (true) {
		cin >> n;
		if (n == 0)
			break;
		t++;
		input();
		solve();
	}

	return 0;
}