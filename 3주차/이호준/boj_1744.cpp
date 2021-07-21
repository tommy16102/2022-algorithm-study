/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
1744 수 묶기
2021/07/21 이호준
# 아이디어
1. 음수 * 음수 == 양수
2. 정렬 후 음수는 작은 순으로 곱하고 양수는 큰순서대로(index마지막부터 내려오면서 곱한다)
3. 이때 0에 유의한다.

※ 숫자를 다룰 때 중요한 지점
음수, 0, 양수, 같을 때
음수 * 0 == 0이라는 케이스를 생각못해서 시간을 많이 소모했다.
1*1 < 1+1이라는 케이스도 중요한 케이스이다. 합이 곱하기 보다 큰 특이케이스이므로 항상 생각해야한다.
*******************************************************************/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    int answer = 0;
    bool zero = false;
    vector<int> numbers;
    cin >> N;
    numbers.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    int minus = 0;
    // -13 -3 -2
    for (auto &a : numbers)
    {
        if (a >= 0)
        {
            if (a == 0)
                zero = true;
            break;
        }
        else
            minus++;
    }
    // 0 1 2 3
    if (minus > 1)
    {
        for (int i = 0; i < minus - 1; i += 2)
        {
            answer += (numbers[i] * numbers[i + 1]);
        }
    }
    // 예외처리 음수 * 0 = 0 최대의 값
    if (minus % 2 != 0 && zero)
    {
        minus++;
    }
    else
    { // 음수 홀수
        if (minus % 2 != 0)
        {
            answer += numbers[minus - 1];
        }
        // zero 존재 시 양수인 부분 까지 이동
        if (zero)
            minus++;
    }
    for (int i = numbers.size() - 1; i - 1 >= minus; i -= 2)
    {
        if (numbers[i - 1] <= 1)
        {
            answer += numbers[i] + numbers[i - 1];
        }
        else
            answer += numbers[i] * numbers[i - 1];
    }
    // 양수 홀수개 처리
    if (numbers.size() > minus && (numbers.size() - minus) % 2 != 0)
    {
        answer += numbers[minus];
    }
    cout << answer;
    return 0;
}

// 양수 뒤에서 부터 곱하기
// 음수 앞에서 부터 곱해가기
// 홀수개 짝수개
// 짝수, 홀수, 0  짝수, 홀수