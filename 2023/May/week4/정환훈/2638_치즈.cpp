#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int board[101][101];
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> board[i][j];
		}
	}
}
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int bfs(int y, int x){
	int cheese = 0;
	bool v[101][101];
	int check[101][101];
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			v[i][j] = false;
			check[i][j] = 0;
		}
	}
	queue<pair<int,int>> q;
	q.push({y, x});
	v[y][x] = true;
	while(!q.empty()){
		pair<int,int> cur = q.front();
		int y = cur.first;
		int x = cur.second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny < n && nx >= 0 && nx < m && !v[ny][nx]){				
				if(board[ny][nx] == 0){	
					v[ny][nx] = true;
					q.push({ny, nx});
				}
				else if(board[ny][nx] == 1){
					check[ny][nx]++;
				}
			}
		}
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			if(board[i][j] == 1){
				cheese++;
			}
			if(check[i][j] >= 2){				
				board[i][j] = 0;
			}
		}
	}
	return cheese;
}
void solve(){
	int time = 0;
	while(bfs(0,0) != 0){time++;}
	cout << time;
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
