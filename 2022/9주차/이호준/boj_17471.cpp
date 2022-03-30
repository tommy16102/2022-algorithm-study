/*******************************************************************
Algorithm Study
Baekjoon OJ BFS + 조합
17471 게리맨더링
2022/03/29 이호준
# 아이디어
1. 조합을 이용해서 선거구를 두 개의 집합으로 나누고
BFS로 선거구가 연결됬는지 확인하면서 두 집합의 최소값을 구한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2100000000

using namespace std;

bool visited[11];
vector<int> maps[11];


bool bfs(vector<int>& stations) {

	queue<int> q;

	visited[stations[0]] = true;
	q.push(stations[0]);

	int checked = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < maps[current].size(); i++) {
			for (int j = 0; j < stations.size(); j++) {
				if (stations[j] == maps[current][i] && !visited[stations[j]]) {
					visited[stations[j]] = true;
					q.push(stations[j]);
					checked++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 11; i++)
		visited[i] = false;

	if (checked == stations.size()) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	vector<int> input(n, 0);

	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
		sum += input[i];
	}


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int a = 0; a < num; a++) {
			int temp;
			cin >> temp;
			maps[i].push_back(temp-1);
		}
	}

	int answer = INF;

	for (int i = 1; i < n; i++) {
		if (answer == 0)
			break;
		vector<bool> combination(n, false);
		for (int a = 0; a < i; a++) {
			combination[n - 1 - a] = true;
		}
		do {

			int combination_sum = 0;
			vector<int> stations;
			vector<int> stations2;
			bool possible_case = false;
			for (int s = 0; s < n; s++) {
				if (combination[s]) {
					stations.push_back(s);
				}
				else {
					stations2.push_back(s);
				}
			}
			if (!stations.empty()) {
				// 두 집합 모두연결되어 있다면
				if (bfs(stations) && bfs(stations2)) {
					possible_case = true;
				}
			}
			if (possible_case) {
				for (auto a : stations)
					combination_sum += input[a];

				int combination_sum2 = abs(combination_sum - sum);
				answer = min(abs(combination_sum - combination_sum2), answer);
			}
			if (answer == 0)
				break;

		} while (next_permutation(combination.begin(), combination.end()));
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;
	

	return 0;
}