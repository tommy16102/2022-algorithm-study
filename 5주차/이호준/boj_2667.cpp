/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2667 단지번호붙이기 
2021/08/05 이호준
# 아이디어
1. 단순히 BFS로 집이 있는 곳을 탐색하여 단지를 체크한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(int x, int y, vector<vector<int>> &map, int count);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }
    //for (auto a : map) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                answer.push_back(bfs(i, j, map, ++count));
            }
        }
    }
    //for (auto a : map) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto a : answer)
        cout << a << "\n";
    return 0;
}

int bfs(int x, int y, vector<vector<int>> &map, int count)
{

    int s = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int n = map.size();
    if (count == 1)
        map[x][y] = 0;
    else
        map[x][y] = count;
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
                if (map[nx][ny] == 1)
                {
                    q.push(make_pair(nx, ny));
                    s++;
                    if (count == 1)
                        map[nx][ny] = 0;
                    else
                        map[nx][ny] = count;
                }
            }
        }
    }
    return s;
}
