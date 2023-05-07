#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
using namespace std;
int p[50505]; int r[50505]; int top[50505]; int bottom[50505];
vector<pair<int,int>> graph[50505];
set<int> gate;
set<int> summit;
int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    if(r[pa] < r[pb]) swap(pa, pb);
    else if(r[pa] == r[pb]) r[pa]++;
    p[pb] = p[pa];
}
bool cmp(vector<int>& p1, vector<int>& p2){
    return p1[2] < p2[2];
}
int n;
vector<pair<int,int>> mst[50505];
int bfs(int start){
    queue<int> q;
    q.push(start);
    vector<int> intensity(n+1, -1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<mst[cur].size();i++){
            int next = mst[cur][i].first;
            int nextCost = mst[cur][i].second;
            if(intensity[next] != -1 || top[next]) continue;
            intensity[next] = max(intensity[cur], nextCost);
            if(bottom[next]) continue;
            q.push(next);
        }
    }
    int ret = 2000000000;
    for(int g : gate){
        if(intensity[g] != -1) ret = min(ret, intensity[g]);
    }
    return ret;
}
vector<int> solution(int nn, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {   
    n = nn;
    for(auto g : gates) {bottom[g] = 1; gate.insert(g);}    
    for(auto s : summits) {top[s] = 1; summit.insert(s);}
    set<int> wset;
    for(int i=0;i<50505;i++) {
        p[i] = i;
    }
    vector<int> answer = {0, 2000000000};    
    sort(paths.begin(), paths.end(), cmp);
    set<int> gs; set<int> ss;
    int cnt = 0;
    for(vector<int>& edge : paths){
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        if(find(from) != find(to)){
            merge(from, to);
            mst[from].push_back({to, cost});
            mst[to].push_back({from, cost});
            if(++cnt == n-1) break;
        }
    }
    for(int s : summit){
        int temp = bfs(s);
        if(temp < answer[1])
            answer = {s, temp};
        
    }
    return answer;
}
