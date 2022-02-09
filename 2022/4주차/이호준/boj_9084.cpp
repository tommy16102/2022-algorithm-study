/*******************************************************************
Algorithm Study
Baekjoon OJ DP
9084 동전
2022/02/08 이호준
# 아이디어
1. DP

동전1과 동일한 로직
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test;

	cin >> test;

	for (int i = 0; i < test; i++) {
		int n;
		
		cin >> n;

		vector<int> coin(n);

		for (int a = 0; a < n; a++) {
			cin >> coin[a];
		}

		int target;

		cin >> target;
		
		dp[0] = 1;

		for (int a = 0; a < n; a++) {
			for (int b = coin[a]; b <= target; b++) {
				dp[b] += dp[b - coin[a]];
			}
		}

		cout << dp[target] << "\n";

		for (int a = 0; a <= target; a++) {
			dp[a] = 0;
		}
		
	}

	return 0;
}

// 1 1 1 1 1 1 1 1 1 1
// 1 2 2 3