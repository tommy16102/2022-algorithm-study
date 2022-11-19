#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cost[1010][3];
int dp[1010][3];
void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin >> cost[i][j];
		}
	}
}
void solve(){
	int ans = 987654321;
	for(int first = 0;first<3;first++){				
			for(int i=0;i<3;i++){
				if(i == first){
					dp[1][i] = cost[1][i];
				}
				else{
					dp[1][i] = 987654321;
				}
			}
			for(int i=2;i<=n;i++){
				dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];	
			}							
		for(int i=0;i<3;i++){
			if(i != first){
				ans = min(ans, dp[n][i]);
			}
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}

