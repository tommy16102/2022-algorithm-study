#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
vector<int> pSum;
void input(){
	cin >> n;
	v = vector<int>(n+1);
	pSum = vector<int>(n+1);
	for(int i=1;i<=n;i++){
		cin >> v[i];
		pSum[i] = pSum[i-1] + v[i];
	}
}
void solve(){
	int ans = 0;
	// i k j
	// i+1~k + k+1~j
	for(int k=2;k<n;k++){		
		ans = max(ans, pSum[k] - pSum[1] + pSum[n-1] - pSum[k-1]);
	}
	// i j k
	// i+1~k + j+1~k
	for(int j=2;j<n;j++){
		ans = max(ans, pSum[n]- pSum[1] + pSum[n] - pSum[j] - v[j]);
	}	
	// 0 i n
	// 0~i-1 + 0~n - v[i]
	for(int i=2;i<n;i++){
		ans = max(ans, pSum[i-1] + pSum[n-1] - v[i]);
	}	
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
