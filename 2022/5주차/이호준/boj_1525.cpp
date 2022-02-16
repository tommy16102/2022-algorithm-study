/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
1525 퍼즐
2022/02/14 이호준
# 아이디어
1. set을 이용해 visited를 해결한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0, 0, 1, -1 };

string End = "123456780";
string Start = "";
set<string> Visit;

int BFS()
{
	queue<pair<string, int>> q;
	q.push({ Start, 0 });
	Visit.insert(Start);

	while (!q.empty())
	{
		string current = q.front().first;
		int Cnt = q.front().second;
		q.pop();

		if (current == End) return Cnt;

		int Zero = current.find('0');
		int x = Zero / 3;
		int y = Zero % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3)
			{
				string Next = current;
				swap(Next[x * 3 + y], Next[nx * 3 + ny]);

				if (Visit.find(Next) == Visit.end())
				{
					Visit.insert(Next);
					q.push({ Next, Cnt + 1 });
				}
			}
		}
	}
	return -1;
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int temp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			Start = Start + char(temp + 48);
		}
	}
	cout << BFS() << "\n";

	return 0;
}