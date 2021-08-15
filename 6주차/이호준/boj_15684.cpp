/*******************************************************************
Algorithm Study
Baekjoon 6주차
15684 사다리 조작
2021/08/15 이호준
# 아이디어
1. dfs로 탐색한다.
문제를 구현하는데 처음에 어려움을 겪었다.
구현을 쉽게하기 위해 배열의 크기를 1개 크게 하고 0을 통해서 연산에는 영향이 없게 했다.
그리고 시간초과가 발생했다.
필요없는 중복에 대해서 항상 생각해야한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_value = 5;
bool check(vector<vector<int>> &map);
void print(vector<vector<int>> &map);
bool visited[50][50];

void dfs(vector<vector<int>> &map, int current, int x, bool &flag);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h, m;

    cin >> n >> h >> m;

    vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < h; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        visited[x][y] = true;
    }

    bool flag = false;
    dfs(map, 1, 1, flag);

    cout << (min_value == 5 ? -1 : min_value) << endl;

    return 0;
}

bool check(vector<vector<int>> &map)
{
    bool answer = true;

    int n = map.size();
    int m = map[0].size();

    for (int i = 1; i < m; i++)
    {
        int current = 1;
        int check = i;
        while (current != n)
        {
            if (map[current][check] == 1)
                check++;
            else if (map[current][check - 1] == 1)
                check--;
            current++;
        }
        if (check != i)
        {
            answer = false;
            break;
        }
    }

    return answer;
}

void print(vector<vector<int>> &map)
{
    for (auto a : map)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<vector<int>> &map, int current, int x, bool &flag)
{
    if (flag || current > 4 || current - 1 >= min_value)
        return;

    if (check(map))
    {
        min_value = min(current - 1, min_value);
        if (min_value == 0)
            flag = true;
        return;
    }

    int n = map.size();
    int m = map[0].size() - 1;

    for (int i = x; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (!visited[i][j])
            {
                if (map[i][j - 1] || map[i][j] || map[i][j + 1])
                    continue;
                visited[i][j] = true;
                map[i][j] = 1;
                dfs(map, current + 1, i, flag);
                visited[i][j] = false;
                map[i][j] = 0;
            }
        }
    }
}
