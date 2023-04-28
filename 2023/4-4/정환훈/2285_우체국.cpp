#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
typedef long long ll;
vector<pair<ll,ll>> v;
void input(){
	cin >> n;
	v = vector<pair<ll,ll>>(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;		
	}
}
void solve(){
	sort(v.begin(), v.end());
	ll cnt = 0;
	ll total = 0;
	for(auto e : v){
		total += e.second;
	}
	int id = 0;
	while(true){
		cnt += v[id].second;
		if(cnt >= (1+total)/2){
			cout << v[id].first;
			return;
		}
		id++;
	}

}
int main(){	
	input();
	solve();
	return 0;
}
