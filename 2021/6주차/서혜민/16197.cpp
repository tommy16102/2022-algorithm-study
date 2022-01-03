#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*

2021.08.13 서혜민

동전의 좌표와 버튼을 누른 횟수를 저장하는 두개의 que에 먼저 입력받은 보드에서
두 동전의 위치를 찾아내서 이들의 좌표와 횟수 0을 넣어놓는다.
그 뒤, 동전 2개 각각의 위치를 기준으로 위, 오른쪽, 아래, 왼쪽 중 가능한 방향으로 이동했을 때의 좌표를 계속 queue에 넣어준다.
이 때, 동전 중에 해당 방향에 #이 있으면 그 때의 좌표는 바꾸지 않고 그대로 유지시켜주며, 이 둘의 좌표가 같아지거나, 방문했던 곳은 다시 방문할 수가 없다.

그래서 가장 먼저 이 두개의 동전 중 하나만 보드의 영역 밖에 있는 동전이 나올 때의 횟수가 정답이 된다.

*/

int N, M;
string board[22];
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,1,0,-1 };
bool visited[22][22][22][22];

queue<pair<pair<int, int>, int>> queue1;
queue<pair<pair<int, int>, int>> queue2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	board[0] = string(M+2, ' ');
	board[21] = string(M + 2, ' ');
	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		board[i] = ' ' + s + ' ';
	}
	
	int coinx[2];
	int coiny[2];
	int count = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (board[i][j] == 'o') {
				coinx[count] = i;
				coiny[count] = j;
				count++;

			}
		}
	}
	queue1.push({ {coinx[0],coiny[0]},0 });
	queue2.push({ {coinx[1],coiny[1]},0 });
	visited[coinx[0]][coiny[0]][coinx[1]][coiny[1]] = 1;

	count = 0;
	while (!queue1.empty() || !queue2.empty()) {
		int coin1x = queue1.front().first.first;
		int coin1y = queue1.front().first.second;
		int coin2x = queue2.front().first.first;
		int coin2y = queue2.front().first.second;
		count = queue1.front().second;

		if (count > 10) break;
		if ((coin1x == 0 || coin1x == N + 1 || coin1y == 0 || coin1y == M + 1) && (coin2x > 0 && coin2x <= N && coin2y > 0 && coin2y <= M)) {
			cout << count << endl;
			return 0;
		}
		if ((coin2x == 0 || coin2x == N + 1 || coin2y == 0 || coin2y == M + 1) && (coin1x > 0 && coin1x <= N && coin1y > 0 && coin1y <= M)) {
			cout <<count << endl;
			return 0;
		}

		queue1.pop();
		queue2.pop();

		for (int i = 0;i < 4;i++) {
			int newcoin1x = coin1x + moveX[i];
			int newcoin1y = coin1y + moveY[i];
			int newcoin2x = coin2x + moveX[i];
			int newcoin2y = coin2y + moveY[i];
		
			if (board[newcoin1x][newcoin1y] == '#' && board[newcoin2x][newcoin2y] == '#') continue;

			if (newcoin1x == newcoin2x && newcoin1y == newcoin2y) continue;
			
			if (((newcoin1x == 0 || newcoin1x == N + 1 || newcoin1y == 0 || newcoin1y == M + 1) &&
				(newcoin2x == 0 || newcoin2x == N + 1 || newcoin2y == 0 || newcoin2y == M + 1))) continue;

			else if (board[newcoin1x][newcoin1y] == '#') {
				newcoin1x -= moveX[i];
				newcoin1y -= moveY[i];

			}
			else if (board[newcoin2x][newcoin2y] == '#') {
				newcoin2x -= moveX[i];
				newcoin2y -= moveY[i];
			}
			
			
			if (!visited[newcoin1x][newcoin1y][newcoin2x][newcoin2y]){
				visited[newcoin1x][newcoin1y][newcoin1x][newcoin1y] = 1;
				queue1.push({ { newcoin1x, newcoin1y },count + 1 });
				queue2.push({ { newcoin2x, newcoin2y },count + 1 });
			}
		}
	}
	cout << -1 << endl;
}
