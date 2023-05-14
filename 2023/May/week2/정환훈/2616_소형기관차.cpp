#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n; vector<int> v; int m;
int dp[4][50505];
vector<int> sum;
void input(){
	cin >> n;
	sum = vector<int>(n+1);
	int tmp;
	for(int i=1;i<=n;i++){
		cin >> tmp;
		sum[i] = sum[i-1] + tmp;
	}
	cin >> m;
}
void solve(){
	for(int i=1;i<=3;i++){
		for(int j=i*m;j<=n;j++){
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + sum[j] - sum[j-m]);
		}
	}
	cout << dp[3][n];
}
int main(){
	
	input();
	solve();
	return 0;
}
