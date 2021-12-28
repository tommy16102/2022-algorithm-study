/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 
DP 정수 삼각형
2021/09/18 이호준
# 아이디어
1. 루트에서 부터 내려갈 때 왼쪽 오른쪽으로 이동할 수 있다.
이때 삼각형의 특성상 각 층의 맨 오른쪽 항과 맨 왼쪽항은 값이 1개로 정해지고
( triangle[i][0] += triangle[i - 1][0];  triangle[i][j] += triangle[i - 1][j - 1];)
다른 항들은 왼쪽에서 오는 경우 오른쪽에서 내려 오는 경우 2가지가 생긴다.
그런데 우리는 합이 최고인 경우를 구하기 때문에 이 왼쪽에서, 오른쪽에서 오는 값중에서 큰 값만 저장하면된다.
왜냐하면 왼쪽에서 오던 오른쪽에서 오던 그 항이 그 다음 층으로 내려갈 때 더해지는 값들은 동일하기 때문이다
그렇기 때문에 그 항의 값이 더 큰 값만 생각하면된다.
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][0] += triangle[i - 1][0];
            }
            else if (j == triangle[i].size() - 1)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] = max(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j]);
            }
        }
    }
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    return answer;
}