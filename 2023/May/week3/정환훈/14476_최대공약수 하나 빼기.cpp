#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std; 
int n;
vector<int> v;
map<int,int> _map;
void input(){
	cin >> n;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
int gcd(int a, int b){
	if(a<b) swap(a,b);
	if(b == 0) return a;
	return gcd(b, a%b);
}
void solve(){
	// except i => gcd(0~i-1, i+1~n)
	vector<int> ltor(n);
	vector<int> rtol(n);
	ltor[0] = v.front();
	rtol[n-1] = v.back();
	for(int i=1;i<n;i++){
		ltor[i] = gcd(ltor[i-1], v[i]);
	}
	for(int i=n-2;i>=0;i--){
		rtol[i] = gcd(rtol[i+1], v[i]);
	}
	int result;
	int ex;
	for(int i=0;i<n;i++){	
		if(i==0){
			result = rtol[1];
			ex = v[i];
		}
		else if(i==n-1){
			if(result < ltor[n-2]){
				result = max(result, ltor[n-2]);
				ex = v[i];	
			}						
		}
		else{
			int target = gcd(ltor[i-1], rtol[i+1]);
			if(result < target){
				result = target;
				ex = v[i];
			}
		}
	}
	if(ex % result == 0){
		cout << -1;
		return;
	}
	cout << result << " " << ex;
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
