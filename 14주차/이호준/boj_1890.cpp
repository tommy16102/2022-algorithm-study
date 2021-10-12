/*******************************************************************
Algorithm Study
Baekjoon OJ DP
1890 점프
2021/10/12 이호준
# 아이디어
1. DP를 이용해 해당 위치로 갈 수 있는 경우의 수를 구한다.
문제의 정의에 따라 아래나 오른쪽으로 점프할 수 있다.
먼저 첫번째 시작 지점에서 점프할 수 있는 지점들을 구한 후 점프하도록 한다.
제출을 끝내고 아이디어를 정리하다보니 첫번째 시작지점 만 체크하고 다음엔 그냥 dp로 하면 if문을 처리할 필요가 없었을 것 같다.
모든 지점을 체크하여 헤당 지점이 왔던 곳이라면 거기서 부터 점프할 수 있는 지점을 확인하여 answer에 더해주는 방식
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

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

    vector<vector<ll>> answer(n, vector<ll>(n, 0));

    answer[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (answer[0][i] != 0)
        {
            if (i + map[0][i] < n)
            {
                answer[0][i + map[0][i]] += answer[0][i];
            }
        }

        if (answer[i][0] != 0)
        {
            if (i + map[i][0] < n)
            {
                answer[i + map[i][0]][0] += answer[i][0];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == n - 1 && j == n - 1)
                continue;
            if (i != 0 && answer[i][j] != -1)
            {
                if (j + map[i][j] < n)
                {
                    answer[i][j + map[i][j]] += answer[i][j];
                }
            }

            if (answer[i][j] != -1)
            {
                if (j != 0 && i + map[i][j] < n)
                {
                    answer[i + map[i][j]][j] += answer[i][j];
                }
            }
        }
    }

    //for (auto a : answer) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl << endl;
    //}

    cout << answer[n - 1][n - 1];
    return 0;
}