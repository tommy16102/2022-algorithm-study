/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2580 스도쿠
2021/08/08 이호준
# 아이디어
1. 가로, 세로, 9개칸에 1~9까지가 존재하는 조건을 만족하는 것이 문제이다.
값이 정해진 빈칸들 부터 채워가면 풀 수 있지않을까?

2. 그냥 빈칸에 1 ~ 9 까지 넣으면서 되는지 dfs를 통해 진행하고 되지않으면 backtracking을 실시한다..
구글의 힘을 빌렸다.. 
위와 같은 방식으로 풀면되는 것을 알게 되었다. 
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(9, vector<int>(9, 0));
vector<pair<int, int>> points;
bool found = false;

bool check(pair<int, int> p)
{
    int row = p.first / 3;
    int column = p.second / 3;
    for (int i = 0; i < 9; i++)
    {
        if (map[p.first][i] == map[p.first][p.second] && i != p.second)
            return false;
        if (map[i][p.second] == map[p.first][p.second] && i != p.first)
            return false;
    }
    for (int i = 3 * row; i < 3 * row + 3; i++)
    {
        for (int j = 3 * column; j < 3 * column + 3; j++)
        {
            if (map[i][j] == map[p.first][p.second])
            {
                if (i != p.first && j != p.second)
                    return false;
            }
        }
    }

    return true;
}

void sudoku(int N)
{

    if (found)
        return;

    if (N == points.size())
    {
        found = true;
        for (auto a : map)
        {
            for (auto b : a)
                cout << b << " ";
            cout << "\n";
        }
        return;
    }
    for (int j = 1; j <= 9; j++)
    {
        map[points[N].first][points[N].second] = j;
        if (check(points[N]))
            sudoku(N + 1);
        map[points[N].first][points[N].second] = 0;
    }
    return;
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                points.push_back(make_pair(i, j));
        }
    }

    sudoku(0);

    return 0;
}