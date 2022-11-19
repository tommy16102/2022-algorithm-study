#include <iostream>
#include <set>
using namespace std;
string game;
set<string> ans;
int board[3][3];
int win[8][3] = {{0,1,2},{3,4,5},{6,7,8},
				{0,3,6}, {1,4,7}, {2,5,8},
				{0,4,8}, {2,4,6}};
				
bool check(string t, int i){
	for(int j=1;j<3;j++){
		// char is . or not make line
		if(t[win[i][0]] != t[win[i][j]] || t[win[i][0]] == '.'){
			return false;
		}
	}
	return true;
}
				
void go(int n){
	string now;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == 1) now += "X";
			else if(board[i][j] == 2) now += "O";
			else now += ".";
		}
	}
	// someone win game
	for(int i=0;i<8;i++){
		if(check(now, i)){
			ans.insert(now);
			return;
		}
	}
	// end game
	if(n == 9){
		ans.insert(now);
		return;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			// O or X
			if(board[i][j] != 0){
				continue;
			}
			// X->O->X...
			board[i][j] = n%2+1;
			go(n+1);
			// no choose
			board[i][j] = 0;
		}
	}
}

void input(){
	go(0);
}

void solve(){
	while(1){
		cin >> game;
		if(game == "end"){
			break;
		}
		if(ans.find(game) != ans.end()){
			cout << "valid\n";
		}
		else{
			cout << "invalid\n";
		}
	}

}
int main(){
	input();
	solve();
	return 0;
}
