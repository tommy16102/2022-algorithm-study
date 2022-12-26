#include <iostream>
#include <vector>
using namespace std;
bool v[2020];
int n, m;
vector<int> graphs[2020];
bool flag = false;
void input(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		graphs[a].push_back(b);
		graphs[b].push_back(a);
	}
}

void dfs(int depth, int now){
	if(depth == 4){
		flag = true;
		return;
	}
	for(int i=0;i<graphs[now].size();i++){
		int next = graphs[now][i];
		if(!v[next]){
			v[next] = true;
			dfs(depth + 1, next);
		}
	}
	v[now] = false;
}

void solve(){
	for(int i=0;i<n;i++){
		if(flag) break;
		v[i] = true;
		dfs(0, i);
	}
	if(flag) cout << 1;
	else cout << 0;
}
int main(){
	input();
	solve();		
}
