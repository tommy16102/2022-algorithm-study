#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int inDegree[1010];
vector<int> adj[1010];
bool v[1010][1010];
vector<int> ans;
void input(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int k;
		cin >> k;
		vector<int> temp(k);
		for(int j=0;j<k;j++){
			cin >> temp[j];
		}
		for(int j=1;j<temp.size();j++){
			// 1->4->3
			if(!v[temp[j-1]][temp[j]]){
				v[temp[j-1]][temp[j]] = true;
				adj[temp[j-1]].push_back(temp[j]);
				inDegree[temp[j]]++;			
			}
		}
	}	
}
void solve(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	for(int i=0;i<n;i++){
		if(q.empty()){
			cout << 0;
			return;
		}
		int now = q.front();
		q.pop();
		ans.push_back(now);
		for(int j=0;j<adj[now].size();j++){
			int next = adj[now][j];
			inDegree[next]--;
			if(inDegree[next] == 0){
				q.push(next);
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << '\n';
	}
}
int main(){
	input();
	solve();
	return 0;
}
