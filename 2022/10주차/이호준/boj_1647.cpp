/*******************************************************************
Algorithm Study
Baekjoon OJ Minimum Spanning Tree (MST) Kruskal Algorithm
1647 도시분할계획
2022/04/05 이호준
# 아이디어
1. 크루스칼 알고리즘을 통한 최소 스패닝 트리 기본 알고리즘 문제 풀이.
Union-Find Algorithm 이용
2개의 도시로 나누면 된다.
1개의 도시로 전부 연결되면 가장 큰 간선의 연결을 빼주면된다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<pair<int,pair<int,int>>> house;

int parent[100001];

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
	    if(u<v)
            parent[v] = u; // union
        else
            parent[u] = v;
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    int answer = 0;

    for(int i = 0; i< m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        house.push_back({c, {a, b}});
    }

    for(int i = 1; i<= n; i++){
        parent[i] = i;
    }

    sort(house.begin(), house.end());

    int union_count = 0;
    int last;

    for (int i = 0; i < m; i++){
        if(find_parent(house[i].second.first)!=find_parent(house[i].second.second)){
		    union_node(house[i].second.first, house[i].second.second);
            answer += house[i].first;
            last = house[i].first;
            // cout << parent[house[i].second.first] << " " << parent[house[i].second.second] << "\n";
        }
  
	}

    for(int i = 1; i<=n; i++){
        if(parent[i]==i)
            union_count++;
    }

    if(union_count==1){
        answer-=last;
    }
    cout << answer;
    return 0;
}