/*******************************************************************
Algorithm Study
Baekjoon 2630 색종이
2023/05/18 이호준
# 아이디어
1. 재귀
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int blue, white;
vector<vector<int>> map;

void makeColorPaper(int x, int y, int n){
    int current_color = map[x][y];
    if (n == 1){
        if(current_color) blue++;
        else white++;
        return;
    }
    bool escapeFlag = false;
    for(int i = x; i < x + n; i++){
        if(escapeFlag)
            break;
        for(int j = y; j < y + n; j++){
            if(map[i][j] != current_color){
                escapeFlag = true;
                break;
            }
        }
    }

    if(escapeFlag){
        n /= 2;
        makeColorPaper(x, y, n);
        makeColorPaper(x + n, y, n);
        makeColorPaper(x, y + n, n);
        makeColorPaper(x + n, y + n, n);
    }else{
        if(current_color) blue++;
        else white++;
    }

}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    map = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> map[i][j];
        }
    }

    makeColorPaper(0, 0, n);


    cout << white << "\n" << blue <<"\n";

    return 0;
}