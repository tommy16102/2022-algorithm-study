/*******************************************************************
Algorithm Study
Baekjoon OJ Floyd Warshall
11404 플로이드
2022/03/27 이호준
# 아이디어
1. Floyd Warshall Algorithm 구현 및 알고리즘 이해 완료.
=> 어느 정점(노드)를 거치느냐를 중점으로 최적의 cost구하기

경로를 구해야한다면. backtracking처럼 최적의 cost로 교체가 일어나게 하는 거치는 정점을 저장해서
처음째 노드까지 되돌아가도록 구현.
*******************************************************************/
/*
플로이드 와샬 알고리즘 (Floyd Warshall)
모든 노드에서의 최단 거리 구하기.
연결된 노드끼리 cost를 입력 받고
각 노드에서 어떤 노드를 거쳐갈 때 값을 구해 min cost만 구하기.

=> 거쳐가는 노드를 기준으로 최단거리를 구한다.
*/

#include <iostream>
#include <algorithm>
#define INF 214700000
using namespace std;

int cost[101][101];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	
	// 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) cost[i][j] = INF;

	int a, b, c;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	// k를 거쳐 지나갈때 cost 연산
	// i 에서 j 로 가는 cost 구하기.
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << (cost[i][j] != INF ? cost[i][j] : 0) << " ";
		cout << '\n';
	}

	
	return 0;
}