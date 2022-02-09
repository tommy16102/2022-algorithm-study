/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
14226 이모티콘
2022/02/08 이호준
# 아이디어
1. 문제가 제시한대로 BFS실행
{ {screen, clipboard}, seconds }
*******************************************************************/
#include <iostream>
#include <queue>

using namespace std;

bool visited[2001][2001];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int finish;

	cin >> finish;

	int current = 1;

	// { {screen, clipboard}, seconds }
	queue<pair<pair<int, int>, int>> q;

	q.push({ {1, 0}, 0 });

	while (!q.empty()) {
		int current_screen = q.front().first.first;
		int current_clipboard = q.front().first.second;
		int current_seconds = q.front().second;
		q.pop();

		if (current_screen == finish) {
			cout << current_seconds;
			return 0;
		}

		if (current_clipboard && current_screen + current_clipboard < 1001 &&!visited[current_screen + current_clipboard][current_clipboard]) {
			q.push({ {current_screen + current_clipboard, current_clipboard}, current_seconds + 1 });
			visited[current_screen + current_clipboard][current_clipboard] = true;
		}
		
		if (current_screen) {
			if (!visited[current_screen][current_screen]) {
				q.push({ {current_screen, current_screen}, current_seconds + 1 });
				visited[current_screen][current_screen] = true;
			}
			if (!visited[current_screen - 1][current_clipboard]) {
				q.push({ {current_screen - 1, current_clipboard}, current_seconds + 1 });
				visited[current_screen - 1][current_clipboard] = true;
			}
		}

	}


	return 0;
}