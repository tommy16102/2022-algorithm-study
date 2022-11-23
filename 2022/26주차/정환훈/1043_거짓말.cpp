#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, truth;
vector<int> trues;
vector<int> party[55];
int p[55];
void input(){
	cin >> n >> m >> truth;
	trues = vector<int>(truth);
	for(int i=0;i<truth;i++){
		cin >> trues[i];
	}
	for(int i=0;i<m;i++){
		int howcome;
		cin >> howcome;
		for(int j=0;j<howcome;j++){
			int k;
			cin >> k;
			party[i].push_back(k);
		}
		
	}
}

int findParent(int x){
	if(p[x] == x) return x;
	return p[x] = findParent(p[x]);
}

void uni(int a, int b){
	a = findParent(a);
	b = findParent(b);
	if(a == b){
		return;
	}	
	p[b] = a;
}

bool sameParent(int a, int b){
	a = findParent(a);
	b = findParent(b);
	if(a == b) return true;
	return false;
}

void solve(){
	int ans = m;
	for(int i=1;i<=n;i++){
		p[i] = i;
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<party[i].size();j++){
			uni(party[i][0], party[i][j]);
		}
	}
	
	for(int i=0;i<m;i++){
		bool go = true;
		for(int j=0;j<party[i].size();j++){
			if(!go) break;
			for(int k=0;k<trues.size();k++){
				if(sameParent(party[i][j], trues[k])){
					go = false;
					break;
				}
			}
		}
		if(!go) ans--;
	}
	
	cout << ans << '\n';
}

int main(){
	input();
	solve();
	return 0;
}
