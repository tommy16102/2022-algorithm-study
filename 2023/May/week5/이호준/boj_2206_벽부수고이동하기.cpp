/*******************************************************************
Algorithm Study
Baekjoon 2206 벽 부수고 이동하기
2023/06/02 이호준
# 아이디어
1. BFS
2. costs를 생각할 필요 없이 먼저 그 방에 들가면 장땡. (처음에 부셨을 때, 안 부셨을 때를 구분하지 않고 생각했어서 잘못 품)
-> 느리지만 통과
-> Best는 visited로만 구분 (costs고려할 필요 없음)
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define INF 2100000000
#define BLOCK 1
#define EMPTY 0

using namespace std;

int n, m;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int costs[1001][1001][2];

bool inRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i){
        string temp;
        cin >> temp;
        for(int j = 0; j < m; ++j){
            board[i][j] = temp[j] - '0';
        }
    }

    pair<int,int> endPoint = {n - 1, m - 1};
    queue<pair<pair<int,int>, pair<bool, int>>> q;
    q.push({{0, 0}, {false, 0}});

    fill(&costs[0][0][0], &costs[n][m][2], INF);
    costs[0][0][0] = 0;

    while(!q.empty()){
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        bool isCrash = q.front().second.first;
        int current_step = q.front().second.second;
        q.pop();

        if(current_x == endPoint.first && current_y == endPoint.second){
            cout << current_step + 1<< "\n";
            return 0;
        }

        for(int dir = 0; dir < 4; dir++){
            int next_x = current_x + dx[dir];
            int next_y = current_y + dy[dir];

            if(inRange(next_x, next_y)){
                if(board[next_x][next_y] == BLOCK){
                    if(!isCrash && costs[next_x][next_y][true] > current_step + 1){
                        costs[next_x][next_y][true] = current_step + 1;
                        q.push({{next_x, next_y}, {true, current_step + 1}});
                    }
                }else{
                    if(costs[next_x][next_y][isCrash] > current_step + 1){
                        costs[next_x][next_y][isCrash] = current_step + 1;
                        q.push({{next_x, next_y}, {isCrash, current_step + 1}});
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}