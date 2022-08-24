#include <bits/stdc++.h>
using namespace std;

int n;
int cost[2000000];
int reward[2000000];
int dp[2000000];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		cin >> reward[i];
	}
}

void solve() {

	// dp[7] = dp[2] + reward[2] or dp[5] + reward[5]
	// cost[i] 의 제한이 1~50이므로, 정직하게 50일 전까지의 모든 경우를 탐색해낸다

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 50; j >= 1; j--) {
			if (i - j >= 1) { // 배열 인덱스 검사
				if (i - cost[i - j] == i - j) { // 상담 하기 이전 dp로 점프
					//cout << "i : " << i << " j : " << j << "   "; cout << dp[i - j] << " + " << reward[i - j] << endl;
					// max(상담 시작날까지 최댓값 + 해당 상담의 보상, 그냥 지금 최댓값)
					dp[i] = max(dp[i - j] + reward[i - j], dp[i]);
				}
			}
			else { // 배열 인덱스를 넘어가면 그냥 전날 최댓값 이어감
				dp[i] = dp[i - 1];
			}
		}
	}

	cout << dp[n + 1];


}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}