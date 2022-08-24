#include <bits/stdc++.h>
using namespace std;

int n;
char board[64][64];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void check(int i, int j, int depth) {

	if (depth == 0) {
		cout << board[i][j];
		return;
	}

	int size = pow(2, depth);
	bool cut = false;
	for (int a = i; a < i + size; a++) {
		for (int b = j; b < j + size; b++) {
			if (a >= n || b >= n || board[i][j] != board[a][b]) {
				cut = true;
				break;
			}
		}
		if (cut) break;
	}

	if (cut) {
		cout << "(";
		check(i, j, depth - 1);
		check(i, j + size/2, depth - 1);
		check(i + size/2, j, depth - 1);
		check(i + size/2, j + size/2, depth - 1);
		cout << ")";
	}
	else
		cout << board[i][j];
}


void solve() {
	int sq = 0; int temp = n;
	while (temp) {
		temp = temp / 2;
		sq++;
	}
	sq--;
	check(0, 0, sq);
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}