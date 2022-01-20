#include <bits/stdc++.h>
using namespace std;

int n; int m;
int MAP[10][10];// 테스트에 사용하는 map
int map_origin[10][10]; // 입력받은 original map
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
pair<int, int> zero_combination[3]; // 현재 벽을 세울 좌표
vector<pair<int, int>> zeros; // 벽을 세울 수 있는 좌표 목록


void dfs() { // dfs로 바이러스 퍼뜨리기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (MAP[i][j] == 2) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && MAP[nx][ny] == 0) {
						MAP[nx][ny] = 2;
						dfs();
					}
				}
			}
		}
	}

}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map_origin[i][j];
			if (map_origin[i][j] == 0)
				zeros.push_back({ i,j }); // 벽을 세울 수 있는 좌표 목록
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			MAP[i][j] = map_origin[i][j];
		}
	}
}

void solve() {

	// nC3을 하기 위한 과정
	int size = zeros.size();
	vector<int> v;
	for (int i = 0; i < size; i++) {
		v.push_back(i);
	}
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	for (int i = 3; i < size; i++) {
		temp.push_back(0);
	}

	do { // 벽을 세울 수 있는모든 조합에 대하여
		int c = 0;
		for (int i = 0; i < v.size(); ++i) { // 현재 조합 갱신
			if (temp[i] == 1) {
				zero_combination[c++] = zeros[i];
			}
		}
		// MAP 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				MAP[i][j] = map_origin[i][j];
			}
		}
		for (int i = 0; i < 3; i++) { // 벽 세움
			MAP[zero_combination[i].first][zero_combination[i].second] = 1;
		}
		// 바이러스 퍼뜨리기
		dfs();
		// 값 채점
		int area = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (MAP[i][j] == 0) {
					area++;
				}
			}
		}
		// 값 갱신
		answer = max(answer, area);
	} while (prev_permutation(temp.begin(), temp.end()));

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}