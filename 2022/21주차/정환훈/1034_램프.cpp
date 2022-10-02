#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n; int m; int k;
vector<string> strs;
int answer = 0;
map<string, int> _map;
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		strs.push_back(str);
	}
	cin >> k;
}

void solve(){
	for(auto str : strs){
		int zero = 0;
		for(auto c : str){
			if(c == '0')
				zero++;
		}
		if(zero > k || (zero % 2 != k % 2)){
			continue;
		}
		if(_map.find(str) == _map.end()){
			_map.insert({str, 1});
		}
		else
			_map[str]++;
	}
	int ans = 0;
	for(auto e : _map){
		ans = max(ans, e.second);
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}
