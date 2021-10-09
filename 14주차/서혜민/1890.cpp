#include <iostream>
using namespace std;

/*

dp배열 시작점 1로 초기화 후, 이중 포문을 통해 갈 수 있는 지점 dp배열 내 기존 값에 해당 기준 값 더해주면서 [N][N]까지 진행. 

*/

long long int arr[101][101];
long long int dp[101][101];

int main() {
	int N;
	cin >> N;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == N && j == N) {
				cout << dp[N][N] << endl;
				return 0;
			}
			if (dp[i][j]) {
				int val = arr[i][j];
				if (i + val <= N) dp[i + val][j] += dp[i][j];
				if (j + val <= N) dp[i][j + val] += dp[i][j];
			}
		}
	}
}