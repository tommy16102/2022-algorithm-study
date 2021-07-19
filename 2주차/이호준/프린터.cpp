/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Stack/Queue / 프린터
2021/07/19 이호준
# 아이디어
1. location으로 받은 내가 프린트 해야하는 문서보다 높은 우선순위를 가진 문서들을
priority_queue q에 넣는다.
q의 top보다 작으면 wait_list의 뒤로보내고
top값과 같으면 해당 문서를 출력한다.
이때 current로 나의 문서위치를 기억한다.
priority_queue 문서들을 다 출력했으면
나의 현재 index인 current보다 앞에 나와 같은 우선순위를 가진 문서의 개수를 찾는다.
priority_queue에서 뺀 문서들과 나보다 앞에 있는 같은 우선순위 문서의 개수 + 1은 내 문서가 빠지는 순간이다.
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int current = location;
    int answer = 0;
    int my_document = priorities[location];
    priority_queue<int, vector<int>> q;
    queue<int> wait_list;
    for (auto &a : priorities)
    {
        if (a > my_document)
            q.push(a);
        wait_list.push(a);
    }
    while (!q.empty())
    {
        if (wait_list.front() < q.top())
        {
            int temp = wait_list.front();
            wait_list.pop();
            wait_list.push(temp);
            if (current == 0)
                current = wait_list.size() - 1;
            else
                current--;
        }
        else if (wait_list.front() == q.top())
        {
            wait_list.pop();
            q.pop();
            answer++;
            current--;
        }
    }
    int count = 0;
    if (q.empty())
    {
        for (int i = 0; i < current; i++)
        {
            int temp = wait_list.front();
            if (temp == my_document)
                count++;
            wait_list.pop();
        }
    }
    answer += (count + 1);
    return answer;
}

int main(void)
{
    //[2, 1, 3, 2]	2	1
    //[1, 1, 9, 1, 1, 1]	0	5
    cout << ((solution({2, 1, 3, 2}, 2) == 1) ? "정답" : "실패") << endl;
    cout << ((solution({1, 1, 9, 1, 1, 1}, 0) == 5) ? "정답" : "실패") << endl;
    cout << ((solution({1, 2, 3, 3}, 1) == 3) ? "정답" : "실패") << endl;
}