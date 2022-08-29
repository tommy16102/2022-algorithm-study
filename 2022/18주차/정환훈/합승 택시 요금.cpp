#include <string>
#include <vector>
#include <iostream>
using namespace std;

int d[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    // 플로이드 와샬로 모든 정점간의 최단 거리를 구한다.
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            d[i][j] = 87654321;
        }
        d[i][i] = 0;
    }
    for(int i=0;i<fares.size();i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        d[from][to] = cost;
        d[to][from] = cost;
    }
    
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            //cout << i << ", " << j << " : " << d[i][j] << endl;
        }
    }
    
    // s->x + x->a + x->b가 min인 x를 구하면 된다.
    int answer = 987654321;
    for(int i=1;i<=n;i++){
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    
    return answer;
}