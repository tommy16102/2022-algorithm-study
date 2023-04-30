#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int board[1010][1010];
int cache[1010][1010][3];
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> board[i][j];
			for(int k=0;k<3;k++){
				cache[i][j][k] = -1;
			}			
		}
	}
}
int go(int y, int x, int dir){
	if(y == n) return 0;	
	if(x == -1 || x == m) return 987654321;
	int& ret = cache[y][x][dir];
	if(ret != -1) return ret;
	ret = 987654321;
	if(dir == 0){
		ret = min(ret, board[y][x] + go(y+1, x, 1));		
		ret = min(ret, board[y][x] + go(y+1, x+1, 2));
	}
	if(dir == 1){
		ret = min(ret, board[y][x] + go(y+1, x-1, 0));
		ret = min(ret, board[y][x] + go(y+1, x+1, 2));
	}
	if(dir == 2){
		ret = min(ret, board[y][x] + go(y+1, x-1, 0));
		ret = min(ret, board[y][x] + go(y+1, x, 1));		
	}
	return ret;
}
void solve(){
	int ans = 987654321;	
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			ans = min(ans, go(0, i, j));
		}
	}		
	cout << ans;
}
int main(){	
	input();
	solve();
	return 0;
}
