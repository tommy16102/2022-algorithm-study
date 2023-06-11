/*******************************************************************
Algorithm Study
Baekjoon 177779 게더멘더링2
2023/06/11 이호준
# 아이디어
1. 구현
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, total;
int answer = 2000000000;
int A[25][25];

// 구역 나누고, population 벡터에 각 구역 인구 저장
void DivideArea(const int x, const int y, const int d1, const int d2, vector<vector<int>> &board, vector<int> &population)
{
    // 1
    int cnt = 0;
    for(int i = 1; i < x + d1; i++)
    {
        if(i >= x) cnt++;
        for(int j = 1; j <= y - cnt; j++)
        {
            population[1] += A[i][j];
        }
    }

    // 2
    cnt = 0;
    for(int i = 1; i <= x+d2; i++)
    {
        if(i > x) cnt++;
        for(int j = y+1+cnt; j <= N; j++)
        {
            population[2] += A[i][j];
        }
    }

    // 3
    cnt = 0;
    for(int i = N; i >= x + d1; i--)
    {
        if(i < x+d1+d2) cnt++;
        for(int j = 1; j < y+d2-d1-cnt; j++)
        {
            population[3] += A[i][j];
        }
    }

    // 4
    cnt = 0;
    for(int i = N; i > x+d2; i--)
    {
        if(i <= x+d1+d2) cnt++;
        for(int j = y+d2-d1+cnt; j <= N; j++)
        {
            population[4] += A[i][j];
        }
    }
}

void Print(vector<vector<int>> board)
{
    cout << endl;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            total += A[i][j];
        }
    }

    for(int x = 1; x < N; x++)
    {
        for(int y = 0; y < N; y++)
        {

            for(int d1 = 1; d1 < N; d1++)
            {
                for(int d2 = 1; d2 < N; d2++)
                {
                    if(x+d1 > N || y-d1 <= 0) continue; // 좌측 꼭지점
                    if(x+d2 > N || y+d2 > N) continue; // 우측 꼭지점
                    if(x+d1+d2 > N || y+d2-d1 <= 0) continue; // 아래 꼭지점
                    if(x+d2+d1 > N || y-d1+d2 > N) continue;

                    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
                    vector<int> population(6);
                    DivideArea(x, y, d1, d2, board, population);
                    population[5] = total - (population[1]+population[2]+population[3]+population[4]);
                    sort(population.begin(), population.end());
                    answer = min(answer, population[5] - population[1]);
                }
            }
        }
    }

    cout << answer;
}