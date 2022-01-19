#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX = 101;

int now[MAX];
int cost[MAX];
int dp[10000000];

int main() {
	int N, M;
	int sum = 0;
	int ans = INT_MAX;
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> now[i];
	}

	for (int i = 0;i < N;i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0;i < N;i++) {
		for (int j = sum;j >= cost[i];j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + now[i]);
			if (dp[j] >= M && j < ans) ans = j;	
		}
	}
	cout << ans << '\n';
