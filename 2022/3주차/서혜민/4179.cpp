#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

2022.1.26

불 먼저 시작 지점부터 BFS를 통해 소요 시간을 저장해놓고,
지훈이도 마찬가지로 시작 지점부터 BFS를 통해 소요시간을 저장하는 데,
이때 어떤 지점까지의 소요시간이 불이 해당 지점까지 번지는 소요시간보다 작을 때만, 
탐색을 이어나간다.

*/

char miro[1001][1001];
int fire[1001][1001];
int ji[1001][1001];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;

	int jI, jJ;
	vector<pair<int, int>> fIJ;

	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			cin >> miro[i][j];
			fire[i][j] = 1001 * 1001 + 1;
			ji[i][j] = 1001 * 1001 + 1;
			if (miro[i][j] == 'J') {
				jI = i;
				jJ = j;
				ji[i][j] = 0;
			}
			if (miro[i][j] == 'F') {
				fIJ.push_back({ i,j });
				fire[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> fQ;
	for (auto place : fIJ) fQ.push({ place.first, place.second });
	while (!fQ.empty()) {
		int i = fQ.front().first;
		int j = fQ.front().second;
		fQ.pop();
		for (int x = 0;x < 4;x++) {
			int newI = i + moveI[x];
			int newJ = j + moveJ[x];
			if (miro[newI][newJ] == '#' || newI<1 || newJ<1 || newI>R || newJ>C) continue;
			if (fire[newI][newJ] > fire[i][j] + 1){
				fire[newI][newJ]=fire[i][j]+1;
				fQ.push({ newI,newJ });
			}
		}
	}

	queue<pair<int, int>> Q;
	Q.push({ jI,jJ });
	while (!Q.empty()) {
		int i = Q.front().first;
		int j = Q.front().second;
		int sec = ji[i][j];
		if (i == R || j == C || i==1 || j==1) {
			cout << sec+1 << '\n';
			return 0;
		}
		Q.pop();
		for (int x = 0;x < 4;x++) {
			int newI = i + moveI[x];
			int newJ = j + moveJ[x];
			if (miro[newI][newJ] == '#' || newI<1 || newJ<1 || newI>R || newJ>C) continue;
			if (sec + 1 >= fire[newI][newJ]) continue;
			if (sec + 1 < ji[newI][newJ]) {
				ji[newI][newJ] = ji[i][j] + 1;
				Q.push({ newI,newJ });
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
