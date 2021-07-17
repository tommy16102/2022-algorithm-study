/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Greedy / 큰 수 만들기
2021/07/17 이호준
# 아이디어
기본아이디어 : 내 뒤 보다 작으면 없앤다..
그러기 전에 맨 앞자리를 정해야한다.
첫 번째 자리는 커야한다.
먼저 k 번째 자리가 처음부터 탐색하여 k자리까지 숫자중 max값인지 확인하고
max라면 처음 k를 빼면 max입니다. ( 첫자리의 중요성)
그렇지 않다면 앞자리가 뒷자리보다 작다면 빼버립니다.
그런데 만약 뒤까지 해당작업을 다 찾았는데
오름차순으로 정렬되고 삭제된 수(remove)가 k보다 적다는 것은
뒤에 값들이 다 같은 값들이 있다는 것으로
오름차순이기 때문에 뒤에서 부터 총 삭제수가 k가 되도록 뻅니다.

# 같다는 케이스를 빼먹어 무한루프에 빠졌다.
※ 같을때, 범위의 맨 앞, 맨 뒤과 같은 곳은 항상 체크해야한다.
*******************************************************************/
#include <string>
#include <vector>
#include <iostream>
// 내 뒤보다 작으면 죽여..
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int remove = 0;
    int max = 0;
    for (int i = 1; i <= k; i++)
    {
        if (number[i] > number[max])
        {
            max = i;
        }
    }
    if (max == k)
    {
        answer = number.substr(k);
    }
    else
    {
        int current = 0;
        while (remove != k)
        {
            for (int i = current; i < number.size() - 1; i++)
            {
                if (number[i] < number[i + 1])
                {
                    number.erase(i, 1);
                    remove++;
                    if (i == 0)
                        current = 0;
                    else
                        current = i - 1;
                    break;
                }
                if (i == number.size() - 2)
                {
                    for (int j = remove; j < k; j++)
                    {
                        number.erase(number.end() - 1);
                        remove++;
                    }
                }
            }
        }
        answer = number;
    }
    return answer;
}

int main(void)
{
    //  "1924"	2	"94"
    //	"1231234"	3	"3234"
    //	"4177252841"	4	"775841"
    //  "11111" 2 "111"
    cout << "정답 : 94 : \t" << solution("1924", 2) << endl;
    cout << "정답 : 3234 : \t" << solution("1231234", 3) << endl;
    cout << "정답 : 775841 : \t" << solution("4177252841", 4) << endl;
    cout << "정답 : 111 : \t" << solution("11111", 2) << endl;
}