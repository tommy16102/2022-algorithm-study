#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[100001];

void input() {
	cin >> n;
}

/*
	즉, 현재 우리에서 사자가 있는 우리와 없는 우리로 분리한 뒤 빈 우리의 수 × 3 + 사자가 있는 우리 × 2 를 하면 되는 것이다.
	즉, 점화식은 다음과 같다.
	dp[i] = (dp[i-2]*3 + (dp[i-1]-dp[i-2])*2)
	위 점화식을 풀어서 정리하면 다음과 같다.
	dp[i] = (dp[i-2] + dp[i-1]*2)
*/

void solve() {
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= 100000; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	cout << dp[n];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}