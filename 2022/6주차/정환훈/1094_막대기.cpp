 #include <bits/stdc++.h>
using namespace std;

int x;

void input() {
	cin >> x;
}

void solve() {
	int start = 128;
	int goal = 0;
	int answer = 0;
	while (start > 0) {
		int q = start / 2;
		start /= 2;
		if (goal + q <= x) {
			goal += q;
			answer++;
		}
		if (goal == x) {
			cout << answer;
			return;
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();

	return 0;
}	