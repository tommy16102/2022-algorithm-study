#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX (500 + 100) * 25 * 25 + 1

using namespace std;

int arr[26][26][4];
queue<pair<pair<int,int>,int>> q;
int moveI[4] = {-1, 0, 1, 0};
int moveJ[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    
    int I = board.size();
    int J = board[0].size();
    
    q.push({ {0,0}, -1});
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            for(int k = 0; k < 4; k++){
                arr[i][j][k] = MAX;
            }
        }
    }
    
    arr[0][0][0] = 0;
    arr[0][0][1] = 0;
    arr[0][0][2] = 0;
    arr[0][0][3] = 0;
    
    while (!q.empty()) {
        int nowI = q.front().first.first;
        int nowJ = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextI = nowI + moveI[i];
            int nextJ = nowJ + moveJ[i];
            if (nextI < 0 || nextJ < 0 || nextI >= I || nextJ >= J) continue;
            if (board[nextI][nextJ] == 1) continue;
            if (dir == -1){
                arr[nextI][nextJ][i] = arr[nowI][nowJ][0] + 100;
            }
            else if (i == dir){
                if (arr[nextI][nextJ][i] < arr[nowI][nowJ][dir] + 100) continue;
                arr[nextI][nextJ][i] = min(arr[nextI][nextJ][i], arr[nowI][nowJ][dir] + 100);
            }
            else {
                if (arr[nextI][nextJ][i] < arr[nowI][nowJ][dir] + 100 + 500) continue;
                arr[nextI][nextJ][i] = min(arr[nextI][nextJ][i], arr[nowI][nowJ][dir] + 100 + 500);
            }
            q.push({ {nextI, nextJ}, i});
        }
    }
    
    int ans = arr[I-1][J-1][0];
    for(int i=1;i<=3;i++){
        ans = min(ans, arr[I-1][J-1][i]);
    }
    
    return ans;
}
