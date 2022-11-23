#include <iostream>
#include <vector>
using namespace std;
int n;
int dp[2][1010];
vector<int> v;
void input(){
	cin >> n;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}

void solve(){
	int ans = 0;	
	for(int i=0;i<n;i++){
		dp[0][i] = 1;
		for(int j=0;j<i;j++){
			if(v[i] > v[j]){
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		dp[1][i] = 1;
		for(int j=n-1;j>i;j--){
			if(v[i] > v[j]){
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		ans = max(ans, dp[0][i] + dp[1][i]);
	}	
	cout << ans - 1;
}

int main(){
	input();
	solve();
	return 0;
}
