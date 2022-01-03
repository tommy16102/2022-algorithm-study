/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
1541 잃어버린 괄호
2021/07/21 이호준
# 아이디어
괄호를 통해 식의 값을 최소로 하기 위해서는 최대한 많이 -로 감싸야한다.
그렇기 때문에 -가 나오는 순간 또다른 -가 나오기 전까지 전부 ()로 감싼다.
-가 나올때 까지 vector에 전부 넣어놓고 vector의 모든원소의 값을 더한후 -를 취한다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 55-50+40
// 55-(50+40)     마이너스 나오는 순간 ()
// 55-50+40-30
int main(void)
{
    string input = "";
    vector<int> stack;
    int answer = 0;
    int current = 0;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            current = current * 10 + input[i] - '0';
        }
        else if (input[i] == '+')
        {
            answer += current;
            current = 0;
        }
        else
        {
            i++;
            answer += current; // 첫번째 operator가 - 라면 그 전 값더해주기 그 외의 경우 current=0이므로 영향 x
            current = 0;
            while (input[i] != '-')
            {
                if (input[i] >= '0' && input[i] <= '9')
                {
                    current = current * 10 + input[i] - '0';
                }
                else if (input[i] == '+')
                {
                    stack.push_back(current);
                    current = 0;
                }
                i++;
                if (i == input.size()) // vector끝까지 탐색 완료 했으므로 더이상 필요 x
                {
                    break;
                }
            }
            stack.push_back(current); // -를 만나기 전 current값 push
            int temp = 0;
            for (auto &a : stack)
            {
                temp += a;
            }
            stack.clear();
            answer -= temp;
            i--;
            current = 0;
        }
    }
    answer += current;
    cout << answer << endl;
    return 0;
}