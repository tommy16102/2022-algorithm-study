#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
vector<int> v;
vector<pair<int,int>> p;
void input(){
	cin >> n >> k;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i]; 
	}	
}
void solve(){
	int left = 0; int right = 0;
	int cnt = v[0] % 2 == 0 ? 0 : 1;
	int ans = 0;
	while(left < n){	
		while(right < n-1 && cnt + v[right+1] % 2 <= k){		  
		  cnt += v[right+1] % 2;
		  right++;
		}
		ans = max(ans, right - left + 1 - cnt);
		cnt -= v[left] % 2;
		left++;
	}
	cout << ans;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);		
	input();
	solve();		
	return 0;
}
