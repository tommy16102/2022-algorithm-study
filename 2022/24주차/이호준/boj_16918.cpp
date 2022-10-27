/*******************************************************************
16918 봄버맨
2022/10/27 이호준
# 아이디어
1. 구현
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool visited[201][201];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int r,c,n;

    cin >> r >> c >> n;

    vector<vector<int>> map(r, vector<int>(c, -1));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char temp;
            cin >> temp;
            if(temp == 'O'){
                map[i][j] = 0;
            }
        }
    }
    int time = 2;
    
    while(time != n + 1){

        if(time % 2 == 0){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(map[i][j] == -1){
                        map[i][j] = 1;
                    }
                }
            }
        }else{
            vector<vector<int>> temp = map;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(map[i][j] == 0){
                        temp[i][j] = -1;
                        for(int a = 0; a < 4; a++){
                            int next_x = i + dx[a];
                            int next_y = j + dy[a];
                            if(next_x >= 0 && next_x < r && next_y >= 0 && next_y < c){
                                temp[next_x][next_y] = -1;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(temp[i][j] != -1){
                        temp[i][j] = 0;
                    }
                    map[i][j] = temp[i][j];
                }
            }
        }
        time++;
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int node = map[i][j];
            if(node == 0 || node == 1){
                cout << 'O';
            }else{
                cout << '.';
            }
        }
        cout <<"\n";
    }

    return 0;
}