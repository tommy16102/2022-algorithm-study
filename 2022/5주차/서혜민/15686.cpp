#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

2022.2.11

재귀를 통해 입력받은 치킨집 중 M개를 골라서,
각 집에서 가장 가까운 치킨집까지의 경로의 합을 구해나간다.

*/

int N, M;
int city[51][51];
bool checked[14];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int minD = 50 * 50 * 13;

void calcDist() {
	int dist = 0;
	for (int i = 0;i < home.size();i++) {
		int homeI = home[i].first;
		int homeJ = home[i].second;
		int minDist = 50 * 50;
		for (int j = 0;j < chicken.size();j++) {
			if (!checked[j]) continue;
			int chickenI = chicken[j].first;
			int chickenJ = chicken[j].second;
			minDist = min(minDist, abs(homeI - chickenI) + abs(homeJ - chickenJ));
		}
		dist += minDist;
	}
	if (dist < minD) minD = dist;
}

void pickChicken(int index, int cnt) {
	if (cnt == M) {
		calcDist();
		return;
	}

	for (int i = index + 1;i < chicken.size();i++) {
		checked[i] = 1;
		pickChicken(i, cnt + 1);
		checked[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	
	for (int i = 0;i < chicken.size();i++) {
		checked[i] = 1;
		pickChicken(i, 1);
		checked[i] = 0;
	}

	cout << minD << '\n';
}
