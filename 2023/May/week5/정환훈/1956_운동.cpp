#include <iostream>
#include <algorithm>
#include <vector>
int v, e;
using namespace std;
int d[404][404];
void input(){
	cin >> v >> e;
	for(int i=0;i<404;i++){
		for(int j=0;j<404;j++){
			d[i][j] = 987654321;
		}
	}
	for(int i=0;i<e;i++){
		int from, to, w;
		cin >> from >> to >> w;
		d[from][to] = w;
	}
}
void solve(){
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 987654321;
	for(int i=1;i<=v;i++){
		for(int j=i+1;j<=v;j++){
			ans = min(ans, d[i][j] + d[j][i]);
		}
	}
	if(ans == 987654321) ans = -1; 
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
