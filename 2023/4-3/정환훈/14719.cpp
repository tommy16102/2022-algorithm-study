#include <iostream>
#include <algorithm>
using namespace std;
int h, w;
int v[505];
void input(){
	cin >> h >> w;
	for(int i=0;i<w;i++){
		cin >> v[i];
	}
}
void solve(){
	int ans = 0;
	for(int i=1;i<w;i++){
		int now = v[i];
		int left = *max_element(v, v + i);
		int right = *max_element(v + i + 1, v + w);		
		if(now < left && now < right){
			ans += min(left, right) - now;
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
