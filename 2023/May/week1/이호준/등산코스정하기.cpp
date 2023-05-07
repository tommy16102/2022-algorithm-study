/*******************************************************************
Algorithm Study
2022 KAKAO TECH INTERNSHIP 등산코스 정하기
2023/05/01 이호준
# 아이디어
1. 다잌스트라 개념을 이용한 구현
-> 한번 정상에 도착하면 intensity가 정해지므로 내가 가지 말아야 하는 길을 cutting할 수 있다.
기본 아이디어 -> DFS -> 시간초과가 당연하므로 다잌스트라와 같은 원리 + cutting 사용
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>

#define INF 2100000000

using namespace std;

vector<pair<int,int>> map[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    sort(summits.begin(), summits.end());

    for(vector<int> path : paths){
        map[path[0]].push_back({path[1], path[2]});
        map[path[1]].push_back({path[0], path[2]});
    }
    int max_intensity = INF;
    int max_summit = INF;
    for(int gate : gates){
        priority_queue<pair<int,int>> q;
        q.push({0, gate});
        int isBlocked[50001];
        int costs[50001];
        fill(&costs[0], &costs[50001], INF);
        costs[gate] = 0;
        memset(&isBlocked, 0, sizeof(isBlocked));
        for(int g : gates){
            isBlocked[g] = true;
        }

        while(!q.empty()){
            int current_intensity = -q.top().first;
            int current_node = q.top().second;
            q.pop();

            if(max_intensity < current_intensity)
                continue;

            for(pair<int,int> path : map[current_node]){
                int next_intensity = max(current_intensity, path.second);
                if(!isBlocked[path.first] && costs[path.first] >= next_intensity ){
                    bool find = false;
                    for(int summit : summits){
                        if(path.first == summit){
                            if(max_intensity > next_intensity){
                                max_intensity = next_intensity;
                                max_summit = summit;
                            }else if (max_intensity == next_intensity){
                                max_summit = min(max_summit, summit);
                            }
                            find = true;
                            break;
                        }
                    }
                    if(!find && costs[path.first] > next_intensity){
                        q.push({-next_intensity, path.first});
                        costs[path.first] = min(next_intensity, costs[path.first]);
                    }
                }
            }
        }

    }
    answer.push_back(max_summit);
    answer.push_back(max_intensity);
    return answer;
}
