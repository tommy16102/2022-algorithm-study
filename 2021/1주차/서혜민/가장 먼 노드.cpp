#include <string>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

/*

2021.07.12 서혜민

이중 배열 check에서는 두 노드 사이에 연결된 엣지를 [노드1][노드2] 1 설정
visited배열에서는 해당 노드를 인덱스로서 방문을 했는 지를 표현.
disk배열에서는 해당 노드를 인덱스로서 이 노드까지의 경로의 길이를 표현

출발하는 노드인 1을 먼저 queue에 넣어준 뒤,
해당 노도를 꺼낸 뒤, 이와 연결되었으면서 아직 방문하지 않은 노드를 queue에 넣어준다.
이 과정을 반복을 하면서, 경로의 길이를 저장하는 dist배열에 이전 노드의 dist배열의 값에 1을 더해준다.
그리고 dist배열 내 가장 큰 값을 가지는(최장 경로인) 노드의 개수를 구하면 된다.

*/

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