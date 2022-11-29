#include <iostream>
using namespace std;
int n, m;
string s;
string sub;
int ans;
void input(){
	cin >> n >> m >> s;
}

void solve(){
	string p = "IOI";
	int psize = p.size();
	for(int i=1;i<n;i++){
		p += "OI";
	}
	for(int i=0;i<m;i++){
		if(s[i] == 'O'){
			continue;
		}
		int oCnt = 0;
		while(s[i+1] == 'O' && s[i+2] == 'I'){
			oCnt++;
			i += 2;
			if(oCnt == n){
				oCnt--;
				ans++;
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
