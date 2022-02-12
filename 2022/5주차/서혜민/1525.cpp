#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

/*

2022.2.12

1 2 3
4 5 6  => 123456780 문자열 취급하여 BFS를 통해 0을 상,하,좌,우 이동하여 숫자를 바꿔가면서 탐색해나감.
7 8 0

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string puzzle;
	int index;

	for (int i = 1;i <= 3;i++) {
		for (int j = 1;j <= 3;j++) {
			char c;
			cin >> c;
			puzzle += c;
			if (c == '0') {
				index = (i-1) * 3 + j;
			}
		}
	}

	queue<pair<string, pair<int, int>>> queue;
	map<int, int> map;
	map.insert({ stoi(puzzle),1 });
	queue.push({ puzzle, { index, 0 } });
	while (!queue.empty()) {
		string puzzle = queue.front().first;
		int index = queue.front().second.first;
		int cnt = queue.front().second.second;
		if (puzzle == "123456780") {
			cout << cnt << '\n';
			exit(0);
		}
		queue.pop();

		char indexNum = puzzle[index - 1];
		
		if (index > 3) {
			string puzzle2 = puzzle;
			int newIndex = index - 3;
			char newNum = puzzle2[newIndex - 1];
			puzzle2[index - 1] = newNum;
			puzzle2[newIndex - 1] = indexNum;
			if (map.find(stoi(puzzle2)) == map.end()) {
				queue.push({ puzzle2, {newIndex, cnt + 1} });
				map.insert({ stoi(puzzle2),1 });
			}
		}
		if (index < 7) {
			string puzzle2 = puzzle;
			int newIndex = index + 3;
			char newNum = puzzle2[newIndex - 1];
			puzzle2[index - 1] = newNum;
			puzzle2[newIndex - 1] = indexNum;
			if (map.find(stoi(puzzle2)) == map.end()) {
				queue.push({ puzzle2, {newIndex, cnt + 1} });
				map.insert({ stoi(puzzle2),1 });
			}
		}
		if (index % 3 != 1) {
			string puzzle2 = puzzle;
			int newIndex = index - 1;
			char newNum = puzzle2[newIndex - 1];
			puzzle2[index - 1] = newNum;
			puzzle2[newIndex - 1] = indexNum;
			if (map.find(stoi(puzzle2)) == map.end()) {
				queue.push({ puzzle2, {newIndex, cnt + 1} });
				map.insert({ stoi(puzzle2),1 });
			}
		}
		if (index % 3 != 0) {
			string puzzle2 = puzzle;
			int newIndex = index + 1;
			char newNum = puzzle2[newIndex - 1];
			puzzle2[index - 1] = newNum;
			puzzle2[newIndex - 1] = indexNum;
			if (map.find(stoi(puzzle2)) == map.end()) {
				queue.push({ puzzle2, {newIndex, cnt + 1} });
				map.insert({ stoi(puzzle2),1 });
			}
		}
	}
	cout << -1 << '\n';
}
