#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
int ans;
vector<int> v;
vector<int> minuses;
vector<int> pluses;
void input(){
	cin >> n >> m;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		if(v[i] > 0){
			pluses.push_back(v[i]);
		}
		else{
			minuses.push_back(v[i]);
		}
	}
}
void solve(){
	sort(minuses.begin(), minuses.end());
	sort(pluses.begin(), pluses.end(), greater<int>());
	vector<int> go;
	for(int i=0;i<minuses.size();){
		go.push_back(abs(minuses[i]));
		i += m;
	}
	for(int i=0;i<pluses.size();){
		go.push_back(pluses[i]);
		i += m;
	}
	sort(go.begin(), go.end(), greater<int>());
	for(auto g : go){
		ans += 2*g;
	}
	ans -= go[0];
	cout << ans;	
}

int main(){
	input();
	solve();
	return 0;
}
