#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*

2021.08.09 서혜민

dfs를 통해서 왼쪽 상단의 지점에서부터 지나온 알파벳은 해당 알파벳 -'A'를 해줘서 count 배열 내 인덱스를 1로 바꾸고
visited배열을 통해 한번 간 곳은 다시 갈 수 없도록 탐색을 한다.

dfs의 세번째 매개변수 cnt를 통해 탐색이 끝나면 전역변수인 max와 비교를 해서 더 크다면 max 수정.

*/

bool count[26] = { 0, }; //알파벳
bool visited[21][21] = { 0, };
string alphabet[21];
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,1,0,-1 };
int max = -1;
int R, C;

void dfs(int x, int y, int cnt) {
	for (int i = 0;i < 4;i++) {
		int newX = x + moveX[i];
		int newY = y + moveY[i];
		if (newX >= 1 && newY >= 1 && newX <= R && newY <= C && !::count[alphabet[newX][newY] - 'A'] && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			::count[alphabet[newX][newY] - 'A'] = 1;
			dfs(newX, newY, cnt + 1);
			visited[newX][newY] = 0;
			::count[alphabet[newX][newY] - 'A'] = 0;
		}
	}
	if (cnt > ::max) ::max = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	alphabet[0] = "";
	for (int i = 1;i <= R;i++) {
		string s;
		cin >> s;
		alphabet[i] = " " + s;
	}
	::count[alphabet[1][1] - 'A'] = 1;
	visited[1][1] = 1;
	dfs(1, 1, 1);

	cout << ::max << endl;
}
