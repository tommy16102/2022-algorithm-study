#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n; int k; int q;
ll x; ll y;
void input(){
	 cin >> x >> y;
}

void solve(){
	// parent = (child-2) / k + 1
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll d = 0;
	// 1진트리의 경우 직선거리만 재는게 빠르다. 
	if(k == 1){
		cout << abs(y-x) << '\n';
		return;
	}
	while(y != x){
		if(y > x){
			y = (y - 2) / k + 1;
		}
		else
			x = (x - 2) / k + 1;
		d++;
	}
	cout << d << '\n';
}
int main(){
	cin >> n >> k >> q;
	for(int i=0;i<q;i++){	
		input();
		solve();
	}
	return 0;
}

