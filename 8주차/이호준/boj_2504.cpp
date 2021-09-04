/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
2504 괄호의 값
2021/09/01 이호준
# 아이디어
1. 분배법칙을 이용한 풀이 방법
(이나 [이 들어올 경우 스택에 넣고 해당 값을 곱해놓은 level변수를 이용한다.
stack에 문자와, level정보를 넣는다.
( 일경우 { (, 2} 저장
) ]을 만날경우 이제 그 괄호에 대한 연산은 끝나는 시점이다.
(와 [의 연산에서 계속 해당값을 곱하면서 중첩했기 때문에
(나 [ 이후에 첫번째로 동일한 괄호의 닫힌 모양을 만날경우에만 answer에 값을 더해준다.

이외의 닫힌 모양을 만났으 경우 level만 줄이고 무시 연산한다.

이 역할을 하기 위해 하나의 bool here변수를 이용한다.

즉 (()[]) 일 경우 ) ] 각각 1번씩에 대해서만 연산을 진행하도록 구현하는 것이다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    cin >> input;

    vector<pair<char, int>> stack;
    int answer = 0;
    int level = 1;
    bool here = false;

    for (int i = 0; i < input.size(); i++)
    {
        char current = input[i];
        if (stack.empty())
        {
            if (current == '(')
            {
                level = 2;
                here = true;
            }
            else if (current == '[')
            {
                level = 3;
                here = true;
            }
            else
            { // 올바르지 못한 괄호열
                cout << 0;
                return 0;
            }
            stack.push_back({current, level});
            continue;
        }

        if (current == '(' || current == '[')
        {
            if (current == '(')
            {
                level *= 2;
            }
            else
            {
                level *= 3;
            }
            stack.push_back({current, level});
            here = true;
        }
        else
        {
            // stack
            char top = stack.back().first;
            int distri = stack.back().second;
            if (!here)
            {
                if (current == ')' && top == '(')
                {
                    level /= 2;
                }
                else if (current == ']' && top == '[')
                {
                    level /= 3;
                }
                else
                { // 올바르지 못한 괄호열
                    cout << 0;
                    return 0;
                }
                stack.pop_back();
            }
            else
            {
                if (current == ')' && top == '(')
                {
                    level /= 2;
                    answer += (distri);
                }
                else if (current == ']' && top == '[')
                {
                    level /= 3;
                    answer += (distri);
                }
                else
                { // 올바르지 못한 괄호열
                    cout << 0;
                    return 0;
                }
                stack.pop_back();
                here = false; // 첫번째로 만났을 경우 이제 해당 괄호에대한 연산을 안하기 위해
            }
        }
    }
    if (stack.empty())
    {
        cout << answer;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
