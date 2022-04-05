/*******************************************************************
Algorithm Study
Baekjoon OJ Dijkstra
11779 최소비용 구하기2
2022/04/03 이호준
# 아이디어
1. 다익스트라 기본문제 및 경로 탐색.
경로는 다음 next값에 이전 node의 정보를 추가하는 식으로 backtracking한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

int n, m;
vector<pair<int,int>> map[1001];
int trace[1001];

int dijkstra(int start, int end);

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b,c});
    }

    int start, end;
    cin >> start >> end;

    cout << dijkstra(start,end) <<"\n";
    vector<int> roots;
    int current = end;
    while(1){
        if(current == start){
            roots.push_back(start);
            break;
        }else{
            roots.push_back(current);
            current = trace[current];
        }
    }

    cout << roots.size() << '\n';
    for(int i = roots.size()-1; i>=0; i--)
        cout << roots[i] << " ";

    return 0;
}

int dijkstra(int start, int end){

    vector<long long> cost(n+1, INF);

    cost[start] = 0;
    // {node, distace}
    priority_queue<pair<int,int>> q;
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
                trace[next_node] = current_node;
            }
        }
    }
    return cost[end];
}