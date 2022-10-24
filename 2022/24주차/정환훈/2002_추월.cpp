#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> out;
unordered_map<string, int> m;
int n;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		string s; 
		cin >> s;
		m.insert({s, i});
	}
	out = vector<string>(n);
	for(int i=0;i<n;i++){
		cin >> out[i];
	}
}
void solve(){
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m[out[i]] > m[out[j]]){
				ans++;
				break;
			}
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
