#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;
int n;
ll v[5050];
ll d[5050][5050];
ll dp[5050];
bool flag = false;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v[i];
		dp[i] = 987654321;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			d[i][j] = (j-i) * (1+abs(v[j] - v[i]));
		}
	}
}
void solve(){
	// dp[3] = d[3][4]
	// dp[2] = min(max(d[2][3], dp[3]), d[2][4])
	// dp[1] = min(max(d[1][2], dp[2]), max(d[1][3], dp[3]), max(d[1][4], dp[4]))
	dp[n-1] = 0;
	dp[n-2] = d[n-2][n-1];
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){			 
			dp[n-i] = min(dp[n-i], max(d[n-i][n-i+j], dp[n-i+j]));	
		}
	}	
	cout << dp[0];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
