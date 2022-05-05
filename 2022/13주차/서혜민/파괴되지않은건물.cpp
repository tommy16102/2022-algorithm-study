#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int h = board.size();
    int l = board[0].size();
    int cnt = 0;
    
    for (int i = 0; i < skill.size(); i++) {
        
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        int mul = (type == 1) ? -1 : 1;
        degree *= mul;
        
        arr[r1][c1] += degree;
        arr[r2 + 1][c2 + 1] += degree;
        arr[r1][c2 + 1] += -degree;
        arr[r2 + 1][c1] += -degree;   
        
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 1; j < l; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 1; j < h; j++) {
            arr[j][i] += arr[j - 1][i];
        }
    } 
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            board[i][j] += arr[i][j];
        }
    }
    
    for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                if (board[i][j] > 0) cnt++;
            }
        }
    
    return cnt;
}
