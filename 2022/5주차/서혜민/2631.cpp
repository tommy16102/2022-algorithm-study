#include <iostream>
#include <algorithm>
using namespace std;

/*

2022.2.13

입력받은 수들 중 가장 긴 증가하는 수열에 포함되어 있지 않은 수만 옮기면 해결.

*/

int line[200];
int dp[200];

int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) cin >> line[i];

	for (int i = 0;i < N;i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = i+1;j < N;j++) {
			if (line[j] > line[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	cout << N - *max_element(dp, dp + N) << '\n';
}
