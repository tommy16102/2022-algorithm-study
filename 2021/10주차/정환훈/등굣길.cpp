#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // 210915

int block[101][101];
long long d[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            block[i][j] = 0;
        }
    }

    for (int i = 0; i < puddles.size(); i++) {
        block[puddles[i][0]][puddles[i][1]] = 1; // 못가는 곳은 1 표시
    }

    d[1][1] = 0;

    for (int i = 2; i <= m; i++) { // 가로줄 1로 채우기
        if (block[i][1] == 1) {
            d[i][1] = 0;
            for(int j = i; j<=m; j++){ // 강물 만나면 이후 친구들 0으로 채움
                d[j][1] = 0;
            }
            break;
        }
        else {
            d[i][1] = 1;
        }
    }

    for (int i = 2; i <= n; i++) { // 세로줄 1로 채우기
        if (block[1][i] == 1) {
            d[1][i] = 0;
            for(int j = i; j<=n; j++){ // 강물 만나면 이후 친구들 모ㅅ감
                d[1][j] = 0;
            }
            break;
        }
        else {
            d[1][i] = 1;
        }
    }

    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) { // 경우의 수 : 최단 경로 개수 구하기
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
            if (block[i][j] == 1)
                d[i][j] = 0;
        }
    }

    return d[m][n];
}