/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
1655 가운데를 말해요
2021/08/18 이호준
# 아이디어
1. 0.1초의 제한시간안에 문제를 풀어야했다.
중간값이 되는 조건을 잘 생각하여 max heap, min heap을 이용해 풀이하는 문제였다.
자료구조의 특징을 이용해 풀어야했다.
자료구조를 잘 이해하고 문제상황에 적용해야했다.
*******************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    vector<int> q;

    cin >> n;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

    int x;
    cin >> x;
    max_heap.push(x);
    cout << max_heap.top() << "\n";
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (max_heap.top() < x)
        {
            min_heap.push(x);
            if (min_heap.size() - max_heap.size() >= 1)
            {
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
        }
        else
        {
            max_heap.push(x);
            if (max_heap.size() - min_heap.size() > 1)
            {
                while (max_heap.size() > min_heap.size())
                {
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                }
            }
        }

        cout << max_heap.top() << "\n";
    }

    return 0;
}

/*

한쪽에 치중하지 않도록

*/