/*******************************************************************
Algorithm Study
Baekjoon OJ Dijkstra
4485 녹색 옷 입은 애가 젤다지?
2022/04/11 이호준
# 아이디어
1. 맨 처음에는 전형적인 dp문제 인줄 알았으나
상하좌우로 움직이기 때문에 dp로구할 수 없었다. -> 순환이 생겨서 최선임을 보장할 수 없음.

2. 경로의 최소 비용찾기 -> 다익스트라 알고리즘.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int,int>> map[15626];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int problem = 0;

    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        } 
        problem++;
        vector<vector<int>> input(n, vector<int>(n, 0));
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> input[i][j];
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j< n; j++){
                for(int a = 0; a<4; a++){
                    int next_x = i + dx[a];
                    int next_y = j + dy[a];
                    if(next_x >=0 && next_x < n && next_y >=0 && next_y <n){
                        map[i * n + j].push_back({ next_x*n + next_y, input[next_x][next_y]});
                    }
                }
            }
        }
        vector<int> costs(n*n, INF);

        // {next, costs}
        priority_queue<pair<int,int>> q;
        costs[0] = input[0][0];
        q.push({0, -costs[0]});

        while(!q.empty()){
            int current = q.top().first;
            int current_distance = -q.top().second;
            q.pop();

            if(costs[current] < current_distance)
                continue;
            
            for(auto & a : map[current]){
                int next = a.first;
                int distance = current_distance + a.second;
                if(costs[next] > distance){
                    costs[next] = distance;
                    q.push({next, -distance});
                }
            }
        }
        cout << "Problem " << problem << ": " << costs[n*n-1] << "\n";
        /* for( auto a : costs){
            cout << a << " ";
        }
        cout <<"\n"; */
        for(int i = 0; i < n*n; i++){
            map[i].clear();
        }
    }
    
    return 0;

}