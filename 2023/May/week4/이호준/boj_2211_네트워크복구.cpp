/*******************************************************************
Algorithm Study
Baekjoon 2211 네트워크 복구
2023/05/25 이호준
# 아이디어
1. 다잌스트라
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 2100000000

using namespace std;

vector<pair<int,int>> graph[1001];

int cost[1001];
int before[1001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x].push_back({y, cost});
        graph[y].push_back({x, cost});
    }

    // {cost, node}
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    for(int i = 2; i <= n; ++i)
        cost[i] = INF;
    
    while(!q.empty()){
        int current_cost = -q.top().first;
        int current_node = q.top().second;
        q.pop();

        if(cost[current_node] < current_cost)
            continue;
        
        for(pair<int,int> node : graph[current_node]){
            int next_cost = current_cost + node.second;
            if(cost[node.first] > next_cost){
                cost[node.first] = next_cost;
                before[node.first] = current_node;
                q.push({-next_cost, node.first});
            }
        }
    }

    set<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i){
        int node = i;
        while(node != 1){
            edges.insert({min(node, before[node]), max(node, before[node])});
            node = before[node];
        }
    }

    cout << edges.size() <<"\n";
    for(pair<int,int> edge : edges){
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}