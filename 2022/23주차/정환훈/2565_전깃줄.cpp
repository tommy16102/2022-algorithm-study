#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dp[102];
vector<pair<int,int>> v;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int from; int to;
		cin >> from >> to;
		v.push_back({from, to});
	}
	
}
void solve(){
	sort(v.begin(), v.end());
	// answer = n - max(LIVE)
	// LIS = max(LIVE)
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(v[i].second > v[j].second){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int lis = 0;
	for(int i=0;i<n;i++){
		lis = max(lis, dp[i]);
	}
	cout << n - lis;
}
int main(){
	input();
	solve();
	return 0;
}
