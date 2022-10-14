/*******************************************************************
10282 해킹
2022/10/12 이호준
# 아이디어
1. 다잌스트라
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

int costs[10001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n, d, c;
        cin >> n >> d >> c;
        vector<pair<int,int>> map[n + 1];
        for(int a = 0 ; a <d; a++){
            int x, y, seconds;
            cin >> x >> y >> seconds;
            map[y].push_back({x, seconds});
        }
        for(int a = 0 ; a <=n ; a++){
            costs[a] = INF;
        }
        costs[c] = 0;
        priority_queue<pair<int,int>> q;
        q.push({0, c});

        while(!q.empty()){
            int current_computer = q.top().second;
            int current_second = -q.top().first;

            q.pop();

            if(current_second > costs[current_computer]){
                continue;
            }


            for(int a = 0; a < map[current_computer].size(); a++){
                int next_computer = map[current_computer][a].first;
                int next_seconds = map[current_computer][a].second + current_second;

                if(next_seconds < costs[next_computer]){
                    costs[next_computer] = next_seconds;
                    q.push({-next_seconds, next_computer});
                }
            }
        }
        int max_value = 0;
        int computers = 0;
        for(int a = 1; a <= n; a++){
            if(costs[a] != INF){
                computers++;
                if(costs[a] > max_value) max_value = costs[a];
            }
        }
        cout << computers << " " << max_value <<"\n";
    }

    return 0;
}