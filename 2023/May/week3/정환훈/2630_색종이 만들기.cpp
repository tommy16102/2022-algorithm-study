#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int board[129][129];
int blue, white;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> board[i][j];
		}
	}
}
void go(int y, int x, int s){
	int start = board[y][x];
	bool can = true;
	for(int i=y;i<y+s;i++){
		for(int j=x;j<x+s;j++){
			if(start != board[i][j]){
				can = false;
				break;
			}
		}
	}
	if(!can){
		s /= 2;
		go(y, x, s);
		go(y, x+s, s);
		go(y+s, x, s);
		go(y+s, x+s, s);
	}
	else{
		start == 1 ? blue += 1 : white += 1;	
	}	
}
void solve(){
	go(0, 0, n);
	cout << white << '\n' << blue; 
}
int main(){
	
	input();
	solve();
	return 0;
}
