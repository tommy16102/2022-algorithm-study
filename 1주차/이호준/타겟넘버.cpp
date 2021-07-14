/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * DFS / 타겟 넘버
 * 2021 / 07 / 12  이호준
 * 각 숫자는 +와 -연산이 가능하다.
 * 모든 숫자가 사용되기 때문에 각 숫자마다 가능한 +와 -연산을 DFS로 탐색하여 모든 경우의 수를 탐색할 수 있다.
*/
#include <string>
#include <vector>
using namespace std;

void dfs(vector<int> numbers, int sum, int target, int step, int &count)
{
    if (step == numbers.size())
    {
        if (sum == target)
            count++;
    }
    else
    {
        dfs(numbers, sum + numbers[step], target, step + 1, count);
        dfs(numbers, sum - numbers[step], target, step + 1, count);
    }
}

int solution(vector<int> numbers, int target)
{
    int count = 0;
    dfs(numbers, 0, target, 0, count);
    return count;
}