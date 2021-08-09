#include <iostream>
#include <queue>
using namespace std;

/*

2021.08.16 서혜민

S층에서부터 시작하여 BFS를 통해 U 또는 D로 가는 걸 탐색.
해당 층과 버튼 누른횟수를 벡터에 저장하면서 한번 들린 층은 다시 들릴 수 없고,
F층 보다는 높이 갈 수 없으며, 1층 보다는 아래로 갈 수 없도록 한다.

*/

bool visited[1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> que;
	que.push({ S, 0 });
	visited[S] = 1;

    while (!que.empty())
    {
        int floor = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (floor == G) {
            cout << cnt << endl;
            return 0;
        }
        if (floor + U <= F && !visited[floor + U])
        {
            que.push(make_pair(floor + U, cnt + 1));
            visited[floor + U] = 1;;
        }
        if (floor - D > 0 && !visited[floor - D])
        {
            que.push(make_pair(floor - D, cnt + 1));
            visited[floor - D] = 1;
        }
    }
	cout << "use the stairs" << '\n';
}
