/*******************************************************************
Algorithm Study
Baekjoon 17142 연구소 3
2023/05/24 이호준
# 아이디어
1. Combination && BFS
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer = INT32_MAX;
vector<vector<int>> graph;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

int n;
int emptySize = 0;

void visualizeMap(vector<vector<int>> map){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << map[i][j] << " ";
        cout <<"\n";
    }
    cout <<"\n\n";
}
 
void activeVirus(vector<bool> combination, vector<pair<int,int>> virus){
    vector<vector<int>> checkGraph(n, vector<int>(n, INT32_MAX));

    priority_queue<pair<int, pair<int,int>>> q;
    for(int i = 0; i < combination.size(); ++i){
        if(combination[i]){
            q.push({0, {virus[i].first, virus[i].second}});
        }else{
            graph[virus[i].first][virus[i].second] = 0;
        }
    }

    while(!q.empty()){
        int current_x = q.top().second.first;
        int current_y = q.top().second.second;
        int cost = -q.top().first;
        q.pop();

        if(checkGraph[current_x][current_y] != INT32_MAX && checkGraph[current_x][current_y] < cost)
            continue;

        for(int dir = 0; dir < 4; ++dir){
            int next_x = current_x + dx[dir];
            int next_y = current_y + dy[dir];

            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n){
                if(graph[next_x][next_y] == 0 && checkGraph[next_x][next_y] > cost + 1){
                    checkGraph[next_x][next_y] = cost + 1;
                    q.push({-(cost + 1), {next_x, next_y}});
                }
            }
        }
    }

    for(int i = 0; i < combination.size(); ++i){
        graph[virus[i].first][virus[i].second] = 2;
    }

    int time = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(flag)
            break;
        for(int j = 0; j < n; ++j){
            if(graph[i][j] == 0){
                if(checkGraph[i][j] != INT32_MAX){
                    time = max(time, checkGraph[i][j]);
                }else{
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag)
        answer = min(answer, time);
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    graph = vector<vector<int>>(n, vector<int>(n, 0));

    vector<pair<int,int>> virus;
    int temp;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> temp;
            graph[i][j] = temp;
            if(temp == 2)
                virus.push_back({i, j});
        }
    }

    int virusSize = virus.size();
    vector<bool> combination(virusSize, false);
    for(int i = 0; i < m; i++){
        combination[virusSize - 1 - i] = true;
    }

    do{
        activeVirus(combination, virus);
    }while(next_permutation(combination.begin(), combination.end()));


    if(answer != INT32_MAX)
        cout << answer;
    else
        cout << -1;

    return 0;
}