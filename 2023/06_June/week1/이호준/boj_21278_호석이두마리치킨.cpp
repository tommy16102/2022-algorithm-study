/*******************************************************************
Algorithm Study
Baekjoon 21278 호석이 두 마리 치킨
2023/06/10 이호준
# 아이디어
1. BruteForce, 플로이드와샬
*******************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1000000000

using namespace std;

int n, m;
int dist[101][101];

int calDistance(int x, int y){
	int distance = 0;
	for (int i = 1; i <= n; i++)
		distance += min(dist[x][i], dist[y][i]);
	return distance;
}

void floydWarshall(){
    for(int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			else if (!dist[i][j])
				dist[i][j] = INF;
		}
    }
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		dist[x][y] = dist[y][x] = 1;
	}

    floydWarshall();

    pair<int,int> chicken;
    int answer = INF;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			int temp = calDistance(i, j);
			if (answer > temp) {
				chicken = {i, j};
				answer = temp;
			}
		}
	cout << chicken.first <<" " << chicken.second <<" "<< answer * 2;
	return 0;
}