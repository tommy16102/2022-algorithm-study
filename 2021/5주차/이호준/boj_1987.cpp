/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
1987 알파벳
2021/08/08 이호준
# 아이디어
1. dfs로 탐색한다. 이때 이미 지나간 문자가 있으면 그 문자를 다시 지나가지 못하게한다.
아이디어는 바로 떠올랐고 맞았다.
그러나 시간초과로 고생한 문제이다.
1. string의 find
2. unordered_set
3. unordreed_map
set과 map보다 string find가 더빨랐다. .. 그러나 3방법 모두 되지않았고
생각해보니 dfs과정에서 알파벳 배열을 하나만들고 체크만하면된다는 것을 알게되었다.
그리고 dfs시 string을 만들어가면서 넘겼는데 그걸 지우니까 바로 해결되었다.

근데 풀이를 보니 set이나 map을 쓴것이 더 빠른것 같다. 확인해봐야겠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool check[26];

void dfs(int x, int y, int current, int &answer, vector<vector<char>> &map);

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
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}

    int answer = 1;
    check[map[0][0] - 'A'] = true;
    dfs(0, 0, 1, answer, map);
    cout << answer;
    return 0;
}

void dfs(int x, int y, int current, int &answer, vector<vector<char>> &map)
{
    int r = map.size();
    int c = map[0].size();
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c)
        {
            char temp = map[nx][ny];
            if (!check[temp - 'A'])
            {
                check[temp - 'A'] = true;
                dfs(nx, ny, current + 1, answer, map);
                count++;
                check[temp - 'A'] = false;
            }
        }
    }

    if (count == 0)
    {
        if (answer < current)
            answer = current;
    }
}
