#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.08.09 서혜민

입력받은 사각형의 왼쪽 아래 좌표와 오른쪽 위의 좌표를 통해서
사각형 안의 좌표들을 모두 1로 한 뒤,
이중포문을 통해서 좌표가 사각형에 있지 않고, 아직 방문하지 않은 좌표인 좌표들을 dfs를 통해 탐색을 해주었다.
한번 dfs를 해서 그 dfs가 끝날 때까지 count를 늘려가서 최종 count개수를 벡터에 넣어주므로,
벡터의 원소 개수가 영역의 개수가 된다.

*/

int arr[101][101] = { 0, };
bool visited[101][101] = { 0, };
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };
int N, M, K, count;

void dfs(int x, int y) {
	::count++;
	visited[x][y] = true;
	for (int i = 0;i < 4;i++) {
		int newX = x + moveX[i];
		int newY = y + moveY[i];
		if (newX >= 0 && newX < N && newY >= 0 &&newY < M && !visited[newX][newY] && !arr[newX][newY]) dfs(newX, newY);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	while (K--) {
		int  lx, ly, rx, ry;
		cin >> ly >> lx >> ry >> rx;
		for (int i = lx;i < rx;i++) {
			for (int j = ly;j < ry;j++) {
				arr[i][j] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			::count = 0;
			if (!arr[i][j] && !visited[i][j]) {
				dfs(i, j);
				v.push_back(::count);
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++)cout << v[i] << ' ';
	cout << endl;
}
