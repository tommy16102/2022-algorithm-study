#include <iostream>
#include <vector>
using namespace std;
int t;
int n;
int from, to;
vector<int> childs[10101];
int parent[10101];
void input(){
	for(int i=0;i<10101;i++){
		childs[i].clear();
		parent[i] = -1;
	}
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		childs[a].push_back(b);
		parent[b] = a;
		//childs[b].push_back(a);
	}
	cin >> from >> to;
}
void solve(){
	vector<pair<int,int>> fromParents;
	int depth = 0;
	while(from != -1){
		fromParents.push_back({depth, from});
		from = parent[from];
		depth++;
	}
	
	vector<pair<int,int>> toParents;
	depth = 0;
	while(to != -1){
		toParents.push_back({depth, to});
		to = parent[to];
		depth++;
	}
	
	for(int i=0;i<fromParents.size();i++){
		int now = fromParents[i].second;
		for(int j=0;j<toParents.size();j++){
			if(now == toParents[j].second){
				cout << now << '\n';
				return;
			}
		}
	}

}

int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
