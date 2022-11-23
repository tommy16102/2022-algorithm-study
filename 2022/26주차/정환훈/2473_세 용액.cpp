#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
void input(){
	cin >> n;
	v = vector<ll>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
void solve(){
	sort(v.begin(), v.end());
	// -97 -6 -2 6 98
	ll minAbs = 3000000001;
	vector<ll> answer(3);
	for(int i=0;i<n-2;i++){
		int left = i+1;
		int right = n-1;
		while(left < right){
			ll val = v[i] + v[left] + v[right];
			if(abs(val) < minAbs){
				minAbs = abs(val);
				answer[0] = v[i];
				answer[1] = v[left];
				answer[2] = v[right];
			}
			if(val < 0) left++;
			else right--;
		}
	}
	cout << answer[0] << " " << answer[1] << " " << answer[2];
}
int main(){
	input();
	solve();
	return 0;
}
