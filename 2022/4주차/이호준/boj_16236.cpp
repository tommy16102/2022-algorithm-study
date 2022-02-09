/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
16236 아기 상어
2022/02/08 이호준
# 아이디어
1. 문제가 제시한대로 BFS실행
{{x, y}, time}
BFS에 들어가는 depth를 기억했다가
먹을 수 있는 물고리를 발견한 depth에서 조건에 맞는(가장위, 가장왼쪽) 물고기를 찾도록 구현.
*******************************************************************/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 0, 1};
int dy[4] = { 0, -1, 1, 0};

bool visited[21][21];
int check[21][21];

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, 0));

	pair<int, int> start;
	int fishes = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 9) {
				start = { i, j };
				map[i][j] = 0;
			}else if (temp != 0) {
				fishes++;
			}
		}
	}

	int eat_count = 0;
	int shark_size = 2;
	int time = 0;
	bool finish = false;
	bool catch_case = false;
	while (1) {
		
		// 현재위치에서 bfs 시작
		// {{x, y}, time}
		queue<pair<pair<int, int>, int>> q;
		q.push({ {start.first, start.second},time });
		visited[start.first][start.second] = true;

		// 같은 bfs depth에서 탈출 위치를 check 하기위한 변수
		int candidate_x = 50;
		int candidate_y = 50;
		int candidate_time = 0;

		while(1) {

			if (q.empty() || q.front().second != candidate_time) {
				if (candidate_x != 50) {
					//cout << "check" << candidate_x << " " << candidate_y << " " << candidate_time << "\n";
					map[candidate_x][candidate_y] = 0;
					check[candidate_x][candidate_y] = candidate_time + 1;
					eat_count++;
					fishes--;
					if (eat_count == shark_size) {
						shark_size++;
						eat_count = 0;
					}
					catch_case = true;
					start = { candidate_x, candidate_y };
					time = candidate_time + 1;
					break;
				}
			}
			if (q.empty()) {
				break;
			}
			int current_x = q.front().first.first;
			int current_y = q.front().first.second;
			int current_time = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int next_x = current_x + dx[i];
				int next_y = current_y + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
					
					if (!visited[next_x][next_y]) {
						int current_location_size = map[next_x][next_y];
						// 상어 크기보다 작다면 먹는다.
						// 먹으면 자리 0 cout++ , size check
						//if (current_location_size < shark_size && current_location_size > 0) {
						//	visited[next_x][next_y] = true;
						//	map[next_x][next_y] = 0;
						//	check[next_x][next_y] = current_time + 1;
						//	eat_count++;
						//	fishes--;
						//	if (eat_count == shark_size) {
						//		shark_size++;
						//		eat_count = 0;
						//	}
						//	catch_case = true;
						//	start = { next_x, next_y };
						//	time = current_time + 1;
						//	q = queue<pair<pair<int, int>, int>>();
						//	//cout << q.size() << "\n";
						//	break;
						//}
						if (current_location_size < shark_size && current_location_size > 0) {
							visited[next_x][next_y] = true;
							if (candidate_x > next_x || (candidate_x == next_x && candidate_y > next_y)) {
								//cout << next_x << " " << next_y  << " " << q.size() << "\t";
								candidate_x = next_x;
								candidate_y = next_y;
								candidate_time = current_time;
								//cout << candidate_x << " " << candidate_y << " " << candidate_time << " "<< q.size()<< "\n";
							}
						}
						if (current_location_size == shark_size || current_location_size == 0) {
							visited[next_x][next_y] = true;
							q.push({ {next_x, next_y}, current_time + 1 });
						}
					}
				}
			}
			
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
			}
		}

		// 잡아서 탈출시
		if (catch_case) {
			catch_case = false;
			if (fishes == 0) {
				break;
			}
		}
		else {
			// q가 empty()여서 탈출했을 때!
			// 잡을 것이 더이상 없다.
			break;
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << time;

	return 0;
}