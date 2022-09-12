#include <string>
#include <vector>
using namespace std;

int keyArr[20][20];
int lockArr[20][20];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int keyLen = key.size();
    int lockLen = lock.size();
    
    for (int i = 0; i < lockLen; i++) {
        for (int j = 0; j < lockLen; j++) {
            lockArr[i][j] = lock[i][j];
        }
    }
    
    for (int i = 0; i < keyLen; i++) {
        for (int j = 0; j < keyLen; j++) {
            keyArr[i][j] = key[i][j];
        }
    }
    
    for (int i = 0; i <= 3; i++) {
        if (i != 0) {
            for (int x = 0; x < keyLen; x++) {
                for (int y = 0; y < keyLen; y++) {
                    keyArr[y][keyLen - 1 - x] = key[x][y];
                }
            }
            for (int x = 0; x < keyLen; x++) {
                for (int y = 0; y < keyLen; y++) {
                   key[x][y] = keyArr[x][y];
                }
            }
        }
        
        for (int x = -keyLen + 1; x < lockLen; x++) {
            for (int y = -keyLen + 1; y < lockLen; y++) {
                int arr[20][20];
                for (int a = 0; a < lockLen; a++) {
                    for (int b = 0; b < lockLen; b++) {
                        arr[a][b] = lock[a][b];
                    }
                }
                for (int a = 0; a < keyLen; a++) {
                    for (int b = 0; b < keyLen; b++) {
                        if (a + x >= 0 && a + x < 20 && b + y >= 0 && b + y < 20) {
                            arr[a+x][b+y] += key[a][b];
                        }
                    }
                }
                 for (int a = 0; a < lockLen; a++) {
                    for (int b = 0; b < lockLen; b++) {
                         if (arr[a][b] != 1) return false;
                    }
                }
                
             }
        }
    }
         
    return true;
}