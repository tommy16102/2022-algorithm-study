#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; int m;
typedef long long ll;
vector<ll> cost;
void input(){
	cin >> n >> m;
	cost = vector<ll>(n);
	for(int i=0;i<n;i++){
		cin >> cost[i];
	}
		
}
void solve(){
	sort(cost.begin(), cost.end());
	ll left = 1;
	ll right = m * cost.back();
	ll ans = 0;
	while(left <= right){
		ll mid = (left + right) / 2;
		ll sum = 0;
		for(auto c : cost)
			sum += mid / c;
			
		if(sum < m){
			left = mid + 1;
		}
		else{
			ans = mid;
			right = mid - 1;
		}

	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
