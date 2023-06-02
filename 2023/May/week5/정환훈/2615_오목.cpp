#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int board[19][19];
int dy[4][5] = {{0, 0, 0, 0, 0}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {-1, -2, -3, -4, -5}};
int dx[4][5] = {{1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
void input(){
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			cin >> board[i][j];
		}
	}
}
bool valid(int y, int x){
	return (y>=0 && y<19 && x>=0 && x<19);
}
pair<int,int> isWin(int n){
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			int y = j; int x = i;
			if(board[y][x] == n){
				for(int k=0;k<4;k++){
					int test = 0;
					for(int t=0;t<4;t++){
						int ny = y + dy[k][t];
						int nx = x + dx[k][t];
						if(ny >= 0 && ny < 19 && nx >= 0 && nx < 19 && board[ny][nx] == n){
							test++;
						}
					}					
					if(test == 4){											
						int ly = y + dy[k][4];
						int lx = x + dx[k][4];
						int ly2 = y - dy[k][0];
						int lx2 = x - dx[k][0];
						// (ly2, lx2) (y, x) (y+dy[0], x+dx[0]) ... (ly, lx)
						if(!valid(ly, lx) && !valid(ly2, lx2)){
							return {y+1, x+1};
						}
						else if(valid(ly, lx) && !valid(ly2, lx2)){
							if(board[ly][lx] != n){
								return {y+1, x+1};
							}
						}
						else if(!valid(ly, lx) && valid(ly2, lx2)){
							if(board[ly2][lx2] != n){
								return {y+1, x+1};
							}
						}
						if(valid(ly, lx) && valid(ly2, lx2)){
							if(board[ly][lx] != n && board[ly2][lx2] != n){
								return {y+1, x+1};
							}
						}
					}
				}
			}
		}
	}
	return {-1, -1};
}
void solve(){
	if(isWin(1).first != -1){
		cout << 1 << '\n';
		cout << isWin(1).first << " " << isWin(1).second;
	}
	else if(isWin(2).first != -1){
		cout << 2 << '\n';
		cout << isWin(2).first << " " << isWin(2).second;
	}
	else{
		cout << 0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
