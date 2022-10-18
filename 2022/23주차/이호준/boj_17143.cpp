/*******************************************************************
17143 낚시왕
2022/10/18 이호준
# 아이디어
1. 
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upDownX[2] = {-1, 1};
int upDownY[2] = {0, 0};

int leftRightX[2] = {0, 0};
int leftRightY[2] = {1, -1};

struct Shark{
    int speed;
    int direction;
    int size;
};


int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int r, c, m;

    cin >> r >> c >> m;

    vector<Shark> map[r][c];

    for(int i = 0; i < m; i++){
        int x, y, speed, direction, size;
        cin >> x >> y >> speed >> direction >> size;
        map[x - 1][y - 1].push_back(Shark{speed, direction, size});
    }
    // cout <<"\n\n";
    // for(int a = 0; a < r; a++){
    //         for(int b = 0; b < c; b++){
    //             if(!map[a][b].empty()){
    //                 Shark s = map[a][b][0];
    //                 cout << a << " " << b << " " << s.size << " " << s.direction << " " << s.speed << " " << map[a][b].size() <<"\n";
    //             }
    //         }
    //     }
    //     cout << "\n\n";

    int deathSharkSize = 0;

    for(int i = 0; i < c; i++){
        // 낚시왕 땅에 제일 가까운 상어 죽기
        for(int a = 0; a < r; a++){
            if(!map[a][i].empty()){
                deathSharkSize += map[a][i][0].size;
                map[a][i].clear();
                break;
            }
        }
        // 상어 이동
        vector<Shark> temp[r][c];
        for(int a = 0; a < r; a++){
            for(int b = 0; b < c; b++){
                if(!map[a][b].empty()){
                    Shark current_shark = map[a][b][0];
                    int current_direction = current_shark.direction;
                    int speed = current_shark.speed;
                    int next_x = a;
                    int next_y = b;
                    if(current_direction == 1 || current_direction == 2){
                        int time = speed % ((r - 1) * 2);
                        while(time != 0){
                            next_x = next_x + upDownX[current_direction - 1];
                            next_y = next_y + upDownY[current_direction - 1];
                            if(next_x < 0 || next_x >=r || next_y <0 || next_y >=c){
                                current_direction = current_direction == 1 ? 2 : 1;
                                next_x = next_x + upDownX[current_direction - 1] * 2;
                                next_y = next_y + upDownY[current_direction - 1] * 2;
                            }
                            time--;
                        }
                        temp[next_x][next_y].push_back(Shark{speed, current_direction, current_shark.size});
                    }else{
                        while(time != 0){
                            int time = speed % ((c - 1) * 2);
                            next_x = next_x + leftRightX[current_direction - 3];
                            next_y = next_y + leftRightY[current_direction - 3];
                            if(next_x < 0 || next_x >=r || next_y < 0 || next_y >=c ){
                                current_direction = current_direction == 3 ? 4 : 3;
                                next_x = next_x + leftRightX[current_direction - 3] * 2;
                                next_y = next_y + leftRightY[current_direction - 3] * 2;
                            }
                            time--;
                        }
                        temp[next_x][next_y].push_back(Shark{speed, current_direction, current_shark.size});
                    }
                }
            }
        }
        
        // 상어 여러개 확인
        for(int a = 0; a < r; a++){
            for(int b = 0; b < c; b++){
                if(temp[a][b].size() >= 2){
                    int max_index;
                    int max_size = 0;
                    for(int j = 0; j < temp[a][b].size(); j++){
                        int current_size = temp[a][b][j].size;
                        if(max_size < current_size){
                            max_size = current_size;
                            max_index = j;
                        }
                    }
                    Shark temp_shark = temp[a][b][max_index];
                    temp[a][b].clear();
                    temp[a][b].push_back(temp_shark);
                }
            }
        }

        for(int a= 0 ; a < r; a++){
            for(int b = 0; b < c; b++){
                map[a][b] = temp[a][b];
            }
        }

        // for(int a = 0; a < r; a++){
        //     for(int b = 0; b < c; b++){
        //         if(!map[a][b].empty()){
        //             Shark s = map[a][b][0];
        //             cout << a << " " << b << " " << s.size << " " << s.direction << " " << s.speed << " " << map[a][b].size() <<"\n";
        //         }
        //     }
        // }
        // cout << "\n\n";
    }
    cout << deathSharkSize;

}