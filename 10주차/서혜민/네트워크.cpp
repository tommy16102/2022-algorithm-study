#include <string>
#include <vector>
#include <queue>
using namespace std;

/*

bfs 방식으로 연결된 네트워크 탐색해가며 진행.

*/

bool visited[200];

int solution(int n, vector<vector<int>> computers) {

    queue<int> queue;
    int answer = 0;
    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            queue.push(i);
            visited[i] = 1;
            while (!queue.empty()) {
                int a = queue.front();
                queue.pop();
                for (int j = 0;j < n;j++) {
                    if (j != a && computers[a][j] == 1 && !visited[j]) {
                        queue.push(j);
                        visited[j] = 1;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}