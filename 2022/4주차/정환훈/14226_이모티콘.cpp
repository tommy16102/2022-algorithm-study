#include <bits/stdc++.h>
using namespace std;
int s;
int dp[1001];
void input() {
	cin >> s;
	
	for(int i=1;i<=1000;i++){
		dp[i] = 11001100;
	}
}

void solve() {

	/*
		1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		3. 화면에 있는 이모티콘 중 하나를 삭제한다.	
	*/

	dp[1] = 0;
	dp[2] = 2; // 12
	dp[3] = 3; // 122

	for (int i = 4; i <= 1000; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if (i % j == 0) { // 현재 수의 약수를 찾으면
				dp[i] = min(dp[i], dp[j] + (i / j)); // 약수 만들기까지의 연산수 + i/j(복사+붙여넣기 연산수)
			}
		}
		for (int k = i + 1; k <= i + 10; k++) { // 삭제해야 하는 경우 현재 수 + 10까지 살펴봄
			for (int j = 1; j <= k / 2; j++) {
				if ((k) % j == 0) {
					dp[i] = min(dp[i], dp[j] + ((k) / j) + (k-i)); // 약수 만들기까지의 연산수 + i/j(복붙연산수) + k-i(삭제연산수)
				}
			}
		}
	}
	cout << dp[s];

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}