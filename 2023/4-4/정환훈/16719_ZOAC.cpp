#include <iostream>
#include <algorithm>
using namespace std;
string s;
bool v[101];
void input(){
	cin >> s;
}
// [left, right]
void go(int left, int right){	
	int id = -1; int t = 999;
	for(int i=left;i<=right;i++){
		if(!v[i] && t > s[i]){
			t = s[i];
			id = i;
		}
	}
	if(t == 999) return;
	v[id] = true;
	for(int i=0;i<s.size();i++){
		if(v[i]) cout << s[i];
	}
	cout << '\n';
	go(id + 1, right);
	go(left, id - 1);
}
void solve(){
	go(0, s.size()-1);
}
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	solve();
	return 0;
}
