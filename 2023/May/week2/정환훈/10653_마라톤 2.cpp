#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, k;
int cache[501][501];
vector<pair<int,int>> v;
void input(){
	cin >> n >> k;
	v = vector<pair<int,int>>(n+1);
	for(int i=1;i<=n;i++){
		cin >> v[i].first >> v[i].second;
	}	
	for(int i=0;i<501;i++){
		for(int j=0;j<501;j++){
			cache[i][j] = -1;
		}
	}
}
int go(int depth, int jump){
	if(depth == n) return 0;
	int& ret = cache[depth][jump];
	if(ret != -1) return ret;
	ret = 987654321;
	ret = min(ret, go(depth+1, jump) + abs(v[depth].first - v[depth+1].first) + abs(v[depth].second - v[depth+1].second));
	for(int i=1;i<=jump;i++){
		if(depth+i+1 <= n)
			ret = min(ret, go(depth+i+1, jump-i) + abs(v[depth].first - v[depth+i+1].first) + abs(v[depth].second - v[depth+i+1].second));
	}
	return ret;
}
void solve(){
	cout << go(1, k);
}
int main(){
	
	input();
	solve();
	return 0;
}
