#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
char board[1010][1010];
int p[1000001];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 1000001; i++) {
		p[i] = i;
	}
}

int findParent(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = findParent(p[x]);
}

void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b)
		return;
	p[b] = a;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'U') {
				merge(i * m + j, i*m + j - m);
			}
			if (board[i][j] == 'D') {
				merge(i * m + j, i * m + j + m);
			}
			if (board[i][j] == 'L') {
				merge(i * m + j, i * m + j - 1);
			}
			if (board[i][j] == 'R') {
				merge(i * m + j, i * m + j + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n * m; i++) {
		if (p[i] == i)
			ans++;
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	
	return 0;
}
