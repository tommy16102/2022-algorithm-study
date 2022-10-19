#include <iostream>
using namespace std;
int n;
typedef long long ll;
ll d[100001];
ll cost[100001];
void input(){
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> d[i];
	}
	for(int i=0;i<n;i++){
		cin >> cost[i];
	}
}
void solve(){
	ll ans = 0;
	ll m = cost[0];	
	ans += m * d[0];
	for(int i=1;i<n-1;i++){
		if(cost[i] < m){
			m = cost[i];
		}
		ans += m * d[i];
	}
	cout << ans;

}
int main(){
	input();
	solve();
	return 0;
}
