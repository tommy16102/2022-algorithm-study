#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int board[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) // 집
				homes.push_back({ i,j });
			if (board[i][j] == 2) // 치킨집
				chickens.push_back({ i,j });
		}
	}
}

int calc(vector<pair<int, int>>& chicks) { // 주어진 치킨집 좌표에 대해 치킨 거리 계산
	
	int d = 0;
	for (int i = 0; i < homes.size(); i++) { // 모든 집들에 대해
		int ds = 111110;
		for (int j = 0; j < chicks.size(); j++) { // 해당 치킨집들 중 거리 최솟값 구함
			int dy = abs(chicks[j].first - homes[i].first);
			int dx = abs(chicks[j].second - homes[i].second);
			ds = min(ds, dy + dx);
		}
		d += ds; // 총합 구함(치킨 거리)
	}
	return d;
}

void solve() {
	vector<int> test;
	for (int i = 0; i < chickens.size() - m; i++) { // 폐업함
		test.push_back(0);
	}
	for (int i = 0; i < m; i++) { // 살아남음
		test.push_back(1);
	}

	int t = 1000000;
	do {
		vector<pair<int, int>> temp; // nCr로 선택된 치킨집
		for (int i = 0; i < test.size(); i++) {
			if (test[i]) { // 조합에 선택되면 temp 벡터에 해당 치킨집 추가
				temp.push_back(chickens[i]);
			}
		}
		t = min(t, calc(temp)); // 거리 최솟값 구하기
	} while (next_permutation(test.begin(), test.end())); // nCr
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