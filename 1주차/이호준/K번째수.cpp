/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * Sort / K번째 수 
 * 2021 / 07 / 12  이호준
 * 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하는 문제이다.
 * a번째 순서의 해당 i, j, k의 정보는 commands[a][0], commands[a][1], commands[a][2]에 존재한다.
 * assign을 통해 해당 범위를 복사하고, sort를 통해 정렬한다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (auto &a : commands)
    {
        vector<int> temp(50);
        temp.assign(array.begin() + a[0] - 1, array.begin() + a[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[a[2] - 1]);
    }
    return answer;
}