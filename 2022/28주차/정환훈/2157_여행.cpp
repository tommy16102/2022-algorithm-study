#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
vector<pair<int,int>> graphs[302];
int dp[302][302];
void input(){
	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b) continue;
		graphs[a].push_back({b, c});		
	}
}
void solve(){
	for(int i=0;i<graphs[1].size();i++){
		int next = graphs[1][i].first;
		int cost = graphs[1][i].second;
		dp[next][2] = max(dp[next][2], cost);
	}
	for(int i=2;i<=m;i++){
		for(int cur=2;cur<=n;cur++){
			if(dp[cur][i] != 0){
				for(int j=0;j<graphs[cur].size();j++){
					int next = graphs[cur][j].first;
					int cost = graphs[cur][j].second;
					dp[next][i+1] = max(dp[next][i+1], dp[cur][i] + cost);
				}
			}
		}
	}
	int ans = 0;
	for(int i=2;i<=m;i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	
}
int main(){
	input();
	solve();
	return 0;
}
