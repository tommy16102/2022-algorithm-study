#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
vector<int> v;
void input(){
	cin >> n >> m;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
void solve(){
	sort(v.begin(), v.end());
	int ans = 0;
	bool flag = false;
	while(true){
		if(flag || v.empty()) break;
		for(int i=0;i<v.size();i++){
			// 1. 10으로 나눠 떨어지고 m>=k인 k번 잘라 모두 10으로 만들 수 있는 빵 
			if(v[i] > 10 && v[i] % 10 == 0 && v[i] / 10 <= m+1){
				ans += v[i] / 10;				
				m -= v[i]/10 -1;				
				v.erase(v.begin() + i);
				break;
			}
			if(i == v.size()-1){
				flag = true;
			}
		}
	}
	// 2. 나머지 10 이상인 빵들 
	for(auto e : v){
		int t = e;
		while(t>10 && m>0){
			t-=10;
			m--;
			ans++;
		}
		if(e == 10){
			ans++;
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
