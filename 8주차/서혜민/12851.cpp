#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

/*

2021.09.03 서혜민

N을 시작점으로서 dist라는 INT_MAX로 초기화 한 최단 경로의 길이를 값으로 가지는 배열에서
dist[N]을 0값을 시작으로 N에 -1,+1,*2한 수가 범위 내에 있으면서 또한 경로의 길이가 
이전에 비해서 같거나 짧아진다면 queue에 넣어준다.

queue에서 꺼낸 숫자가 K와 같다면 count를 늘려주면서 queue에서 한차례 순환이 끝났을 때 1씩 더해주는 
경로의 길이인 timeCount가 disk[K]와 같게될 때의 count의 값은 최단 경로일 때의 경우의 수이다.

*/

const int MAX = 100001;
int dist[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	fill_n(dist, MAX, INT_MAX);
	dist[N] = 0;
	queue<int> queue;
	queue.push(N);

	int timeCount = 0;
	while (!queue.empty()) {
		int size = queue.size();
		int count = 0;
		while (size--) {
			int x = queue.front();
			if (x == K) {
				count++;
			}
			queue.pop();
			if (x - 1 >= 0 && dist[x - 1] >= dist[x] + 1) {
				dist[x - 1] = dist[x] + 1;
				queue.push(x - 1);
			}
			if (x + 1 < MAX && dist[x + 1] >= dist[x] + 1) {
				dist[x + 1] = dist[x] + 1;
				queue.push(x + 1);
			}
			if (x * 2 < MAX && dist[x * 2] >= dist[x] + 1) {
				dist[x * 2] = dist[x] + 1;
				queue.push(2 * x);
			}
		}
		if (timeCount==dist[K]) {
			cout << dist[K] << '\n' << count << '\n';
			return 0;
		}
		timeCount++;
	}
}
