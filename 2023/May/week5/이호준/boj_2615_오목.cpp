/*******************************************************************
Algorithm Study
Baekjoon 2615 오목
2023/06/02 이호준
# 아이디어
1. 구현
*******************************************************************/

#include <iostream>

#define SIZE 19

using namespace std;

int board[SIZE][SIZE];

int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

bool inRange(int x, int y){
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            cin >> board[i][j];
        }
    }

    bool gameFlag = false;
    int winnerColor;
    pair<int,int> start_point;
    for(int i = 0; i < SIZE; ++i){
        if(gameFlag)
            break;
        for(int j = 0; j < SIZE; ++j){
            if(gameFlag)
                break;
            if(board[i][j]){
                int current_color = board[i][j];
                for(int dir = 0; dir < 4; ++dir){
                    int next_x = i, next_y = j;
                    int sequence = 1;
                    int check_x = i - dx[dir];
                    int check_y = j - dy[dir];
                    if(inRange(check_x, check_y)){
                        if(board[check_x][check_y] == current_color)
                            continue;
                    }
                    for(int a = 0; a < 5; ++a){
                        next_x += dx[dir];
                        next_y += dy[dir];
                        if(inRange(next_x, next_y)){
                            // cout << i << " " << j << ": -> " << next_x << " " << next_y <<"\n";
                            if(board[next_x][next_y] != current_color){
                                break;
                            }                     
                            sequence++;
                        }
                    }
                    if(sequence == 5){
                        gameFlag = true;
                        winnerColor = current_color;
                        start_point = {i + 1, j + 1};
                        break;
                    }
                }
            }
        }
    }

    if(!gameFlag){
        cout << 0;
    }else{
        cout << winnerColor << "\n";
        cout << start_point.first<< " " << start_point.second<<"\n";
    }

    return 0;
}