///*******************************************************************
//Algorithm Study
//Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
//Hash / 위장
//2021/07/15 이호준
//# 의도
// 각 종류의 의상개수를 구한 후 최소 1개이상의 옷을 입은 경우의 수를 구하는 문제이다.
// a+b+c+ab+ac+bc+abc 를 구하는 것인데
// (1+a)(1+b)(1+c) = a+b+c+ab+ac+bc+abc 를 이용한다
// 해당 의상을 안입는다라는 경우의 수를 추가하고
// 전부 안입은 경웅의 수를 뺴는 것과 같다.
//*******************************************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    unordered_map<string, int> kind;
    for (auto &a : clothes)
    {
        if (kind.find(a[1]) == kind.end())
        {
            kind.insert(make_pair(a[1], 1));
        }
        else
        {
            kind[a[1]]++;
        }
    }
    vector<int> count;
    count.reserve(kind.size());
    for (auto &a : kind)
    {
        count.push_back(a.second);
    }
    int temp = 1;
    for (auto &a : count)
        temp *= (a + 1);
    answer = temp - 1;
    return answer;
}
int main(void)
{
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes) << endl;
}