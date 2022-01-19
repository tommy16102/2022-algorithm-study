/*******************************************************************
Algorithm Study
Baekjoon OJ DP
10799 쇠 막대기
2022/01/16 이호준
# 아이디어
1. 문제를 분석하여 구현하는 문제였다.
()가 들어오면 레이저를 발사하여 막대기를 자른다.
input으로 (와)가 들어올 수 있다.
간단하게 (가 들어오면 지속적으로 입력을 받다가 )가 들어오면 처리해준다.
()가 쌍으로 발생한다면 레이저를 쏴 현재 까지 쌓인 막대기의 개수를 더해줌으로써 자르는 것을 구한다.
))가 된다면 레이저가 발생한 것이아니라 막대기의 끝에 도달한 것으로 +1처리해준다.(최상단 막대의 남은 부분)
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;

    string input;

    getline(cin, input);

    vector<char> stack;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            stack.push_back('(');
        }
        else
        {
            if (input[i - 1] == ')')
            {
                answer += 1;
            }
            else if (stack.back() == '(')
            {
                answer += stack.size() - 1;
            }
            stack.pop_back();
        }
    }

    cout << answer;

    return 0;
}