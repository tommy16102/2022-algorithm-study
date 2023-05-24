#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t;
int r[51]; int p[51];
vector<int> party[51];
vector<int> tt;
int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa == pb) return;
	if(r[pa] < r[pb]) swap(pa, pb);
	if(r[pa] == r[pb]) r[pa]++;
	p[pb] = p[pa];
}
void input(){
	cin >> n >> m >> t;	
	tt = vector<int>(n);
	for(int i=0;i<51;i++){
		p[i] = i;
	}

	for(int i=0;i<t;i++){
		cin >> tt[i];
	}
	for(int i=0;i<tt.size();i++){
		merge(tt[0], tt[i]);
	}
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		party[i] = vector<int>(x);
		for(int j=0;j<x;j++){
			cin >> party[i][j];			
		}
	}	
}
void solve(){
	int ans = 0;
	if(tt.size() == 0){
		cout << m;
		return;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<party[i].size();j++){
			merge(party[i][j], party[i][0]);			
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<party[i].size();j++){
			if(find(party[i][j]) == find(tt[0])){
				break;
			}
			if(j == party[i].size()-1){
				ans++;
			}
		}
	}
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
