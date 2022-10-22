/*******************************************************************
10830 행렬 제곱
2022/10/22 이호준
# 아이디어
1. 분할 정복
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> temp;
vector<vector<int>> result;

int n;
void matrixMultiply(vector<vector<int>>& a, vector<vector<int>> b){
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = 0;
            for(int k = 0; k < n ; k++){
                temp[i][j] += (a[i][k] * b[k][j]);
            }
            temp[i][j] %= 1000;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            a[i][j] = temp[i][j];
        }
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long b;

    cin >> n >> b;

    matrix = vector<vector<int>>(n, vector<int>(n, 0));
    temp = vector<vector<int>>(n, vector<int>(n, 0));
    result = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cin >> matrix[i][j];
        }
        result[i][i] = 1;
    }

    while(b){
        if(b%2 == 1){
            matrixMultiply(result, matrix);
        }
        matrixMultiply(matrix, matrix);
        b/=2;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}