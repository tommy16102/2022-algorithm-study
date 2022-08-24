#include <bits/stdc++.h>
using namespace std;

int n;
int k;

void input() {
	cin >> n >> k;
}


int one_bit(int x) {
	int bit1 = 0;
	while (x > 0) { // 16
		if (x % 2 == 0) {
			x /= 2;
		}
		else {
			bit1++;
			x /= 2;
		}
	}
	return bit1;
}

void solve() {
	int i = n;
	while (one_bit(i) > k) {
		i++;
	}
	cout << i - n;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}