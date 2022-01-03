/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 
Heap 디스크 컨트롤러
2021/09/24 이호준
# 아이디어
1. 우선순위 큐와 큐를 이용해 디스크 컨트롤러 시스템을 구현한다.
먼저 works를 입력시간순, 입력시간이 같다면 working이 빨리 끝나는 순으로 정렬한다.
priority_queue를 통해 우선순이가 높은(빨리끝나는 작업)순으로 대기열을 만든다.
working queue를 통해 현재 작업중인 queue를 보관한다.
time 변수를 통해 1초씩 진행하면서 디스크가 일을 처리하고 있을 경우 priority_queue에 넣어 대기한다.
만약 디스크가 작업을 끝냈는데 priority_queue에 작업이 없다면 works의 다음일을 working queue에 넣는다.
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
};

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

    vector<pair<int, int>> works(jobs.size(), {0, 0});

    for (int i = 0; i < jobs.size(); i++)
    {
        works[i] = {jobs[i][0], jobs[i][1]};
    }

    sort(works.begin(), works.end(), compare);

    /*for (auto a : works) {
		cout << a.first << " " << a.second << endl;
	}*/

    int index = 1;
    int time = 0;
    int size = jobs.size();
    int out_time = works[0].second + works[0].first;
    queue<pair<int, int>> working;
    answer += works[0].second;
    working.push(works[0]);
    if (index < size && working.front().first == works[index].first)
    {
        while (index < size && working.front().first == works[index].first)
        {
            q.push(works[index++]);
        }
    }
    while (1)
    {
        time++;

        if (index < size && works[index].first == time)
        {
            while (index < size && works[index].first == time)
            {
                q.push(works[index++]);
            }
        }

        if (working.empty())
        {
            if (!q.empty())
            {
                int new_work_insert = q.top().first;
                int working_time = q.top().second;
                int waiting_time = time - new_work_insert;

                int total_time = waiting_time + working_time; // waiting_time + working time;
                answer += total_time;
                working.push(q.top());
                out_time = time + working_time;
                q.pop();
            }
            else
            {
                // 우선순위 queue가 비엇을 경우 works에서 다음 work 하나 빼고 time update;
                if (index < size)
                {
                    int new_work_insert = works[index].first;
                    int working_time = works[index].second;

                    int total_time = working_time; // 기다린 시간 0 + working time;

                    time = new_work_insert;
                    answer += total_time;
                    working.push(works[index++]);
                    out_time = time + working_time;
                    if (index < size && works[index].first == time)
                    {
                        while (index < size && works[index].first == time)
                        {
                            q.push(works[index++]);
                        }
                    }
                }
            }
        }

        if (time == out_time)
        {
            if (!q.empty())
            {
                int new_work_insert = q.top().first;
                int working_time = q.top().second;
                int waiting_time = time - new_work_insert;

                int total_time = waiting_time + working_time; // waiting_time + working time;
                answer += total_time;
                working.push(q.top());
                q.pop();
                working.pop();
                out_time = time + working_time;
            }
            else
            {
                if (index < size)
                {
                    int new_work_insert = works[index].first;
                    int working_time = works[index].second;

                    int total_time = working_time; // 기다린 시간 0 + working time;

                    time = new_work_insert;
                    answer += total_time;
                    working.push(works[index++]);
                    out_time = time + working_time;
                    working.pop();
                    if (index < size && works[index].first == time)
                    {
                        while (index < size && works[index].first == time)
                        {
                            q.push(works[index++]);
                        }
                    }
                }
            }
        }

        if (index == size && q.empty())
        {
            break;
        }
    }

    return answer / size;
}

int main(void)
{

    cout << solution({{24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1}}) << endl; //74
    cout << solution({{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1}}) << endl; //72
    cout << solution({{0, 3}, {4, 5}}) << endl;
    cout << solution({{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}) << endl; //13
    cout << solution({{0, 5}, {1, 4}, {6, 1}, {7, 1}}) << endl;         //5
    cout << solution({{0, 10}, {4, 10}, {15, 2}, {5, 11}}) << endl;     //15
    cout << solution({{0, 3}, {4, 3}, {8, 3}}) << endl;                 //3

    return 0;
}

/*

working이 비면 priority_queue에서 pop()하여 넣는다.

works에 현재 일이 들어있습니다. (시간순서대로)

*/