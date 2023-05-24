#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll g;
void input(){
	cin >> g;
}
void solve(){
	// cur^2 - prev^2 = g
	ll cur = 1;
	ll prev = 1;
	bool no = true;
	while(true){		
		if(cur - prev == 1 && cur*cur - prev*prev > g) break;
		if(cur*cur - prev*prev == g){
			cout << cur << '\n';
			no = false;
		}		
		if(cur*cur - prev*prev > g){
			prev++;
		}
		else{
			cur++;
		}
	}
	if(no) cout << -1;
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
