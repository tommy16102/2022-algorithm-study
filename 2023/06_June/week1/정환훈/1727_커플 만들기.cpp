#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
int dp[1010][1010];
vector<int> mv;
vector<int> gv;
void input(){
	cin >> n >> m;
	mv = vector<int>(n);
	gv = vector<int>(m);
	for(int i=0;i<n;i++){
		cin >> mv[i];		
	}
	for(int i=0;i<m;i++){
		cin >> gv[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = 987654321;
		}
	}
}
void solve(){
	sort(mv.begin(), mv.end());
	sort(gv.begin(), gv.end());
	dp[0][0] = abs(mv[0] - gv[0]);
	for(int i=1;i<gv.size();i++){
		dp[0][i] = min(dp[0][i-1], abs(mv[0] - gv[i]));
	}
	for(int i=1;i<mv.size();i++){
		dp[i][0] = min(dp[i-1][0], abs(mv[i] - gv[0]));
	}
	for(int i=1;i<mv.size();i++){
		for(int j=1;j<gv.size();j++){
			if(i == j){
				dp[i][j] = dp[i-1][j-1] + abs(mv[i] - gv[i]);
			}
			else if(i > j){
				dp[i][j] = min(dp[i-1][j-1] + abs(mv[i]-gv[j]), dp[i-1][j]);
			}
			else{
				dp[i][j] = min(dp[i-1][j-1] + abs(mv[i]-gv[j]), dp[i][j-1]);
			}
		}
	}	
	cout << dp[n-1][m-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}	
