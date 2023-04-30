#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

typedef struct boxinfo{	
	int dir;
	int num;
}BoxInfo;

typedef struct fishinfo{
	map<int, pair<int,int>> m;
	BoxInfo box[4][4];
}FishInfo;
FishInfo fi;

void input(){	
	map<int, pair<int,int>> m;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int t1, t2;
			cin >> t1 >> t2;
			BoxInfo b;
			b.dir = t2; b.num = t1;
			fi.box[i][j] = b;
			m[t1] = {i,j};
		}
	}
	fi.m = m;
}
int ans;
void print(FishInfo ff){
	cout << "============================\n";
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout << ff.box[i][j].num << "," << ff.box[i][j].dir << " ";
		}
		cout << '\n';
	}
	cout << "============================\n";
}
void go(int sy, int sx, int sdir, FishInfo ffi, int sum){		
	// move fish	
	for(int i=1;i<=16;i++){
		//cout << "=============" << i << "==============\n";
		if(ffi.m.find(i) == ffi.m.end()) continue;
		int fy = ffi.m[i].first;
		int fx = ffi.m[i].second;
		int fdir = ffi.box[fy][fx].dir;
		for(int j=0;j<9;j++){
			int nfdir = (fdir+j) % 9;
			if(nfdir == 0) continue;
			int nfy = fy + dy[nfdir];
			int nfx = fx + dx[nfdir];	
			if(nfy >= 0 && nfy < 4 && nfx >= 0 && nfx < 4 && ffi.box[nfy][nfx].num != 0){
				if(ffi.box[nfy][nfx].num == -1){
					// just go there				
					//cout << "just move " << "from " << fy << "," << fx << "to " << nfy << "," << nfx << " : " << ffi.box[fy][fx].num << '\n';
					ffi.box[fy][fx].num = -1;
					ffi.box[nfy][nfx].dir = nfdir;					
					ffi.box[nfy][nfx].num = i;
					ffi.m[i] = {nfy, nfx};
				}
				else{
					// swap					
					//cout << "swap" << ffi.box[fy][fx].num << " and " << ffi.box[nfy][nfx].num << '\n';
					ffi.box[fy][fx].dir = nfdir;
					int from = ffi.box[fy][fx].num; int to = ffi.box[nfy][nfx].num;
					//cout << from  << " <=> " << to << '\n';					
					swap(ffi.m[from], ffi.m[to]);
					swap(ffi.box[fy][fx], ffi.box[nfy][nfx]);					
				}
				break;
			}
		}
	}
	//cout << "FISH MOVED===================\n";
	//print(ffi);
	vector<pair<int,int>> next;
	for(int i=1;i<=3;i++){
		int nsy = sy + dy[sdir]*i;
		int nsx = sx + dx[sdir]*i;
		if(nsy >= 0 && nsy < 4 && nsx >= 0 && nsx < 4 && ffi.box[nsy][nsx].num != -1){
			//cout << "can goto " << nsy << "," << nsx << " : " << ffi.box[nsy][nsx].num << '\n';
			next.push_back({nsy, nsx});
		}
	}		
	if(next.empty()) { 
		ans = max(ans, sum); 
		//cout << "========ENDS TURN========= score : " << sum << '\n';
		return;
	}	
	for(int i=0;i<next.size();i++){		
		int nsy = next[i].first;
		int nsx = next[i].second;		
		int kill = ffi.box[nsy][nsx].num;
						
		ffi.box[nsy][nsx].num = 0;		
		ffi.box[sy][sx].num = -1;
		ffi.m.erase(kill);
		//cout << "SHARK MOVED===================\n";
		//print(ffi);
		//cout << "==========KILL : " << kill << '\n';
		go(nsy, nsx, ffi.box[nsy][nsx].dir , ffi, sum + kill);		
		//cout << "REROLL===================\n";
		ffi.box[sy][sx].num = 0;
		ffi.box[nsy][nsx].num = kill;
		ffi.m[kill] = {nsy, nsx};		
	}
	
}

void solve(){		
	int start = fi.box[0][0].num;
	// kill fish (0,0)
	fi.m.erase(start);
	fi.box[0][0].num = 0;
	//print(fi);
	go(0, 0, fi.box[0][0].dir , fi, start);
	
	cout << ans;
}
int main(){	
	input();
	solve();
	return 0;
}
