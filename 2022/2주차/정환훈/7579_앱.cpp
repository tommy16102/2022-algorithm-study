#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int mem[101];
int cost[101];
int dp[10001];
int sum;


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mem[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
}

void solve() { 
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]); //현재 cost에서 최대로 확보할수있는 메모리
		}
	}

	int i = 0;
	for(;i<sum && dp[i]<m;i++){}
	cout << i << endl;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}