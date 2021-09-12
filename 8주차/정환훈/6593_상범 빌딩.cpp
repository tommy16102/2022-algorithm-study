#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int L = -1; // L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수
int R = -1; //  R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수
int C = -1;
bool visited[33][33][33] = { false, };
char store[33][33][33];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int start_x = -1;
int start_y = -1;
int start_z = -1;
bool flag = false;

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 33; i++) {
		for (int j = 0; j < 33; j++) {
			for (int k = 0; k < 33; k++) {
				visited[i][j][k] = false;
				store[i][j][k] = 'x';
			}
		}
	}

	cin >> L >> R >> C;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				char temp;
				cin >> temp;
				store[i][j][k] = temp;
				if (store[i][j][k] == 'S') {
					start_x = i;
					start_y = j;
					start_z = k;
				}
			}
		}
	}
}

void bfs() {
	vector<string> nodes;
	flag = false;
	nodes.push_back(to_string(start_x) + to_string(start_y) + to_string(start_z)); // 1층 1행 1열의 경우 111로 저장
	visited[start_x][start_y][start_z] = true;
	int tries = 0;

	while (!nodes.empty()) {
		tries++;
		vector<string> next_nodes;
		for (int i = 0; i < nodes.size(); i++) { // 각각의 노드들에 대해
			
			int x = nodes[i][0] - '0'; // 현재 층
			int y = nodes[i][1] - '0'; // 행
			int z = nodes[i][2] - '0'; // 열
			for (int n = 0; n < 6; n++) { // 다음 길 알아보기
				int nx = x + dx[n]; // 다음 층
				int ny = y + dy[n]; // 행
				int nz = z + dz[n]; // 열
				if (nx >= 1 && nx <= L &&
					ny >= 1 && ny <= R &&
					nz >= 1 && nz <= C && // 존재하는 장소고
					store[nx][ny][nz] != '#') { // 아직 안 갔고 벽이 아니면
					if (store[nx][ny][nz] == '.' || store[nx][ny][nz] == 'E') {
						if (visited[nx][ny][nz] == false) {
							visited[nx][ny][nz] = true;
							next_nodes.push_back(to_string(nx) + to_string(ny) + to_string(nz)); // 해당 지역 다음 노드에 추가
						}
					}

				}
			}

		}

		nodes = next_nodes;	
	}


	if (tries == 1) {
		cout << "Trapped!" << endl;
	}
	else
		cout << "Escaped in " << tries - 1 << " minute(s).\n";


}

void dfs(int x, int y, int z, int depth) {

	if (depth == 15) return;

	if (store[x][y][z] == 'E') {
		//answers.push_back(depth);
		return;
	}

	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];

		if (nx >= 1 && nx <= L && 
			ny >= 1 && ny <= R && 
			nz >= 1 && nz <= C && 
			visited[nx][ny][nz] == false && 
			store[x][y][z] != '#') {

			visited[nx][ny][nz] = true;
			dfs(nx, ny, nz, depth + 1);
			visited[nx][ny][nz] = false;

		}
	}
}

void solve() {
	bfs();
}

int main() {
	while (true) {
		input();
		if (L == 0 && R == 0 && C == 0)
			break;
		solve();
	}
	return 0;
}