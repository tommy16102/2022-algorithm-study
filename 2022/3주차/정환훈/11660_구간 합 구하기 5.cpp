#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int table[1025][1025];
vector<pair<int, int>> x1y1;
vector<pair<int, int>> x2y2;
int garosum[1025][1025];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x1; int y1; int x2; int y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		x1y1.push_back({ x1,y1 });
		x2y2.push_back({ x2,y2 });
	}
}


void solve() {

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) { // 가로합 채우기 garosum[1][3] = 1행에서 3열까지의 합
			sum += table[i][j];
			garosum[i][j] = sum;
		}
	}

	for (int i = 0; i < x1y1.size(); i++) {
		int x1 = x1y1[i].first;
		int y1 = x1y1[i].second;
		int x2 = x2y2[i].first;
		int y2 = x2y2[i].second;
		int sum = 0;
		for (int j = x1; j <= x2; j++) { // 가로마다 dp식으로 더해줌
			sum += garosum[j][y2] - garosum[j][y1 - 1];
		}
		cout << sum << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}