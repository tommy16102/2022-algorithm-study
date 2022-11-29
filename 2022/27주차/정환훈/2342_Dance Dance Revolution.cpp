#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;
int dp[101010][5][5];
int n;
int dis(int from, int to){
	if(from == 0)
		return 2;
	if(from == to)
		return 1;
	if(abs(from - to) == 2)
		return 4;
	return 3;
}

void input(){
	while(true){
		int temp;
		cin >> temp;		
		if(temp == 0) break;
		v.push_back(temp);
	}
	for(int i=0;i<101010;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				dp[i][j][k] = -1;
			}
		}
	}
}

int go(int depth, int l, int r){
	if(depth == n) return 0;
	if(dp[depth][l][r] != -1) return dp[depth][l][r];
	int next = v[depth];
	int nl = go(depth + 1, next, r) + dis(l, next);
	int nr = go(depth + 1, l, next) + dis(r, next);
	return dp[depth][l][r] = min(nl, nr);
}

void solve(){	
	n = v.size();
	cout << go(0, 0, 0);
}
int main(){
	input();
	solve();
	return 0;
}
