#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1 ,0, 1};
bool v[1010][1010][2];
char cboard[1010][1010];
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> cboard[i][j];			
		}
	}
}
void solve(){
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({{0, 0}, {1, 0}});
	v[0][0][1] = true;
	while(!q.empty()){
		pair<int,int> cur = q.front().first;
		int t = q.front().second.second;
		int r = q.front().second.first;
		q.pop();	
		int y = cur.first; 
		int x = cur.second;
		if(y == n-1 && x == m-1){
			cout << t+1;
			return;
		}
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny < n && nx >= 0 && nx < m){
				if(cboard[ny][nx] == '0' && !v[ny][nx][r]){
					v[ny][nx][r] = true;
					q.push({{ny, nx}, {r, t+1}});
				}				
				if(cboard[ny][nx] == '1' && r == 1 && !v[ny][nx][r]){
					v[ny][nx][r] = true;
					q.push({{ny, nx}, {0, t+1}});
				}
			}
		}
	}
	cout << -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
