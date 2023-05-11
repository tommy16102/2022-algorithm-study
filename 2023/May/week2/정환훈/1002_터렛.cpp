#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int t;
int xx1, yy1, rr1, xx2, yy2, rr2;
void input(){
	cin >> xx1 >> yy1 >> rr1 >> xx2 >> yy2 >> rr2;
}
void solve(){	
	double d = sqrt(abs(xx1-xx2) * abs(xx1-xx2) + abs(yy1-yy2) * abs(yy1-yy2));
	double rmr = abs(rr1-rr2);
	double rpr = rr1+rr2;
	if(d == 0 && rr1 == rr2) cout << -1 << '\n';
	else if(rmr < d && d < rpr) cout << 2 << '\n';
	else if(rpr == d || rmr == d) cout << 1 << '\n';	
	else cout << 0 << '\n';
}
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
