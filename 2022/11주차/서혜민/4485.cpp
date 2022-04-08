#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 126
#define INF 999999999
using namespace std;

int N;
int arr[MAX][MAX];
int dist[MAX][MAX];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

void find() {
	queue<pair<int, int>> pq;
	pq.push({ 0,0 });
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {
		int nowI = pq.front().first;
		int nowJ = pq.front().second;
		int d = dist[nowI][nowJ];
		pq.pop();
		for (int i = 0;i < 4;i++) {
			int newI = nowI + moveI[i];
			int newJ = nowJ + moveJ[i];

			if (newI < 0 || newJ < 0 || newI >= N || newJ >= N) continue;
			if (dist[newI][newJ] < d + arr[newI][newJ]) continue;
			dist[newI][newJ] = d + arr[newI][newJ];
			pq.push({ newI,newJ });
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}

void input() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			dist[i][j] = INF;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> N;
		if (!N) break;
		input();
		find();
		cout << "Problem " << cnt++ << ": " << dist[N-1][N-1] << '\n';
	}
}
