#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*

2021.08.02 서혜민

bfs를 통해서 방문하지 않은 square내 1인 지역을 탐색해낸다.
탐색을 할 때마다 count를 늘려준 뒤, 탐색 끝나면 벡터에 삽입.
벡터내 원소 개수->단지 개수, 원소->단지 내 집의 수

*/
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };
bool visited[25][25] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string* square = new string[N];
	
	for (int i = 0;i < N;i++) cin >> square[i];

	vector<int> v;
	queue<pair<int, int>> queue;
	int count;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j] && (square[i][j] == '1')) {
				queue.push({ i,j });
				visited[i][j] = 1;
				count = 1;
				while (!queue.empty()) {
					int x = queue.front().first;
					int y = queue.front().second;
					queue.pop();
					for (int k = 0;k < 4;k++) {
						int newX = x + moveX[k];
						int newY = y + moveY[k];
						if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY] && square[newX][newY]=='1') {
							queue.push({ newX,newY });
							visited[newX][newY] = 1;
							count++;
						}
					}
				}v.push_back(count);
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (auto& i : v) cout << i << endl;
}