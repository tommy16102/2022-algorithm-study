#include <iostream>
#include <queue>
using namespace std;

/*

2022.2.5

BFS를 통해 탐색을 하는 과정에서 
이모티콘의 개수가 같아도 클립보드에 저장된 이모티콘의 개수가 다르면,
S개까지 걸리는 더 최소인 시간을 찾을 수 있게 된다.

*/


bool emo[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int S;
	cin >> S;
	
	queue<pair<pair<int, int>,int>> queue;
	emo[1][0] = 1;
	queue.push({ { 1, 0 }, 0 });

	while (!queue.empty()) {
		int now = queue.front().first.first;
		int clip = queue.front().first.second;
		int sec = queue.front().second;
		queue.pop();
		if (now == S) {
			cout << sec << '\n';
			return 0;
		}
		if (now + now < 2001 && !emo[now][now]) {
			emo[now][now] = 1;
			queue.push({ {now,now},sec + 1 });
		}
		if (now + clip < 2001 && clip > 0 && !emo[now + clip][clip]) {
			emo[now + clip][clip] = 1;
			queue.push({ {now + clip,clip},sec + 1 });
		}
		if (now > 0 && !emo[now - 1][clip]) {
			emo[now-1][clip]=1;
			queue.push({ {now - 1,clip},sec + 1 });
		}
	}
}
