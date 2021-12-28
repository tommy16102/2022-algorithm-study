/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2583 영역 구하기 
2021/08/05 이호준
# 아이디어
1. 문제의 좌표를 통해 맵을 그린다.
맵에서 완전탐색을 통해 직사각형이 없는 곳을 찾고 해당 부분에서 BFS를 진행한다.
BFS를 진행하면서 이동한 공간은 직사각형이 있는것 과 동일하게 1로 표현한다.
위와 같은 방법을 통해 모든 공간을 검사하여 빈 영역을 찾는다.

※ 맨 처음 문제의 좌표가 위아래가 반대고 좌표로 나와 정신이 나갔었다.
하지만 관계를 잘 생각하면 앞으로는 쉽게 정리할 수 있을 것 같다.
왼쪽 아래와 오른쪽 끝점을 통해 직사각형을 이루는 정사각형의 개수를 얻을 수 있다.
그리고 시작 좌표 즉 직사각형의 맨 왼쪽 상단 좌표를 구하면 2중 for문을 통해 직사각형을 그래프에 표현할 수 있다.
(x, y) (a, b)
map[M - a + j][y + k] = 1;
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(int x, int y, vector<vector<int>> &map);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, K;

    cin >> M >> N >> K;

    vector<vector<int>> map(M, vector<int>(N, 0));
    vector<int> answer;
    for (int i = 0; i < K; i++)
    {
        int x, y, a, b;
        cin >> y >> x >> b >> a;

        for (int j = 0; j < a - x; j++)
        {
            for (int k = 0; k < b - y; k++)
            {
                map[M - a + j][y + k] = 1;
            }
        }
    }

    //for (auto a : map) {
    //	for (auto b : a)
    //		cout << b;
    //	cout << endl;
    //}

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 1)
            {
                answer.push_back(bfs(i, j, map));
                //for (auto a : map) {
                //	for (auto b : a)
                //		cout << b;
                //	cout << endl;
                //}
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ((i != answer.size() - 1) ? " " : "");
    return 0;
}

int bfs(int x, int y, vector<vector<int>> &map)
{
    int s = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    map[x][y] = 1;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a + 1 < map.size() && map[a + 1][b] == 0)
        {
            q.push(make_pair(a + 1, b));
            s++;
            map[a + 1][b] = 1;
        }
        if (a - 1 >= 0 && map[a - 1][b] == 0)
        {
            q.push(make_pair(a - 1, b));
            s++;
            map[a - 1][b] = 1;
        }
        if (b + 1 < map[0].size() && map[a][b + 1] == 0)
        {
            q.push(make_pair(a, b + 1));
            s++;
            map[a][b + 1] = 1;
        }
        if (b - 1 >= 0 && map[a][b - 1] == 0)
        {
            q.push(make_pair(a, b - 1));
            s++;
            map[a][b - 1] = 1;
        }
    }
    return s;
}

/*
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2


*/