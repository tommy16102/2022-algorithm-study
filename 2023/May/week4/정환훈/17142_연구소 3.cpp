#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, vn;
vector<pair<int,int>> vp;
int board[51][51];
int origin[51][51];
int sel[11];
int seq[11];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int ans = 987654321;
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> board[i][j];
			origin[i][j] = board[i][j];
			if(board[i][j] == 2) {
				vn++;
				vp.push_back({i, j});
			}
		}
	}
}
int bfs(){
	bool v[51][51];
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[i][j] = false;			
			board[i][j] = origin[i][j];
			if(board[i][j] == 1){
				board[i][j] = -1;
			}
			if(board[i][j] == 0){
				res++;
			}
		}
	}
	queue<pair<int, pair<int,int>>> q;
	
	// non-activated virus
	for(int i=0;i<vp.size();i++){
		int y = vp[i].first;
		int x = vp[i].second;
		board[y][x] = -2;
	}
	// activated virus
	for(int i=0;i<m;i++){
		int y = vp[seq[i]].first;
		int x = vp[seq[i]].second;
		q.push({0, {y, x}});
		v[y][x] = true;
		board[y][x] = -3;
	}
	int tt = 0;
	// no need to run
	if(res == 0) return 0;
	while(!q.empty()){		
		pair<int,int> cur = q.front().second;
		int t = q.front().first;		
		tt = max(t, tt);		
		int y = cur.first;
		int x = cur.second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny < n && nx >= 0 && nx < n && !v[ny][nx]){
				// empty place
				if(board[ny][nx] == 0){
					v[ny][nx] = true;
					q.push({t+1, {ny, nx}});
					board[ny][nx] = t+1;
					res--;
					// end
					if(res == 0) return t+1;
				}
				// non-activated virus -> activated virus
				if(board[ny][nx] == -2){
					v[ny][nx] = true;
					q.push({t+1, {ny, nx}});	
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			// cannot reach somewhere
			if(board[i][j] == 0) return 987654321;
		}
	}	
	return tt;
}
void go(int depth, int id){
	if(depth == m){
		ans = min(ans, bfs());
		return;
	}
	for(int i=id;i<vn;i++){
		if(sel[i]) continue;
		sel[i] = true;
		seq[depth] = i;
		go(depth+1, i);
		sel[i] = false;
	}
}
void solve(){
	go(0, 0);
	if(ans == 987654321) cout << -1;
	else cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
