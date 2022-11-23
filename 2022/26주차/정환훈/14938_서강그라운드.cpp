#include <iostream>
#include <vector>
using namespace std;
int n,m,r;
int t[101];
int items[101];
int d[101][101];
void input(){
	cin >> n >> m >> r;
	for(int i=1;i<=n;i++){
		cin >> t[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j] = 987654321;
		}
		d[i][i] = 0;
	}
	
	for(int i=0;i<r;i++){
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
	}
}

void solve(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j] <= m){
				items[i] += t[j];
			}				
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, items[i]);
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}
