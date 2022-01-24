#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

2022.1.24

작은키,큰 키 입력받을 때마다 벡터[작은키]에 큰 키를 저장시키면서 큰 키의 진입 차수 증가.
입력 다 끝난 후 진입 차수가 0인 것들을 큐에 넣는 것을 시작으로
벡터[큐에서 꺼낸 노드]에 저장되어 있는 노드(큐에서 꺼낸 노드가 저장되어 있는 노드들의 진입 노드)
들의 진입 차수를 감소시키면서, 진입 차수가 0인 것들을 반복적으로 큐에 넣어준다.

*/

bool visited[32001];
int toCount[32001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> fromTo(N + 1);

	while (M--) {
		int small, big;
		cin >> small >> big;
		fromTo[small].push_back(big);
		toCount[big]++;
	}

	queue<int> queue;

	for (int i = 1;i <= N;i++) {
		if (toCount[i] == 0) {
			queue.push(i);
			visited[i] = 1;
		}
	}

	while (!queue.empty()) {
		int from = queue.front();
		cout << from << ' ';
		queue.pop();
		
		for (int i = 0;i < fromTo[from].size();i++) {
			int to = fromTo[from][i];
			toCount[to]--;
			if (toCount[to] == 0 && !visited[to]) {
				queue.push(to);
				visited[to] = 1;
			}
		}
	}
}
