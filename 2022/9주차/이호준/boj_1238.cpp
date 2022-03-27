/*******************************************************************
Algorithm Study
Baekjoon OJ Dijkstra
1238 파티
2022/03/27 이호준
# 아이디어
1. Dijkstral Algorithm 구현 및 알고리즘 이해 완료.
=> 하나의 노드에서 다른노드들까지의 최단거리를 구하는 알고리즘!

갔다와야하므로
i ->x  , x->i 인데 이때 x-> i까지의 구하는 것은 다익스트라 알고리즘의 고유의 방식이다.
그런데 i->x로 구하려고 할때 이는 모든 정점에서 다익스트라를 진행해야한다.

그러나, 결국 각 노드에서 x로 가는 것이므로 이것을 그래프에서 시작과 도착 간선의 방향을 바꿔
x-> i로 가는 것으로 변환하여 생각하면 한번의 다익스트라를 추가하면 해결할 수 있다.

즉, x라는 노드로 시점을 전환하여 간선의 방향을 바꿔 생각하면 한번의 다익스트라만 더 추가하면 바로 구할 수 있다.

※ 플로이드 와샬 알고리즘이 먼저 생각났는데 노드의 수가 너무 많아 문제가 될 수 있을 것 같았다.
=> 다익스트라로 구현.
=> 이때 생각의 전환으로 x가 중심이라는 것을 생각하여 구현.
*******************************************************************/
#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>

#define INF 10000000

using namespace std;

// map1 ( x-> 노드)
// map2 ( 노드->x) 역방향으로 넣어서 연산
vector<pair<int, int>> map1[1001];
vector<pair<int, int>> map2[1001];
int d[1001];
//파티장소(x)에서의 정방향+역방향에서의 다익스트라값의 합 저장
int ans[1001];
int n, m, x, u, v, w;

void dijkstra(int start, vector<pair<int, int>>arr[1001]);

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		map1[u].push_back({ v,w });
		map2[v].push_back({ u,w });
	}
	dijkstra(x, map1);
	dijkstra(x, map2);

	int max_value = 0;
	for (int i = 1; i <= n; i++)
		max_value = max(max_value, ans[i]);

	cout << max_value << '\n';
}

void dijkstra(int start, vector<pair<int, int>>arr[1001]){
	//각 최단거리를 INF로 초기화
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ start, 0 });
	while (!pq.empty()){
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] < distance)
			continue;
		for (int i = 0; i < arr[current].size(); i++){
			int next = arr[current][i].first;
			int next_distance = distance + arr[current][i].second;
			if (d[next] > next_distance){
				d[next] = next_distance;
				pq.push(make_pair(next, -next_distance));
			}
		}
	}

	// 최단거리 저장
	for (int i = 1; i <= n; i++)
		ans[i] += d[i];
}