#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int p[202];
vector<int> v;
int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa == pb) return;
	p[pb] = p[pa];
}
void input(){
	cin >> n >> m;
	for(int i=0;i<202;i++) p[i] = i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int v;
			cin >> v;
			if(v == 1){
				merge(i, j);
			}
		}
	}
	v = vector<int>(m);
	for(int i=0;i<m;i++) cin >> v[i];
}
void solve(){
	if(m == 0) {
		cout << "YES"; return;
	}
	int start = find(v[0]);
	for(auto e : v){
		if(start != find(e)){
			cout << "NO"; return;
		}
	}
	cout << "YES";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);		
	input();
	solve();		
	return 0;
}
