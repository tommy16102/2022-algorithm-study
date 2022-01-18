#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*

2022.1.18

BFS를 통해서 시작지점인 N부터 K에 도달할 때까지, 큐에 해당 지점과 시간을 넣어주면서,
도달했을 때의 가장 짧은 시간을 구한다.
이때 무한반복을 피하기 위해, N과 K중 더 큰 지점의 2배보다 크거나 +1을 한 지점보다 크면 
그 지점부터는 탐색을 할 필요가 없으므로 continue.

*/

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	fill(arr, arr + 100001, 100001);

	queue<pair<int, int>> queue;
	queue.push({ N,0 });

	while (!queue.empty()) {
		int now = queue.front().first;
		int sec = queue.front().second;
		queue.pop();
		if (now == K) {
			if (sec < arr[K]) arr[K] = sec;
		}
		int big = N > K ? N : K;
		if (now > 2 * big || now > big + 1) continue;
		else {
			if (now > 0 && sec + 1 < arr[now - 1]) {
				arr[now - 1] = sec + 1;
				queue.push({ now - 1, sec + 1 });
			}
			if (now < 100000 && sec + 1 < arr[now + 1]) {
				arr[now + 1] = sec + 1;
				queue.push({ now + 1, sec + 1 });
			}
			if (now <= 100000 / 2 && sec < arr[now * 2]) {
				arr[now * 2] = sec;
				queue.push({ now * 2,sec });
			}
		}
	}

	cout << arr[K] << '\n';
}
