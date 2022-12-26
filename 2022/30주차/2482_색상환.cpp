#include <iostream>
using namespace std;
typedef long long ll;
int n, k;
int dp[1001][1001];
const int MOD = 1000000003;
void input(){
	cin >> n >> k;
}
void solve(){
	
	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=2;j<=i/2;j++){
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}
	
	cout << dp[n][k];
}
int main(){
	input();
	solve();
	return 0;
}
