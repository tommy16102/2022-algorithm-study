#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<pair<int,int>> graph[1010];
int p[1010];
int d[1010];
void input(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({cost, to});
		graph[to].push_back({cost, from});
	}
}
void djikstra(int start){
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<1010;i++){
		d[i] = 987654321;		
	}
	d[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		pair<int,int> cur = pq.top();
		pq.pop();
		int nowCost = -cur.first;
		int nowId = cur.second;
		if(d[nowId] < nowCost) continue;
		for(int i=0;i<graph[nowId].size();i++){
			int nextId = graph[nowId][i].second;
			int add = graph[nowId][i].first;
			int nextCost = nowCost + add;
			if(nextCost < d[nextId]){
				p[nextId] = nowId;
				d[nextId] = nextCost;
				pq.push({-nextCost, nextId});
			}			
		}
	}
}
void solve(){
	djikstra(1);
	cout << n-1 << '\n';
	for(int i=2;i<=n;i++){
		cout << min(i, p[i]) << " " << max(i, p[i]) << '\n';
	}
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
