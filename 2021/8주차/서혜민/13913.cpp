#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
using namespace std;

/*

2021.09.03 서혜민

벡터를 하나 줘서 K부터 N까지 거꾸로 dist배열 내 값이 timeCount값고 같다면 삽입 후,
뒤에서부터 출력.

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
		if (timeCount == dist[K]) {
			cout << dist[K] << '\n';

			int start = K;
			vector<int> v;
			v.push_back(start);
			timeCount--;
			while (timeCount>=0) {
				if (dist[start - 1] == timeCount) {
					v.push_back(start - 1);
					start = start - 1;
				}
				else if (dist[start + 1] == timeCount) {
					v.push_back(start + 1);
					start = start + 1;
				}
				else if (start%2==0 && dist[start / 2] == timeCount) {
					v.push_back(start / 2);
					start = start / 2;
				}
				timeCount--;
			}
			for (int i = v.size() - 1;i >= 0;i--) {
				cout << v[i] << ' ';
			}
			cout << endl;
			return 0;
		}
		timeCount++;
	}
}
