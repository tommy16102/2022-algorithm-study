#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll fn[1000001];
ll gn[1000001];
void input(){
	cin >> n;
}
void go(){	
	for(int i=1;i<=1000000;i++){		
		for(int j=i;j<=1000000;j+=i){
			fn[j] += i;
		}
	}	
	for(int i=1;i<=1000000;i++){
		gn[i] = gn[i-1] + fn[i];
	}
	
}
void solve(){
	cout << gn[n] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	go();
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}	
