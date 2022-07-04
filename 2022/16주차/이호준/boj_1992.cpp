/*******************************************************************
Algorithm Study
Baekjoon OJ 재귀
1992 쿼드트리
2022/07/04 이호준
# 아이디어
1. 재귀이용 알고리즘
   -> 영역내 다른 부분이 존재하면 -> 탐색범위를 1/2 하여 재귀로 다시 탐색
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> map(64, vector<int>(64, 0));


string imageCompression(int size, int x, int y){
    int check_value = map[x][y];
    bool division = false;
    cout << size << " " << x << " " << y << "\n";
    for(int i = x; i< x + size; i++){
        if(division){
                break;
        }
        for(int j = y; j < y + size; j++ ){
            if(check_value != map[i][j]){
                division = true;
                break;
            }
        }
    }
    if(division){
        size /= 2;
        string temp = "(";
        temp += (imageCompression(size, x, y) + imageCompression(size, x , y + size) 
                + imageCompression(size, x + size, y) + imageCompression(size, x + size, y + size) );
        return temp + ")";

    }else{
        if(check_value == 1){
            return "1";
        }else{
            return "0";
        }
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        string line;
        getline(cin, line);
        for(int j = 0 ; j < N; j++){
            map[i][j] = line[j] - '0' ;
        }
    }
    // for(auto a : map){
    //     for(auto b : a)
    //          cout << b << " ";
    //     cout << "\n";
    // }
    cout << imageCompression(N, 0, 0);


    return 0;
}