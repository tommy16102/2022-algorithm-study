#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std; // 210912


int solution(int n, vector<vector<int>> computers) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int graph[201][201]; // i <=> j 그래프 관계
    bool visited[201] = { false, }; // 방문?

    for (int i = 0; i < n; i++) { // 그래프 관계 설정
        for (int j = 0; j < computers[i].size(); j++) {
            graph[i][j] = computers[i][j];
        }
    }

    int answer = 0;
    

    for (int i = 0; i < n; i++) { // 0부터 n-1까지 노드 방문
        queue<int> q;
        if (visited[i] == false) { // 해당 노드로부터 bfs 시작 가능?
            q.push(i);
            answer++;
        }

        vector<int> now = computers[i]; // 현재 노드와 연결된 친구들

        while (!q.empty()) { // 현재 노드로부터 bfs
            int current = q.front();
            now = computers[current];
            q.pop();

            for (int j = 0; j < now.size(); j++) {
                if (now[j] == 1) {
                    if (visited[j] == false) {
                        visited[j] = true;
                        q.push(j);
                    }
                }

            }           

        }
    }


    //cout << "answer : " << answer;
    return answer;

}