#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int g, p;
bool used[1000001];
vector<int> v;
int ans = 0;
set<int> _set;
void input(){
	cin >> g >> p;
	v = vector<int>(p);
	for(int i=0;i<p;i++){
		cin >> v[i];
	}
	for(int i=1;i<=g;i++){
		_set.insert(i);
	}
}
void solve(){
	for(int i=0;i<v.size();i++){
		if(_set.find(v[i]) != _set.end()){
			_set.erase(v[i]);
			continue;
		}
		auto it = _set.upper_bound(v[i]);
		if(it == _set.begin()){
			cout << i;
			return;
		}
		if(*(--it) > v[i]){
			cout << i;
			return;
		}
		_set.erase(it);
	}
	cout << p;
}
int main(){
	input();
	solve();
	return 0;
}
