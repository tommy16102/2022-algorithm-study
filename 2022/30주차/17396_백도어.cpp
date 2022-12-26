#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;
bool vision[101010];
ll d[101010];
vector<pair<ll,ll>> graph[101010];
const ll INF = 10000000001;
void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> vision[i];
	}
	for(int i=0;i<m;i++){
		int a, b, t;
		cin >> a >> b >> t;
			
		if((!vision[b] && a == n-1) || (!vision[a] && b == n-1) || (!vision[a] && !vision[b])){			
			graph[a].push_back({t, b});
			graph[b].push_back({t, a});
		}
			
	}
	for(int i=0;i<101010;i++){
		d[i] = INF;
	}
}

void djikstra(int start){
	d[start] = 0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0, start});
	while(!pq.empty()){
		pair<ll,ll> now = pq.top();
		pq.pop();		
		ll nowCost = -now.first;
		int nowId = now.second;
		if(d[nowId] < nowCost) continue; // 최소 비용 알고 있으면 스킵
		for(int i=0;i<graph[nowId].size();i++){
			pair<ll,ll> next = graph[nowId][i];
			ll add = next.first;
			int nextId = next.second;
			if(d[nextId] > nowCost + add){
				d[nextId] = nowCost + add;
				pq.push({-d[nextId], nextId});
			}
		}
	}
}

void solve(){
	djikstra(0);
	if(d[n-1] == INF) cout << -1;
	else cout << d[n-1];	
}
int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	input();
	solve();
	return 0;
}
