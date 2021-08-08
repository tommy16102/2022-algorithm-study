/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2178 미로탐색 
2021/08/06 이호준
# 아이디어
1. 최단거리 = > BFS
문제는 어떻게 최다거리 길이를 아느냐
BFS의 탐색 level을 기억하자.
이전 레벨의 수 : count
현재 새로 보는 레벨의 수 : new_count
queue에서 pop할때 마다 count를 줄이고
위의 변수를 통해 count== 0이 되는 시점에 level을 증가시킨다.
이때 새로운 level의 정보로 업데이트 해야하므로 count를 new_count로 할당하고 new_count를 0으로 하여 새로운 level에 대한 정보를 업데이트한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>> &map, vector<vector<bool>> &visited);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;

    cin >> n >> m;
    cin.ignore();

    vector<vector<int>> map(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        for (int j = 0; j < m; j++)
            map[i][j] = temp[j] - '0';
    }
    //for (auto a : map) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    cout << bfs(map, visited);

    return 0;
}

int bfs(vector<vector<int>> &map, vector<vector<bool>> &visited)
{
    int count = 1;
    int level = 0;
    int new_count = 1;
    int n = map.size();
    int m = map[0].size();
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        count--;
        if (count == 0)
        {
            level++;
            count = new_count;
            new_count = 0;
        }

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == 1 && visited[nx][ny] != true)
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    new_count++;
                }
            }
        }
    }

    return level;
}
