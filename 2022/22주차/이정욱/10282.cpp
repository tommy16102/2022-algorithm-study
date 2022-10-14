#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;

int t,n,d,c,a,b,s;
vector<pair<int, int>> adj[10001];
int dist[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(){
    cin>>n>>d>>c;
    for(int i=0;i<d;i++){
        cin>>a>>b>>s;
        adj[b].push_back({s,a});
    }
    pq.push({0,c});
    dist[c] = 0;
    while(pq.size()){
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;
        for(pair<int, int> there: adj[here]){
            int _dist = there.first;
            int _there = there.second;
            if(dist[_there] > dist[here] + _dist){
                dist[_there] = dist[here] + _dist;
                pq.push({dist[_there], _there});
            }
        }
    }
    int cnt = 0;
    int time = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] == INF) continue;
        cnt++;
        time = max(time, dist[i]);
    }
    cout<<cnt<<" "<<time<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=0;i<10001;i++){
            adj[i].clear();
        }
        fill(dist, dist+10001, INF);
        solve();
    }
}
