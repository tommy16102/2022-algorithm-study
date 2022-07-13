#include <string>
#include <vector>
#include <queue>
using namespace std;

bool checked[31][31];
char arr[31][31];
int moveI[4] = {0, 0, 1, 1};
int moveJ[4] = {0, 1, 1, 0};
int ans = 0;

bool remove(int m, int n) {
    
    int removeCnt = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            char c = arr[i][j];
            if (c == ' ') {
                checked[i][j] = 1;
                continue;
            }
            
            int cnt = 0;
            
            for (int k = 1; k <= 3; k++) {
                int nextI = i + moveI[k];
                int nextJ = j + moveJ[k];
                if (nextI < 0 || nextJ < 0 || nextI >= m || nextJ >= n) continue;
                if (c == arr[nextI][nextJ]) cnt++;
            }
            
            if (cnt == 3) {
                for (int k = 0; k < 4; k++) {
                    int nextI = i + moveI[k];
                    int nextJ = j + moveJ[k];
                    if (!checked[nextI][nextJ]) {
                        removeCnt++;
                        checked[nextI][nextJ] = 1;
                    }
                }
            }
            
        }
    }

    if (removeCnt == 0) return false;
    
    ans += removeCnt;
    return true;
}

void slide(int m, int n) {
    
    for (int i = 0; i < n; i++) {
        
        queue<char> q;
        for (int j = m - 1; j >= 0; j--) {
            if (!checked[j][i]) q.push(arr[j][i]);
        }
        
        int index = m - 1;
        while(!q.empty()) {
            arr[index--][i] = q.front();
            q.pop();
        }
        
        for (int j = 0; j <= index; j++) arr[j][i] = ' ';
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            checked[i][j] = 0;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = board[i][j];
        }
    }
    
    while(1) {
        if (remove(m, n)) slide(m, n);
        else break;
    }
    
    return ans;
    
}
