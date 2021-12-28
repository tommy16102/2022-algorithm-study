/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
16956 늑대와 양 
2021/08/05 이호준
# 아이디어
1. 상하좌우 이동을 간편히 하는 방법을 익혔다.
문제는 좀 그랬다. 처음에 이해를 못했다.
S의 위치를 찾고 W가 주변에 있으면 막지 못한다.
그외에는 막을 수 있다. D는 주변에 상하좌우로 간편히 채우도록 구현했다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c, ' '));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    //for (auto a : map) {
    //	for (auto b : a) {
    //		cout << b << " ";
    //	}
    //	cout << endl;
    //}
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'S')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c)
                    {
                        if (map[nx][ny] == 'W')
                        {
                            cout << 0;
                            return 0;
                        }
                        else if (map[nx][ny] == '.')
                        {
                            map[nx][ny] = 'D';
                        }
                    }
                }
            }
        }
    }

    cout << 1 << "\n";
    for (auto a : map)
    {
        for (auto b : a)
        {
            cout << b;
        }
        cout << endl;
    }

    return 0;
}
