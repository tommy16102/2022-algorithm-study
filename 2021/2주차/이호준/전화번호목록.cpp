/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Hash / 전화번호 목록
2021/07/15 이호준
# 의도
전화번호 정보가 들어있는 phone_book을 번호순으로 오름차순으로 정렬시
next index만을 확인하여 접두사를 포함하였는지 알 수 있다.
Why ? string 정렬시 119 1195522421 이순으로 정렬되는데
i를 접두사로 가지면 사전순으로 뒤에나올 수 밖에 없는 구조 (사전)

왜 Hash 문제인지 잘모르겠다...
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (vector<string>::iterator i = phone_book.begin(); i != phone_book.end(); i++)
    {
        if ((i + 1) != phone_book.end() && (*(i + 1)).find(*i) == 0)
        {
            answer = false;
            break;
        }
    }
    return answer;
}

int main(void)
{
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    vector<string> phone_book2 = {"123", "456", "789"};
    vector<string> phone_book3 = {"12", "123", "1235", "567", "88"};

    cout << solution(phone_book) << endl;
    cout << solution(phone_book2) << endl;
    cout << solution(phone_book3) << endl;
}