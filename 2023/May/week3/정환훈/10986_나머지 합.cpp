#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int n, m;
map<ll, ll> _map;
vector<ll> v;
ll sum[1000001];
void input(){
	cin >> n >> m;
	v = vector<ll>(n+1);
	int s = 0;
	for(int i=1;i<=n;i++){
		cin >> v[i];
		s += v[i];
		sum[i] = sum[i-1] + v[i];
	}
}
void solve(){
	// (pSum[j] - pSum[i]) % Mod = 0
	// => pSum[j] % Mod == pSum[i] % Mod
	ll ans = 0;	
	for(int i=1;i<=n;i++){
		sum[i] %= m;		
		_map[sum[i]]++;
	}
	ans = _map[0];
	for(int i=0;i<m;i++){		
		ans += _map[i] * (_map[i]-1) / 2;
	}	
	cout << ans;
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
