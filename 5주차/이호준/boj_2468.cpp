/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2468 안전영역
2021/08/06 이호준
# 아이디어
1. BFS완전탐색?
height를 1부터 max height까지 돌리면서
bfs로 각 상황의 영역 개수를 구하면서 최대 값을 구한다.

※ 다른사람들 풀이를 보면 DFS로 푸는사람이 많다. 잘 모르겠따.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int x, int y, vector<vector<int>> &map, vector<vector<bool>> &visited, int height);
void clear(vector<vector<bool>> &visited);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int max = 1;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (max < map[i][j])
                max = map[i][j];
        }
    }
    /*for (auto a : map) {
		for (auto b : a)
			cout << b << " ";
		cout << "\n";
	}*/
    int answer = 1;
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int height = 1; height <= max; height++)
    {
        count = 0;
        //for (auto a : visited) {
        //	for (auto b : a)
        //		cout << b << " ";
        //	cout << endl;
        //}
        clear(visited);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] > height && !visited[i][j])
                {
                    bfs(i, j, map, visited, height);
                    count++;
                }
            }
        }
        //cout << "height : " << height << "  count : " << count << endl;
        if (count > answer)
        {
            answer = count;
        }
    }

    cout << answer;

    return 0;
}

void bfs(int x, int y, vector<vector<int>> &map, vector<vector<bool>> &visited, int height)
{
    int n = map.size();
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (map[nx][ny] > height && !visited[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void clear(vector<vector<bool>> &visited)
{
    int n = visited.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}
