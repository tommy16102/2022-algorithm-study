#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, d;
int pos[3];
int board[16][16];
int origin[16][16];
int sel[16];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
vector<pair<int,int>> archer;
void input(){
	cin >> n >> m >> d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> board[i][j];
			origin[i][j] = board[i][j];
		}
	}
}
int ans;
void game(){
	int kill = 0;
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			board[i][j] = origin[i][j];
		}
	}
	while(true){
		vector<pair<int,int>> enemies;
		bool end = true;
		// check		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(board[i][j] == 1) {
					end = false;
					enemies.push_back({i, j});					
				}
			}			
		}
		// archer kill		
		vector<pair<int,int>> kills;
		for(int i=0;i<3;i++){
			queue<pair<pair<int,int>, int>> q;
			bool v[16][16];
			for(int a=0;a<16;a++){
				for(int b=0;b<16;b++){
					v[a][b] = false;
				}
			}
			q.push({archer[i], 0});
			v[archer[i].first][archer[i].second] = true;
			while(!q.empty()){
				pair<int,int> cur = q.front().first;
				int depth = q.front().second;
				if(depth == d+1) break;
				int y = cur.first;
				int x = cur.second;
				q.pop();
				if(board[y][x] == 1){
					kills.push_back({y, x});
					break;
				}
				for(int k=0;k<4;k++){
					int ny = y + dy[k];
					int nx = x + dx[k];
					if(ny >= 0 && ny < n && nx >= 0 && nx < m && !v[ny][nx]){
						q.push({{ny, nx}, depth+1});
						v[ny][nx] = true;
					}
				}
			}
		}		
		kills.erase(unique(kills.begin(), kills.end()), kills.end());
		kill += kills.size();
		// enemy move
		for(int x=0;x<16;x++){
			for(int y=0;y<16;y++){
				board[x][y] = 0;
			}
		}
		for(auto e : enemies){
			if(find(kills.begin(), kills.end(), e) != kills.end()) continue;			
			board[e.first+1][e.second] = 1;			
		}
		if(end) break;
	}	
	ans = max(ans, kill);
}
void go(int depth, int id){
	if(depth == 3){
		archer.clear();
		for(int i=0;i<3;i++){
			archer.push_back({n, pos[i]});
		}
		game();
		return;
	}
	for(int i=id;i<m;i++){
		if(sel[i]) continue;
		pos[depth] = i;
		sel[i] = true;
		go(depth+1, i);
		sel[i] = false;
	}
}
void solve(){
	go(0, 0);
	cout << ans;
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
