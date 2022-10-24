#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[10000000];
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
	for(int i=1;i<=n;i++){
		int k = v[i-1];
		dp[k] = dp[k-1] + 1;
		ans = max(ans, dp[k]);
	}
	cout << n - ans;
}
int main(){
	input();
	solve();
	return 0;
}
