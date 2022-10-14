#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
string l; string r;
void input(){
	cin >> l >> r;
}
void solve(){
	if(l.size() != r.size()){
		cout << 0;
	}
	else{
		int eight = 0;
		for(int i=0;i<l.size();i++){
			if(l[i] == r[i] && l[i] == '8'){
				eight++;
			}
			else if(l[i] != r[i]){
				break;
			}
		}
		cout << eight;
	}
}
int main(){
	input();
	solve();
	return 0;
}
