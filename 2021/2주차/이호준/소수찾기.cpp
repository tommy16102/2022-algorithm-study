/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Greedy / 소수찾기
2021/07/19 이호준
# 아이디어
1. 최대 가능한 숫자를 만들고 해당 숫자까지 소수를 찾아 만들 수 있는 소수를 카운트 하기
2. next_permutation이용
※ 구글에서 next_permutation을 이용한 풀이를 보고 배웠다.
next_permutation은 parameter로 받은 값을 순열형태로 iterator를 통해 반환시켜준다. do while을 이용해 사용 
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

// 1 2 3
// 1 2 3 12 13 21 23 31 32 123 132 213 231 312 321

bool isPrime(int test)
{
    if (test < 2)
        return false;
    int check_count = sqrt(test);
    for (int i = 2; i <= check_count; i++)
    {
        if (test % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    unordered_set<int> nums;
    sort(numbers.begin(), numbers.end());
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            int temp = stoi(numbers.substr(0, i));
            if (nums.find(temp) == nums.end())
            {
                nums.insert(temp);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (auto &a : nums)
    {
        if (isPrime(a))
            answer++;
    }
    return answer;
}