#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t;
int n; int d; int c;
bool infected[10001];
int dis[10001];
vector<pair<int,int>> connected[10001];
void input(){
	
	for(int i=0;i<10001;i++){
		infected[i] = false;
		connected[i].clear();
		dis[i] = 987654321;
	}
	
	cin >> n >> d >> c;
	for(int i=0;i<d;i++){
		int a; int b; int s;
		cin >> a >> b >> s;
		connected[b].push_back({a, s});
		// a depends on b b -> a 
	}
}
void solve(){
	bool end = false;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, c});
	dis[c] = 0;
	infected[c] = true;
	while(!pq.empty()){
		pair<int,int> now = pq.top();
		int infectId = now.second;
		int infectTime = now.first;
		pq.pop();
		for(int i=0;i<connected[infectId].size();i++){
			pair<int,int> next = connected[infectId][i];
			int nextId = next.first;
			int nextTime = next.second;
			if(dis[infectId] + nextTime < dis[nextId]){
				dis[nextId] = dis[infectId] + nextTime;
				pq.push({dis[infectId] + infectTime, nextId});
				infected[nextId] = true;
			}
		}		
	}
	int infects = 0;
	int time = 0;
	for(int i=1;i<=n;i++){
		if(infected[i]){
			infects++;
			time = max(time, dis[i]);			
		}

	}
	cout << infects << " " << time << '\n';
}

int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
