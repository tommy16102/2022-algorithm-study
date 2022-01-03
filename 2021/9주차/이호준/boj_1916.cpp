/*******************************************************************
Algorithm Study
Baekjoon 9주차 다익스트라/이분탐색
1916 최소비용 구하기
2021/09/08 이호준
# 아이디어
1. 다익스트라 알고리즘을 통해서 최소비용을 구할 수 있다.
이 문제를 읽고 다익스트라를 이용하면 좋을 것 같다는 생각이 들면 이문제는 쉬울 것 같다.

앞서 푼 최단경로를 통해서 다익스트라를 구현해봤는데
그것을 이해했는지 체크하기 좋은 문제인 것 같다. 
특별한 것은 없고 다익스트라를 문제에 적용하면 풀 수 있다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> schedule[1000];

    for (int i = 0; i < m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        schedule[start - 1].push_back({end - 1, weight});
    }

    priority_queue<pair<int, int>> pq;

    int departure_station, arrival_station;

    cin >> departure_station >> arrival_station;

    vector<int> answer(n, 2100000000);
    answer[departure_station - 1] = 0;
    pq.push({0, departure_station - 1});

    while (!pq.empty())
    {

        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (answer[node] < cost)
            continue;

        for (int i = 0; i < schedule[node].size(); i++)
        {

            int next_node = schedule[node][i].first;
            int weight = schedule[node][i].second;

            int check_cost = cost + weight;
            if (check_cost < answer[next_node])
            {
                answer[next_node] = check_cost;
                pq.push({-check_cost, next_node});
            }
        }
    }

    cout << answer[arrival_station - 1];

    return 0;
}