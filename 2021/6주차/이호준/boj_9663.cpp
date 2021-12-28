/*******************************************************************
Algorithm Study
Baekjoon 6주차
9663 N-Queen
2021/08/12 이호준
# 아이디어
1. 퀸의 움직임 대로 backtracking
퀸이 놓인 위치로부터 퀸이 움직일 수 있는 모든 곳의 위치에 +1하여 체크한다.
첫번째 행에 놓을 수 있는 n가지 위치에 대해서 backtracking을 반복한다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int count, vector<vector<int>> &chess);
void print(vector<vector<int>> &chess);

int answer;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> chess(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        // 0 i
        for (int j = 0; j < n; j++)
            chess[0][j]++;
        for (int j = 0; j < n; j++)
            chess[j][i]++;
        for (int j = 0; j < n && i + j < n; j++)
            chess[0 + j][i + j]++;
        for (int j = 0; i >= j && j < n; j++)
            chess[0 + j][i - j]++;
        dfs(1, chess);
        for (int j = 0; j < n; j++)
            chess[0][j]--;
        for (int j = 0; j < n; j++)
            chess[j][i]--;
        for (int j = 0; j < n && i + j < n; j++)
            chess[0 + j][i + j]--;
        for (int j = 0; i >= j && j < n; j++)
            chess[0 + j][i - j]--;
    }

    cout << answer << endl;

    return 0;
}

void dfs(int count, vector<vector<int>> &chess)
{
    int n = chess.size();

    if (count == n)
    {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (chess[count][i] == 0)
        {
            for (int j = 0; j < n; j++)
                chess[count][j]++;
            for (int j = 0; j < n; j++)
                chess[j][i]++;
            for (int j = 0; count + j < n && i + j < n; j++)
                chess[count + j][i + j]++;
            for (int j = 1; j <= count && j <= i; j++)
                chess[count - j][i - j]++;
            for (int j = 0; count + j < n && i >= j; j++)
                chess[count + j][i - j]++;
            for (int j = 0; i + j < n && count - j >= 0; j++)
                chess[count - j][i + j]++;
            //print(chess);
            dfs(count + 1, chess);
            for (int j = 0; j < n; j++)
                chess[count][j]--;
            for (int j = 0; j < n; j++)
                chess[j][i]--;
            for (int j = 0; count + j < n && i + j < n; j++)
                chess[count + j][i + j]--;
            for (int j = 1; j <= count && j <= i; j++)
                chess[count - j][i - j]--;
            for (int j = 0; count + j < n && i >= j; j++)
                chess[count + j][i - j]--;
            for (int j = 0; i + j < n && count - j >= 0; j++)
                chess[count - j][i + j]--;
        }
    }
}

void print(vector<vector<int>> &chess)
{
    for (auto a : chess)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl
         << endl;
}