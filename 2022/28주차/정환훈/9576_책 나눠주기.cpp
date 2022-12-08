#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>& a, pair<int,int>& b){
	if(a.second == b.second){
		return a.first > b.first;
	}
	return a.second < b.second;
}
int n, m;
bool done[1010];
vector<pair<int,int>> v;
void input(){
	cin >> n >> m;
	v.clear();
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	for(int i=0;i<1010;i++){
		done[i] = false;
	}
}
void solve(){
	int ans = 0;
	sort(v.begin(), v.end(), cmp);
	for(int i=0;i<v.size();i++){
		for(int j=v[i].first;j<=v[i].second;j++){
			if(!done[j]){
				ans++;
				done[j] = true;
				break;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
