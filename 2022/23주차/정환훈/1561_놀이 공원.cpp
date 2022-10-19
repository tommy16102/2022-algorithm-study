#include <iostream>
using namespace std;
typedef long long ll;
ll n, m;
ll cost[10001];
void input(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> cost[i];
	}
	ll left = 0; ll right = 60000000000;
	ll total_time = 0;
	
	if(n<=m){
		cout << n;
		return;
	}
	
	while(left <= right){
		ll mid = (left + right) / 2;
		ll children = m;
		for(int i=0;i<m;i++){
			children += mid / cost[i];
		}
		if(children >= n){
			total_time = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	ll children = m;
	for(int i=0;i<m;i++){
		children += (total_time - 1) / cost[i];
	}
	
	for(int i=0;i<m;i++){
		if(total_time % cost[i] == 0) children++;
		if(children == n){
			cout << i + 1; return;
		}
	}
	
}
void solve(){
	
}
int main(){
	input();
	solve();
	return 0;
}
