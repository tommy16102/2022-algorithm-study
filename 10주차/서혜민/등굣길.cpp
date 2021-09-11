#include <string>
#include <vector>
using namespace std;
#define DIV 1000000007;

/*

2021.09.11
물에 잠긴 지역은 -1로, 시작 지점은 1로 초기화 후, 이중 for문을 통해서
해당 지점까지 경로의 수는 위에서부터 내려오는 경로, 왼쪽에서부터 오는 경로의 합과 같으므로 이 둘을 더해준다.

/*

int routes[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0;i < puddles.size();i++) {
        int M = puddles[i][0];
        int N = puddles[i][1];
        routes[M][N] = -1;
    }

   routes[1][1]=1;

    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            if(i==1 && j==1) continue;
            if (routes[i][j] == -1) continue;
            int left = 0, down = 0;
            if (routes[i][j - 1] != -1 && j-1>=1) left = routes[i][j - 1];
            if (routes[i - 1][j] != -1 && i-1>=1) down = routes[i - 1][j];
            routes[i][j] = (left + down)%DIV;
        }
    }
    return routes[m][n];
}
