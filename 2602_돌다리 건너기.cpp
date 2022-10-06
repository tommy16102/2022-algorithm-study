#include <iostream>
#include <string>
using namespace std;
long long dp[2][101][21]; // [현재다리][현재위치][현재순서] 
string p;
string board[2];

void input(){
	cin >> p >> board[0] >> board[1];
}

void solve(){
	int l = board[0].size();
	int r = p.size();
	for(int i=0;i<l;i++){
		for(int j=0;j<2;j++){
			// 해당 위치가 찾으려는 문자의 시작과 같을 시 
			if(board[j][i] == p[0]) dp[j][i][0] = 1;
		}
	}
	
	for(int i=0;i<l;i++){
		for(int j=0;j<2;j++){
			for(int k=1;k<r;k++){
				for(int m=0;m<i;m++){
					if(board[j][i] == p[k] && board[abs(j-1)][m] == p[k-1])
						dp[j][i][k] += dp[abs(j-1)][m][k-1];
				}
			}
		}
	}
	
	long long ans = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<l;j++){
			if(board[i][j] == p[p.size()-1]) ans += dp[i][j][p.size()-1];
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
