#include <bits/stdc++.h>
using namespace std;
int n;
int m[30][30];
int st = 0;
bool v[30][30];
int ssize = 2;
pair<int, int> start;

// 상좌우하로 했는데 사실 그딴거 필요없었음 아무방향으로해도됨
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				start = { i,j };
				m[i][j] = 0;
			}
		}
	}
}

bool check() { // 먹을거 있는지 판단
	
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = false;
			if (m[i][j] != 0 && ssize > m[i][j]) {
				flag = true;
			}
		}
	}
	return flag;
}

void print() {
	cout << "=================== size : " << ssize <<  "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===================\n";
}

void solve() {
	int t = 0;
	pair<int, int> spos = start;

	while (check()) { // 먹을수 있는게 있으면 진행
		vector<pair<pair<int, int>, int>> targets; // 거리가 같은 타겟들
		queue<pair<pair<int, int>, int>> q; // bfs를 위한 아기상어 움직임 큐
		q.push({ { spos.first, spos.second } , 0 });

		while (!q.empty()) { 
			int qsize = q.size(); // 새로생긴 움직임 확인
			for (int j = 0; j < qsize; j++) {
				pair<int, int> now = q.front().first;
				int level = q.front().second;
				q.pop();
				int x = now.first;
				int y = now.second;
				for (int i = 0; i < 4; i++) { // bfs
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && !v[nx][ny]) {
						if (m[nx][ny] == 0) { // 지나갈수있음
							v[nx][ny] = true;
							q.push({ { nx,ny } ,level + 1 });
						}
						else if (ssize == m[nx][ny]) { // 동렙(지나갈수만있음)
							v[nx][ny] = true;
							q.push({ { nx,ny } ,level + 1 });
						}
						else if (ssize >= m[nx][ny]) { // 잡아먹을수있는 타겟들
							targets.push_back({ { nx,ny }, level });
							v[nx][ny] = true;
						}
					}
				}
			}
			if (targets.size() >= 1) { // 현재 범위에서 먹을 게 존재하면
				while (!q.empty()) { // 큐 비우고 나가기
					q.pop();
				}
			}
		}

		if (targets.empty()) { // 먹을게없어
			break;
		}
		vector<pair<pair<int, int>, int>> lowers;
		int lowerx = targets[0].first.first;
		int lowerxid = 0; // 맨위 확인

		for (int i = 0; i < targets.size(); i++) {
			if (lowerx > targets[i].first.first) {
				lowerx = targets[i].first.first;
				lowerxid = i;
			}
		}

		for (int i = 0; i < targets.size(); i++) {
			if (lowerx == targets[i].first.first) {
				lowers.push_back(targets[i]);
			}
		}

		if (lowers.size() == 1) {
			int nx = lowers[0].first.first;
			int ny = lowers[0].first.second;
			int level = lowers[0].second;
			m[nx][ny] = 0;
			t += level + 1;
			st++; // 크기 스택
			spos = { nx,ny }; // 위치 이동
			if (st == ssize) {
				ssize++;
				st = 0;
			}
		}
		else {  // 맨위가 둘이상 -> 맨왼쪽 확인
			int lowery = lowers[0].first.second;
			int loweryid = 0;
			for (int i = 0; i < lowers.size(); i++) {
				if (lowery > lowers[i].first.second) {
					lowery = lowers[i].first.second;
					loweryid = i;
				}
			}

			int nx = lowers[loweryid].first.first;
			int ny = lowers[loweryid].first.second;
			int level = lowers[loweryid].second;
			m[nx][ny] = 0;
			t += level + 1;
			st++;
			spos = { nx,ny };
			if (st == ssize) {
				ssize++;
				st = 0;
			}

		}

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