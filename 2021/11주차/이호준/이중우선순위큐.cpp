/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 
Heap 이중 우선순위 큐
2021/09/24 이호준
# 아이디어
1. max_Heap과 min_Heap을 모두 이용한다.
I command시 두 힙에 모두 데이터를 삽입한다.
최소값을 뺄겅유 min_Heap에서 최대값을 뺄경우 max_Heap에서 뺀다.
그런데 이때 빼다보면 두 힙의 값이 같거나 역전되는 경우를 처리해주어야한다.
두힙의 값이 같은경우는 둘다 빼준다.
역전되는 경우는 두 힙을 초기화 해준다.
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int> max_heap;
    bool isEmpty = false;
    for (int i = 0; i < operations.size(); i++)
    {
        string command = operations[i].substr(0, 1);
        int number = stoi(operations[i].substr(2));

        if (command == "I")
        {
            max_heap.push(number);
            min_heap.push(number);
        }
        else
        {
            if (number < 0)
            {
                if (min_heap.empty())
                    continue;
                if (min_heap.top() == max_heap.top())
                {
                    max_heap.pop();
                }
                min_heap.pop();
            }
            else
            {
                if (max_heap.empty())
                    continue;
                if (min_heap.top() == max_heap.top())
                {
                    min_heap.pop();
                }
                max_heap.pop();
            }

            if (min_heap.top() > max_heap.top())
            {
                while (!min_heap.empty())
                {
                    min_heap.pop();
                }
                while (!max_heap.empty())
                {
                    max_heap.pop();
                }
            }
        }
    }

    if (max_heap.empty() && min_heap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (max_heap.empty() && !min_heap.empty())
    {
        answer.push_back(min_heap.top());
        answer.push_back(min_heap.top());
    }
    else if (!max_heap.empty() && min_heap.empty())
    {
        answer.push_back(max_heap.top());
        answer.push_back(max_heap.top());
    }
    else
    {
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    }
    return answer;
}