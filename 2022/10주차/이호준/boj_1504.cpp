/*******************************************************************
Algorithm Study
Baekjoon OJ Dijkstra
1504 특정한 최단 경로
2022/04/03 이호준
# 아이디어
1. 다익스트라 알고리즘을 통해서 구현하는 문제.
정점 2개를 반드시 지난 다는 것은 해당 지점들 까지의 최단거리들을 구해서 구하면 된다는 것이었다.
그래서 v1을 먼저지나는 경로 1개, v2를 먼저지나는 경로 1개를 통해 빠른 경로를 구하고
답을 구한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

int n, e;
vector<pair<int,int>> map[801];
bool cant = false;
int dijkstra(int start, int end);

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> e;

    for(int i = 0 ; i< e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b,c});
        map[b].push_back({a,c});
    }

    int v1,v2;
    cin >> v1 >> v2;

    long long answer = min(dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,n),dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,n));

    if(answer>=INF || cant){
        cout << -1 ;
    }else{
        cout << answer;
    }

    return 0;
}

int dijkstra(int start, int end){

    // {node, distance}
    priority_queue<pair<int,int>> q;
    vector<long long> cost(n+1, INF);

    cost[start] = 0;
    q.push({start, 0});

    while(!q.empty()){
        int current_node = q.top().first;
        int distance = -q.top().second;
        q.pop();

        if(cost[current_node] < distance)
            continue;
        
        for(auto & a : map[current_node]){
            int next_node = a.first;
            int next_distance = a.second + distance;

            if(next_distance < cost[next_node]){
                cost[next_node] = next_distance;
                q.push({next_node, -next_distance});
            }
        }
    }
    // 못지나가는 경우
    if(cost[end]==INF)
        cant = true;

    return cost[end];
}
