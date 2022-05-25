/*******************************************************************
Algorithm Study
Baekjoon OJ 
14499 주사위 굴리기
2022/04/12 이호준
# 아이디어
1. 주사위를 가지고 구현
순수 구현문제
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m ,x, y, k;

    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        for(int j =0; j<m ; j++){
            cin >> map[i][j];
        }
    }

    vector<int> horizon(3, 0);
    vector<int> vertical(4, 0);

    int top = 0;
    int left = 0;

    for(int i = 0; i< k; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 4){
            // 남쪽
            if(x+1 < n){
                x++;
                top++;
                if(top >3){
                    top = 0;
                }
                int change_horizon = left+1;
                int bottom = top+2;
                if(bottom>3){
                    bottom = bottom-4;
                }
                if(change_horizon>2){
                    change_horizon = 0;
                }
                horizon[change_horizon] = vertical[bottom];
                if(map[x][y] == 0){
                    map[x][y] = vertical[bottom];
                }else{
                    vertical[bottom] = map[x][y];
                    horizon[change_horizon] = map[x][y];
                    map[x][y] = 0;  
                }
                cout << vertical[top] << "\n";
            }

        }else if(cmd == 3){
            // 북쪽
            if(x-1 >=0){
                x--;
                top--;
                if(top<0){
                    top = 3;
                }
                int change_horizon = left+1;
                int bottom = top+2;
                if(bottom>3){
                    bottom = bottom-4;
                }
                if(change_horizon>2){
                    change_horizon = 0;
                }
                horizon[change_horizon] = vertical[bottom];
                if(map[x][y] == 0){
                    map[x][y] = vertical[bottom];
                }else{
                    vertical[bottom] = map[x][y];
                    horizon[change_horizon] = map[x][y];
                    map[x][y] = 0;  
                }
                cout << vertical[top] << "\n";
            }

        }else if(cmd == 2){
            // 서쪽
            if(y-1 >=0){
                y--;
                int center, right;
                center = left + 1;
                right  = left + 2;
                if(right > 2){
                    right = right-3;
                }
                if(center > 2){
                    center = right-3;
                }
                int legacy_center = horizon[center];
                int legacy_right = horizon[right];
                horizon[center] = horizon[left];
                int bottom = top+2;
                if(bottom>3){
                    bottom = bottom-4;
                }
                horizon[right] = vertical[bottom];
                horizon[left] = vertical[top];
                vertical[top] = legacy_right;

                int change_horizon = left+1;
                if(change_horizon>2){
                    change_horizon = 0;
                }
                vertical[bottom] = horizon[change_horizon];
                if(map[x][y] == 0){
                    map[x][y] = vertical[bottom];
                }else{
                    vertical[bottom] = map[x][y];
                    horizon[change_horizon] = map[x][y];
                    map[x][y] = 0; 
                }
                cout << vertical[top] << "\n";
            }

        }else{
            // 동쪽
            if(y+1 < m){
                y++;
                int center, right;
                center = left + 1;
                right  = left + 2;
                if(right > 2){
                    right = right-3;
                }
                if(center > 2){
                    center = right-3;
                }
                int legacy_right = horizon[right];
                int legacy_left = horizon[left];
                horizon[center] = legacy_right;
                int bottom = top+2;
                if(bottom>3){
                    bottom = bottom-4;
                }
                horizon[right] = vertical[top];
                horizon[left] = vertical[bottom];
                vertical[top] = legacy_left;

                int change_horizon = left+1;
                if(change_horizon>2){
                    change_horizon = 0;
                }
                vertical[bottom] = legacy_right;
                if(map[x][y] == 0){
                    map[x][y] = vertical[bottom];
                }else{
                    vertical[bottom] = map[x][y];
                    horizon[change_horizon] = map[x][y]; 
                    map[x][y] = 0; 
                }
                cout << vertical[top] << "\n";
            }
        }
    }

    return 0;
}