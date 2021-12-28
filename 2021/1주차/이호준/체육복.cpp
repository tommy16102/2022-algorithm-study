/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * Greedy / 완주하지 못한 선수
 * 2021 / 07 / 12  이호준
 * 여유분을 가진 reserver인원을 통해 unordered_map을 생성
 * 먼저 여유분을 가지고 있지만 lost한 인원을 찾는다. (lost와 reserve모두 존재하는 인원)
 * 해당인원을 reserve와 lost에서 제외한다.
 * 그리고 lost배열을 순서대로 탐새하면서 자신의 숫자 -1, +1인 경우가 존재하는 지 순서대로 탐색하고
 * 있다면 빌린다는 의미로 more(map)과 lost에서 삭제한다.
 * 만약 more이 empty()(더이상 빌릴 곳 존재 x)거나 lost를 다 탐색하면 더이상 탐색할 필요가 없다.
 * 남은 lost배열의 길이를 통해 최대 몇명이 체육 수업을 들을 수 있을지 알 수 있다.
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    unordered_map<int, int> more;
    for (auto &a : reserve)
    {
        more.insert(make_pair(a, a));
    }
    for (auto i = lost.begin(); i != lost.end(); i++)
    {
        if (more.find(*i) != more.end())
        {
            more.erase(more.find(*(i)));
            i--;
            lost.erase(i + 1);
        }
    }
    for (auto i = lost.begin(); i != lost.end(); i++)
    {
        if (more.empty())
            break;
        if ((*i) > 1 && more.find(*(i)-1) != more.end())
        {
            more.erase(more.find(*(i)-1));
            i--;
            lost.erase(i + 1);
        }
        else if (((*i) + 1) <= n && more.find(*(i) + 1) != more.end())
        {
            more.erase(more.find(*(i) + 1));
            i--;
            lost.erase(i + 1);
        }
    }
    answer = n - lost.size();
    return answer;
}