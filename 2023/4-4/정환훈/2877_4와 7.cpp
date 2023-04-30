#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int k;
string toBinary(int x){
	string ret = "";
	while(x){
		if(x%2==0) ret += "4";
		else ret += "7";
		x/=2;
	}
	reverse(ret.begin(), ret.end());
	ret.erase(ret.begin());
	return ret;
}
void input(){
	cin >> k;
}
void solve(){
	cout << toBinary(k+1);
}
int main(){
	input();
	solve();
	return 0;
}
