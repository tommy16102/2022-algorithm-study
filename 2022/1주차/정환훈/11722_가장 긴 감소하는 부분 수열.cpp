#include <bits/stdc++.h>
using namespace std;

int nums[1000];
int dp[1000];
int n;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		dp[i] = 1;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[i] > nums[j]) {
				dp[j] = max(dp[i] + 1, dp[j]); // max(i번째까지의 수열 최대 길이 + 1, 그냥 j번째까지의 최대 길이)
			}
		}
	}

	int answer = dp[0]; // dp의 최댓값 구하기
	for (int i = 0; i < n; i++) {
		if (answer < dp[i])
			answer = dp[i];
	}

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}