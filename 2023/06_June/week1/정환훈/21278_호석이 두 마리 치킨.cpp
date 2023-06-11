#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[101][101];
vector<pair<int, pair<int,int>>> v;
int n, m;
void input(){
	cin >> n >> m;
	for(int i=1;i<101;i++){
		for(int j=1;j<101;j++){
			d[i][j] = 987654321;			
		}
		d[i][i] = 0;
	}	
	for(int i=0;i<m;i++){
		int from, to;
		cin >> from >> to;
		d[from][to] = 1;
		d[to][from] = 1;
	}
}
void go(int a, int b){
	int ret = 0;
	for(int i=1;i<=n;i++){
		ret += min(d[i][a], d[i][b]) * 2;
	}
	v.push_back({ret, {a, b}});
}
void solve(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			go(i, j);
		}
	}
	sort(v.begin(), v.end());
	cout << v.front().second.first << " " << v.front().second.second << " " << v.front().first; 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
