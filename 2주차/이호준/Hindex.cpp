/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Sort / H - Index
2021/07/17 이호준
# 아이디어
내림차순으로 정렬한 후 h-1번째 값이 h이 보다 크거나 같은 지점을 찾으면 된다.

# 문제의 이해가 어려웠다.
  맨 처음 접근했을 때 H-index가 citations내 값인줄 알고 접근했다.
  문제를 잘이해해야한다. 그리고 프로그래머스 설명도 좀 별로다.
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

//6 5 3 1 0
//6 5 4 4 4 4 3 1 0
//6 6 5 3 1 0 3
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());

    int max = citations[0];
    int h = max;
    int size = citations.size();
    for (int h = max; h > 0; h--)
    {
        if ((h - 1) < size && h <= citations[h - 1])
        {
            answer = h;
            break;
        }
    }
    return answer;
}

int main(void)
{
    vector<int> a = {3, 0, 6, 1, 5};
    vector<int> b = {6, 5, 4, 1, 0};
    vector<int> c = {0, 1};
    // [3, 0, 6, 1, 5],	3
    // [6, 5, 4, 1, 0], 3
    // [0, 1] , 1
    cout << "answer : 3\t>>  " << solution(a) << endl;
    cout << "\nanswer : 3\t>>  " << solution(b) << endl;
    cout << "\nanswer : 1\t>>  " << solution(c);
}