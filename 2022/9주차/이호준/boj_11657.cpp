/*******************************************************************
Algorithm Study
Baekjoon OJ Bellman-Ford Algorithm
11657 타임머신
2022/03/27 이호준
# 아이디어
1. Bellman-Ford Algorithm 공부 및 구현 
기본예제 문제 풀이.
*******************************************************************/
/* 
Bellman-Ford Algorithm
한 정점에서 다른 정점까지 최단거리를 구하는 알고리즘
음의 간선 포함 가능.
다익스트라와 다르게 간선을 기준으로...

최악의 경우 최대 길이인 v-1 번 반복해야 경로를 찾을 수 있기 때문에 n -1 번 반복하고
마지막 한번 반복으로 음의 cycle 발견하는 알고리즘이다.

*/
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

long long answer[501];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	
	vector<pair<int,int>> map[501];

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		answer[i] = INF;
	}

	// Bellman Ford Algorithm
	answer[1] = 0;

	bool cycle = false;

	for (int i = 1; i <= n; i++) {
		// 모든 정점에 대해서 모든 간선을 탐색한다.
		for (int j = 1; j <= n; j++) {
			for (auto &a : map[j]) {
				// 방문되지 않은 지점에서 출발은 SKIP
				if (answer[j] != INF && answer[a.first] > a.second + answer[j]) {
					answer[a.first] = a.second + answer[j];
					if (i == n) cycle = true;
				}
			}
		}
	}

    // 음의 cycle 존재 
	if (cycle) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (answer[i] == INF) cout << "-1\n";
			else cout << answer[i] << "\n";
		}
	}

	return 0;
}