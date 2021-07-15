/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * Heap / 더 맵게
 * 2021 / 07 / 12  이호준
 * 가장 맵지 않은, 그다음으로 맵지않은 음식을 구해 요리를 섞어 새로운 음식을 만들어 모든 음식이 K 보다 맵게한다.
 * 항상 정렬이 필요한대 우선순위 Queue를 통해 빠르게 진행할 수 있다.
 * Priority_queue을 만들어 문제의 스코빌 지수 식을 통해 작업한다.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &a : scoville)
        q.push(a);
    while (q.top() < K)
    {
        if (q.size() == 1)
        {
            answer = -1;
            break;
        }
        int temp = q.top();
        q.pop();
        temp += q.top() * 2;
        q.pop();
        q.push(temp);
        answer++;
    }
    return answer;
}