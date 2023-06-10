/*******************************************************************
Algorithm Study
Baekjoon 1956 운동
2023/06/03 이호준
# 아이디어
1. 플로이드와샬
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int costs[401][401];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    int a, b, c;
    fill(&costs[1][1], &costs[v+1][0], INF);

    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c;
        costs[a][b] = c;
    }

    for(int k = 1; k <= v; ++k)
        for(int i = 1; i <= v; ++i)
            for(int j = 1; j <= v; ++j)
                if(costs[i][j] > costs[i][k] + costs[k][j])
                    costs[i][j] = costs[i][k] + costs[k][j];

    int answer = INF;
    for(int i = 1; i <= v; ++i)
        answer = min(answer, costs[i][i]);
        
    cout << ((answer != INF) ? answer : -1);

    return 0;
}