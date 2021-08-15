/*******************************************************************
Algorithm Study
Baekjoon 6주차
14500 테트로미노
2021/08/14 이호준
# 아이디어
1. DFS로 정사각형 4개 위치를 탐색하여 max를 찾는다.
이떄 시작위치는 모든 지점에서 탐색해야한다.
그렇기 떄문에 4개를 탐색할때 위로올라가는 것은 수행하지않는다(중복되므로)

그런데 ㅗ 도형은 dfs로 탐색이 불가능한 도형이다. 이 도형만 예외처리해준다. 

※ 처음에 문제를 잘 못 이해했었다. 문제를 잘 읽느것이 중요하다는 것을 다시 느꼈다.

*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

bool visited[501][501];

using namespace std;

void dfs(vector<vector<int>> &map, int sum, int current, int x, int y);

int dy[4] = {-1, 0, 0};
int dx[4] = {0, -1, 1};
int max_value;
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int x = 0;

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(map, map[i][j], 1, i, j);
            visited[i][j] = false;
        }
    }

    //	ㅗ 모양확인 dfs로 확인 불가능하므로

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            // 1. ㅜ
            if (i + 1 < n && j + 2 < m)
            {
                sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
                max_value = max(max_value, sum);
            }

            // 2. ㅏ
            if (i + 2 < n && j + 1 < m)
            {
                sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
                max_value = max(max_value, sum);
            }

            // 3. ㅗ
            if (i - 1 >= 0 && i < n && j + 2 < m)
            {
                sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
                max_value = max(max_value, sum);
            }

            // 4. ㅓ
            if (i - 1 >= 0 && i + 1 < n && j + 1 < m)
            {
                sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i + 1][j + 1];
                max_value = max(max_value, sum);
            }
        }
    }

    cout << max_value << endl;

    return 0;
}

void dfs(vector<vector<int>> &map, int sum, int current, int x, int y)
{
    if (current == 4)
    {
        max_value = max(max_value, sum);
        return;
    }

    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                dfs(map, sum + map[nx][ny], current + 1, nx, ny);
                visited[nx][ny] = false;
            }
        }
    }
}
