#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct bomb{
	int y; int x; int t; char status;
	bomb() : y(-1), x(-1), t(-1), status('.') {}
	bomb(int Y, int X, int T, char STATUS) : y(Y), x(X), t(T), status(STATUS){}
}bomb;
int r, c, n;
bomb board[201][201];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
void input(){
	cin >> r >> c >> n;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char temp; cin >> temp;
			if(temp == 'O'){
				board[i][j] = bomb(i, j, 3, 'O');
			}
			else if(temp == '.'){
				board[i][j] = bomb(i, j, -1, '.');
			}
		}
	}
}

void print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i][j].status == 'O'){
				cout << 'O';
			}
			else if(board[i][j].status == '.'){
				cout << '.';
			}
		}
		cout << '\n';
	}	
}
void solve(){
	int time = 0;
	// first bomb launch..
	// do nothing..
	time++;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i][j].status == 'O'){
				board[i][j].t--;	
			}
		}
	}
	if(time >= n){
		print();
		return;
	}		
	while(true){
		// launch bomb all areas..
		time++;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(board[i][j].status == 'O'){
					board[i][j].t--;	
				}
				else if(board[i][j].status == '.'){
					board[i][j] = bomb(i, j, 3, 'O');
				}
			}
		}
		if(time == n){
			print();
			return;
		}
		// kaboom!
		time++;
		vector<pair<int,int>> boomed;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				board[i][j].t--;
				if(board[i][j].t == 0 && board[i][j].status == 'O'){
					board[i][j] = bomb(i, j, -1, '.');
					int y = board[i][j].y;
					int x = board[i][j].x;
					for(int k=0;k<4;k++){
						int ny = y+dy[k];
						int nx = x+dx[k];
						if(ny >= 0 && ny < r && nx >= 0 && nx < c){
							boomed.push_back({ny, nx});
							//board[ny][nx] = bomb(ny, nx, -1 ,'.');
						}
					}
				}
			}
		}
		for(auto b : boomed){
			board[b.first][b.second] = bomb(b.first, b.second, -1, '.');
		}
		if(time == n){
			print();
			return;
		}			
	}
}
int main(){
	input();
	solve();
	return 0;
}
