#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int n, m, k;
vector<int> v;
void input(){
	cin >> n >> m >> k;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
void solve(){
	int ans = 0;
	int left = 0; int right = m-1;
	int s = v.size(); bool first = true;
	int sum = 0;	
	for(int i=0;i<m;i++) {
		sum += v[i];		
	}
	if(n == m){
		sum < k ? cout << 1 << '\n' : cout << 0 << '\n';
		return;
	}
	while(true){
		if(!first && left % s == 0) break;
		first = false;		
		if(sum < k) {
			ans++;	
		}
		sum -= v[left];
		sum += v[(right+1)%s];
		
		left++; right++;				
	}
	cout << ans << '\n';
}
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
