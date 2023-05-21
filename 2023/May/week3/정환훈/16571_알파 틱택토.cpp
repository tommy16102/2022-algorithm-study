#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std; 
vector<int> board;
void input(){
	board = vector<int>(9);
	for(int i=0;i<9;i++){
		cin >> board[i];
	}
}
bool isWin(int who, vector<int> b){
	for(int j=0;j<3;j++){
		// 012 345 678
		if(b[j*3] == b[j*3+1] && b[j*3+1] == b[j*3+2] && who == b[j*3]){
			return true;
		}
		// 036 147 258
		if(b[j] == b[j+3] && b[j+3] == b[j+6] && b[j] == who){
			return true;
		}
		// 048
		if(b[0] == b[4] && b[4] == b[8] && b[0] == who){
			return true;
		}
		// 246
		if(b[2] == b[4] && b[4] == b[6] && b[2] == who){
			return true;
		}
	}	
	return false;
}
int game(int now, vector<int> b){
	int ret = 2;
	for(int i=0;i<9;i++){
		if(b[i] == 0){
			b[i] = now;
			if(isWin(now, b)){
				ret = min(ret, -1);
			}
			ret = min(ret, game(now==1? 2: 1,  b));
			b[i] = 0;
		}
	}
	if(ret == 1) return -1;
	else if(ret == 0 || ret == 2) return 0;
	else return 1;
}
void solve(){
	int cnt = 0;
	for(int i=0;i<9;i++){
		if(board[i] == 0) cnt++;
	}
	int turn = cnt%2 == 1 ? 1 : 2;
	int win = game(turn, board);	
	if(win==1) cout << "W";
	else if(win == 0) cout << "D";
	else cout << "L";
}

int main(){
	input();
	solve();
	return 0;
}
