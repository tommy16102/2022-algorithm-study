#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> _set;
int n; int k;
int w[31];
// dp[i][k] = things i, limit k
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> w[i];
	}
	cin >> k;
}
void solve(){
	_set.insert(0);
	for(int i=0;i<n;i++){
		vector<int> t;
		for(auto s : _set){
			t.push_back(s + w[i]);
			t.push_back(s - w[i]);
		}
		for(auto e : t){
			_set.insert(e);
		}
	}
	for(int i=0;i<k;i++){
		int test;
		cin >> test;
		if(_set.find(test) != _set.end()){
			cout << "Y ";
		}
		else{
			cout << "N ";
		}
	}
}
int main(){
	input();
	solve();
	return 0;	
}
