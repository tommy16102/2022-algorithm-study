/*******************************************************************
Algorithm Study
Baekjoon OJ DP
2631 줄세우기
2022/02/14 이호준
# 아이디어
1. 순서대로 줄세우기 위해 최단횟수로 줄을 바꿔야한다.
가장 긴 증가 부분 수열길이를 구하고 나머지는 순서를 변경하면되기 때문에
최대 증가 부분수열의 길이를 구한다.
*******************************************************************/
#include <iostream>

using namespace std;

#define MAX 201
int input[MAX];
int dp[MAX];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int max_length = 0;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	// 최대 증가 부분 수열 구하기
	for (int i = 0; i <= n; i++) {
		dp[i] = 1;
		int current = input[i];
		for (int j = 0; j < i; j++) {
			if (current > input[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max_length) {
			max_length = dp[i];
		}
	}

	/*for (int i = 0; i <= n; i++) {
		cout << dp[i] << "\n";
	}*/

	cout << n - max_length;

	return 0;
}