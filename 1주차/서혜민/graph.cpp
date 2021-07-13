#include <string>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<int> q;
    bool visited[20001] = {0, };
    bool check[20001][20001] = {0, };
    int dist[20001] = {0, };
    
    sort(edge.begin(), edge.end());
    
    for (int i = 0;i < edge.size();i++) {
        check[edge[i][0]][edge[i][1]] = 1;
        check[edge[i][1]][edge[i][0]] = 1;
    }
    q.push(1);
    visited[1] = true;

    int max = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 2;i <= n;i++) {
            if ((check[node][i] == 1 || check[i][node] == 1 )&& visited[i] == 0) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[node] + 1;
            }
            if (dist[i] > max) max = dist[i];
        }
    }

    int answer = 0;
    for (int i = 1;i <= n;i++) {
        if (dist[i] == max) answer++;
    }
    return answer;
}