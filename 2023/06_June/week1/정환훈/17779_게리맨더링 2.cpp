#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int board[21][21];
int temp[21][21];
int n;
void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> board[i][j];
		}
	}
}
void print(){
	cout << '\n'; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << temp[i][j] << " ";
		}
		cout << '\n';
	}
}
int go(int x, int y, int d1, int d2){	
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			temp[i][j] = board[i][j];
		}
	}
	
	for(int r=1;r<x+d1;r++){
		for(int c=1;c<=y;c++){
			temp[r][c] = 1;
		}
	}

	for(int r=1;r<=x+d2;r++){
		for(int c=y+1;c<=n;c++){
			temp[r][c] = 2;
		}
	}

	for(int r=x+d1;r<=n;r++){
		for(int c=1;c<y-d1+d2;c++){
			temp[r][c] = 3;
		}
	}

	for(int r=x+d2+1;r<=n;r++){
		for(int c=y-d1+d2;c<=n;c++){
			temp[r][c] = 4;
		}
	}

	vector<pair<int,int>> t;
	for(int i=0;i<=d1;i++){
		int nx = x + i;
		int ny = y - i;
		temp[nx][ny] = 5;
		t.push_back({nx, ny});
	}
	for(int i=0;i<=d2;i++){
		int nx = x + i;
		int ny = y + i;
		temp[nx][ny] = 5;
		t.push_back({nx, ny});
	}
	for(int i=1;i<=d2;i++){
		int nx = x + d1 + i;
		int ny = y - d1 + i;
		temp[nx][ny] = 5;
		t.push_back({nx, ny});	
	}
	for(int i=1;i<=d1;i++){
		int nx = x + d2 + i;
		int ny = y + d2 - i;
		temp[nx][ny] = 5;
		t.push_back({nx, ny});
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());	
	for(int i=1;i<t.size()-1;i+=2){
		pair<int,int> left = t[i];
		pair<int,int> right = t[i+1];
		int lx = left.first; int ly = left.second;
		int rx = right.first; int ry = right.second;
		for(int j=ly;j<=ry;j++){			
			temp[lx][j] = 5;
		}
	}
	
	vector<int> g = vector<int>(6, 0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[temp[i][j]] += board[i][j];
		}
	}	
	return max({g[1], g[2], g[3], g[4], g[5]}) - min({g[1], g[2], g[3], g[4], g[5]});
	//print();	
}

int go(int x, int y){
	// (d1, d2 ¡Ã 1, 1 ¡Â x < x+d1+d2 ¡Â N, 1 ¡Â y-d1 < y < y+d2 ¡Â N)
	int ret = 99999999;
	for(int d1=1;d1<=n;d1++){
		for(int d2=1;d2<=n;d2++){
			if(d1 >= 1 && d2 >= 1 && 1 <= x && x + d1 + d2 <= n && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n){
				ret = min(ret, go(x, y, d1, d2));
			}
		}
	}
	return ret;
}
void solve(){	
int ans = 9999999;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans = min(ans, go(i, j));
		}
	}
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}	
