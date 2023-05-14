#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int board[51][51];
vector<pair<int,int>> cmd;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> board[i][j];
		}
	}	
	for(int i=0;i<m;i++){
		int d, s;
		cin >> d >> s;
		cmd.push_back({d-1, s});
	}
}
void print(){
	cout << "==================\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "==================\n";
}
void solve(){
	vector<pair<int,int>> clouds = {{n-1, 0}, {n-1, 1}, {n-2, 0}, {n-2, 1}};	
	for(pair<int,int> c : cmd){
		int dir = c.first;
		int dis = c.second;
		for(int i=0;i<clouds.size();i++){
			for(int j=0;j<dis;j++){
				clouds[i].first += dy[dir];
				clouds[i].second += dx[dir];
				if(clouds[i].first < 0) clouds[i].first = n-1;
				if(clouds[i].second < 0) clouds[i].second = n-1;
				if(clouds[i].first == n) clouds[i].first = 0;
				if(clouds[i].second == n) clouds[i].second = 0;
			}
		}
		for(int i=0;i<clouds.size();i++){
			int cy = clouds[i].first; int cx = clouds[i].second;
			board[cy][cx]++;
		}
		for(int i=0;i<clouds.size();i++){
			int plus = 0;
			int cy = clouds[i].first; int cx = clouds[i].second;
			for(int j=0;j<4;j++){
				int ay = cy + dy[j*2+1];
				int ax = cx + dx[j*2+1];
				if(ay >= 0 && ay < n && ax >= 0 && ax < n && board[ay][ax] > 0){
					plus++;
				}	
			}
			board[cy][cx] += plus;
		}
		vector<pair<int,int>> next;		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j] >= 2 && find(clouds.begin(), clouds.end(), make_pair(i, j)) == clouds.end()){
					board[i][j] -= 2;
					next.push_back({i, j});
				}
			}
		}
		clouds = next;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans += board[i][j];
		}
	}
	cout << ans;
}
int main(){
	
	input();
	solve();
	return 0;
}
