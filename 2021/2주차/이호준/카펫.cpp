/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
완전탐색 / 카펫
2021/07/17 이호준
# 아이디어
brown은 카펫의 외부 1줄을 감싸는 개수이다.
brown : 2*wide + 2*height -4
yellow : (height-2) * (width-2)
위와 같은 관계를 가진다.
parameter로 받은 brown과 yellow로 카펫의 size를 알수있다.
문제에서 width가 더 크거나 같다고 했다.
width * height = size 이고 이는 size의 약수와 같다.
sqrt(size)를 구해 문제에서 가능한 width의 최대 길이를 구하고
해당 약수들을 탐색하면서 brown과 yellow의 조건을 만족하는 width를 찾는다.
*******************************************************************/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
// 1 2 3 4 6 12
vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int size = brown + yellow;

    int width = size;
    int max = sqrt(size - 1) + 1;
    while (width >= max)
    {
        int height = size / width;
        if (brown == 2 * width + 2 * height - 4 && yellow == (height - 2) * (width - 2))
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
        int temp = width - 1;
        while ((size % temp) != 0)
        {
            temp--;
        }
        width = temp;
    }
    return answer;
}

int main(void)
{
    vector<int> a = solution(10, 2);
    cout << "정답 : [4, 3] : ";
    for (auto &i : a)
        cout << i << "  ";
    vector<int> b = solution(8, 1);
    cout << "\n정답 : [3, 3] : ";
    for (auto &i : b)
        cout << i << "  ";
    vector<int> c = solution(24, 24);
    cout << "\n정답 : [8, 6] : ";
    for (auto &i : c)
        cout << i << "  ";
}