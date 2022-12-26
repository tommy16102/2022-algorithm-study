#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
priority_queue<ll,vector<ll>,greater<>> pq;
const ll MOD = 1000000007;
void input(){
	cin >> n;
	v = vector<ll>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		pq.push(v[i]);
	}
}
void solve(){
	ll ans = 1;
	while(!pq.empty()){
		ll t1 = pq.top();
		pq.pop();
		if(pq.empty()) break;
		ll t2 = pq.top();
		pq.pop();
		pq.push(t1*t2);		
		ans = ans * (((t1 % MOD) * (t2 % MOD)) % MOD) % MOD;
	}
	cout << ans << '\n';
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();	
	}
	return 0;
}
