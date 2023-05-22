/*******************************************************************
Algorithm Study
Baekjoon 2638 치즈
2023/05/22 이호준
# 아이디어
1. BFS
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define BLANK 0
#define CHEEZE 1
#define AIR 2

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;

vector<vector<int>> graph;

void visualizeGraph(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout <<"\n\n";
}

bool inRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void updateAir(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; ++dir){
            int next_x = current_x + dx[dir];
            int next_y = current_y + dy[dir];
            if(inRange(next_x, next_y)){
                if(graph[next_x][next_y] == BLANK){
                    q.push({next_x, next_y});
                    graph[next_x][next_y] = AIR;
                }
            }
        }
    }
}

vector<pair<int,int>> findMeltCheeze(vector<pair<int,int>> cheezes, int& meltCheezeSize){
    vector<pair<int,int>> meltCheeze;
    for(pair<int,int> cheeze : cheezes){
        if(graph[cheeze.first][cheeze.second] == AIR) continue;
        int faceAirCount = 0;
        for(int dir = 0; dir < 4; ++dir){
            int air_x = cheeze.first + dx[dir];
            int air_y = cheeze.second + dy[dir];
            if(inRange(air_x, air_y)){
                if(graph[air_x][air_y] == AIR)
                    faceAirCount++;
            }
            if(faceAirCount >= 2){
                meltCheeze.push_back({cheeze.first, cheeze.second});
                meltCheezeSize++;
                break;
            }
        }
    }
    return meltCheeze;
}

void meltCheeze(vector<pair<int,int>> meltCheeze){
    for(pair<int,int> cheeze : meltCheeze){
        graph[cheeze.first][cheeze.second] = AIR;
        updateAir(cheeze.first, cheeze.second);
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int temp;
    cin >> n >> m;

    graph = vector<vector<int>>(n, vector<int>(m, 0));
    vector<pair<int,int>> cheezes;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> temp;
            graph[i][j] = temp;
            if(temp == 1)
                cheezes.push_back({i, j});
        }
    }

    updateAir(0, 0);
    
    int step = 0;
    int meltCheezeSize = 0;
    int cheezeSize = cheezes.size();

    while(meltCheezeSize < cheezeSize){
        step++;
        vector<pair<int,int>> meltCheezeCandidates = findMeltCheeze(cheezes, meltCheezeSize);
        meltCheeze(meltCheezeCandidates);
    }
    
    cout << step;

    return 0;
}