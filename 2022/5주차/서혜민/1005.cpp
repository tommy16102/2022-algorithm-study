#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*

2022.2.15

Queue를 이용한 위상정렬.

진입차수가 0인 건물의 번호들을 큐에 넣어주는 것을 시작으로,
큐에서 꺼낸 번호에서 이어서 지을 수 있는 건물 번호 중 꺼낸 번호를 빼게 되면
진입차수가 0인 건물을 다시 큐에 넣어주면서,
해당 번호를 짓는 데 걸리는 시간을 저장하는 ans배열에 더 큰 수가 저장될 수 있도록 한다.

*/
int froms[1001];
bool visited[1001];
int ans[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;

		vector<int> time(N+1);
		for (int i = 1;i <= N;i++) cin >> time[i];

		vector<int> order[1001];
		for (int i = 0;i < K;i++) {
			int from, to;
			cin >> from >> to;
			order[from].push_back(to);
			froms[to]++;
		}

		int W;
		cin >> W;

		queue<int> q;

		for (int i = 1;i <= N;i++) {
			if (froms[i] == 0) {
				visited[i] = 1;
				q.push(i);
				ans[i] = time[i];
			}
		}

		while (!q.empty()) {
			int fnum = q.front();
			q.pop();
			for (int i = 0;i < order[fnum].size();i++) {
				int to = order[fnum][i];
				if (visited[to]) continue;
				froms[to]--;
				ans[to] = max(ans[to], ans[fnum] + time[to]);
				if (froms[to] == 0) {
					visited[to] = 1;
					q.push(to);
				}
			}
		}

		cout << ans[W] << '\n';

		for (int i = 0;i < 1001;i++) froms[i] = visited[i] = ans[i] = 0;
	}
}
