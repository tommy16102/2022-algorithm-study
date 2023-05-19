/*******************************************************************
Algorithm Study
Baekjoon 17135 캐슬디펜스
2023/05/19 이호준
# 아이디어
1. Combination & BFS
*******************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define SIZE 16

using namespace std;

int answer = 0;
int n, m, d;
vector<vector<int>> gameBoard;

int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

bool visited[SIZE][SIZE];

void killEnemy(vector<int> combination, int enemy){
    int killCount = 0;
    int dieArcher = 0;
    vector<int> archers;
    vector<vector<int>> board = gameBoard;
    for(int i = 0; i < combination.size(); ++i){
        if(combination[i] == 1)
            archers.push_back(i);
    }
    for(int stage = 0; stage < n; ++stage){
        if(dieArcher == enemy)
            break;
        
        vector<pair<int,int>> die;
        for(int archer : archers){
            queue<pair<pair<int,int>, int>> q;
            q.push({{n, archer}, 0});
            while(!q.empty()){
                int current_x = q.front().first.first;
                int current_y = q.front().first.second;
                int distance = q.front().second;
                q.pop();
                if(board[current_x][current_y] == 1){
                    die.push_back({current_x, current_y});
                    break;
                }

                for(int dir = 0; dir < 3; ++dir){
                    int next_x = current_x + dx[dir];
                    int next_y = current_y + dy[dir];

                    if(distance + 1 <= d){
                        if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m){
                            if(!visited[next_x][next_y]){
                                visited[next_x][next_y] = true;
                                q.push({{next_x, next_y}, distance + 1});
                            }
                        }
                    }
                }
            }
            fill(&visited[0][0], &visited[SIZE][0], false);
        }

        die.erase(unique(die.begin(), die.end()), die.end());
        killCount += die.size();
        dieArcher += die.size();

        for(pair<int,int> enemy : die){
            board[enemy.first][enemy.second] = 0;
        }

        for(int j = 0; j < m; ++j){
            if(board[n - 1][j] == 1){
                dieArcher++;
                board[n - 1][j] = 0;
            }
        }
        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < m; ++j){
                board[i + 1][j] = board[i][j];
                board[i][j] = 0;
            }
        }        
    }
    answer = max(answer, killCount);
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int temp, enemy = 0;
    cin >> n >> m >> d;

    gameBoard = vector<vector<int>>(n + 1, vector<int>(m, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> temp;
            if(temp == 1)
                enemy++;
            gameBoard[i][j] = temp;
        }
    }

    vector<int> combination = vector<int>(m, 0);

    for(int i = 1; i <= 3; i++)
        combination[m - i] = 1;

    do{
       killEnemy(combination, enemy);
    }while(next_permutation(combination.begin(), combination.end()));

    cout << answer;
     
    return 0;
}