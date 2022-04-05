
/*******************************************************************
Algorithm Study
Baekjoon OJ Minimum Spanning Tree (MST) Kruskal Algorithm
1197 최소 스패닝 트리
2022/04/04 이호준
# 아이디어
1. 크루스칼 알고리즘을 통한 최소 스패닝 트리 기본 알고리즘 문제 풀이.
Union-Find Algorithm 이용
*******************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int V, E, A, B, C;
int u, v, w;
int parent[10001];
long long ans;

vector<pair<int,pair<int,int>>> graph;

int find_parent(int x){
	if (parent[x] == x) 
		return x;
	else // 부모 노드 찾기
		return parent[x] = find_parent(parent[x]);
}

void union_node(int u, int v){
	u = find_parent(u);
	v = find_parent(v);

	if (u == v) // 부모가 같다면 결합 시 사이클 이므로 연결 x
		return; 
	else
	    parent[u] = v; // union
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++){
		cin >> A >> B >> C;
		graph.push_back({C,{A,B}});
	}
	sort(graph.begin(), graph.end());

	for (int i = 0; i < E; i++){
        if(find_parent(graph[i].second.first)!=find_parent(graph[i].second.second)){
		    union_node(graph[i].second.first, graph[i].second.second);
            ans += graph[i].first;
        }
	}

	cout << ans << '\n';
}