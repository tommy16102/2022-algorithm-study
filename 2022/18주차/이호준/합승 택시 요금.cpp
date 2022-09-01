/*******************************************************************
Algorithm Study
2021 Kakao Blind
합승 택시 요금 level 3
2022/08/30 이호준
# 아이디어
1. Floyd Warshall Algorithm
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> map(n+1, vector<int>(n+1, INF));
    
    for(int i = 0; i<=n; i++){
        map[i][i] = 0;
    }
    
    for(int i = 0; i< fares.size(); i++){
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j <=n ; j++){
                if(map[i][k]== INF || map[k][j] == INF) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    for(int i = 0; i <=n; i++){
        answer = min(answer, map[s][i] + map[i][a] + map[i][b]);
    }
    
    return answer;
}