/*******************************************************************
Algorithm Study
BAEKJOON 21주차
1939 중량제한
2022/10/04 이호준
# 아이디어
1. BFS + 이진탐색
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 100001

using namespace std;

int N, M, Max_Cost, start, End;
bool visited[INF];
vector<pair<int,int>> v[INF];

int bigger(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});

        Max_Cost = bigger(Max_Cost, c);
    }
    cin >> start >> End;
}

bool bfs(int current_cost){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current == End) return true;
        
        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int next_cost = v[current][i].second;

            if(visited[next] == false && current_cost <= next_cost){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

void solution(){
    int low = 0;
    int high = Max_Cost;
    while(low <= high){
        memset(visited, false, sizeof(visited));
        int mid = (low + high) / 2;
        if(bfs(mid)){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << high << "\n";
}

void solve(){
    input();
    solution();
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}

