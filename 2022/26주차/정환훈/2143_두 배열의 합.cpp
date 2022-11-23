#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
ll t;
ll a[1010];
ll b[1010];
vector<ll> sumA;
vector<ll> sumB;
void input(){
	cin >> t;
	cin >> n;	
		
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		ll sum = a[i];
		sumA.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum += a[j];
			sumA.push_back(sum);
		}
	}	
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	for(int i=0;i<m;i++){		
		ll sum = b[i];		
		sumB.push_back(sum);		
		for(int j=i+1;j<m;j++){			
			sum += b[j];
			sumB.push_back(sum);
		}		
	}	
}
void solve(){
	sort(sumB.begin(), sumB.end());
	ll ans = 0;
	for(auto item : sumA){
		int diff = t - item;
		auto ub = upper_bound(sumB.begin(), sumB.end(), diff);
		auto lb = lower_bound(sumB.begin(), sumB.end(), diff);
		ans += ub - lb;
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
