/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
1780 종이의 개수
2021/08/08 이호준
# 아이디어
1. 분할 정복에 대한 문제였다..
처음으로 구현해봐서 아이디어가 빨리 생각나지 않았다.
재귀로 호출하면서 분할 정복하는 merge sort의 구현 아이디어와 비슷하다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void divide(int x, int y, int size, vector<vector<int>> &map);
bool isSame(int x, int y, int size, vector<vector<int>> &map);

int answer[3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    divide(0, 0, n, map);
    for (int i = 0; i < 3; i++)
        cout << answer[i] << endl;

    return 0;
}

void divide(int x, int y, int size, vector<vector<int>> &map)
{
    if (isSame(x, y, size, map))
    {
        answer[map[x][y] + 1]++;
    }
    else
    {
        size /= 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                divide(x + size * i, y + size * j, size, map);
            }
        }
    }
}

bool isSame(int x, int y, int size, vector<vector<int>> &map)
{
    int check = map[x][y];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (map[x + i][y + j] != check)
            {
                return false;
            }
        }
    }
    return true;
}
