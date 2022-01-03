/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * Stack/Queue / 기능 개발 (level 2)
 * 2021 / 07 / 12  이호준
 * progresses와 speedes로 들어온 각 작업의 작업진도와 속도 정보를 통해
 * 각 작업마다 배포까지 걸리는 시간을 구해 a vector에 저장한다.
 * 문제 제한조건에서 뒤의 작업이 배포가 가능하더라도 앞의 작업이 배포되지 않으면 앞의 배포가 될때까지 배포가 미뤄진다.
 * 맨앞의 작업의 배포날짜가 배포의 시점을 결정하고 현재 시점에서의 맨 앞 작업의 시간보다 긴 작업을 찾으면 배포 순간이 변경되는 시점이다.
 * 5 1 1 20 에서 20에서 새로운 배포가 시작된다.
 * 이렇게 값이 역전되는 순간을 찾아 그때까지 배포가 되지 않은 작업의 개수를 반환하면 된다.
*/
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> a(progresses.size());
    int size = progresses.size();
    for (int i = 0; i < size; i++)
    {
        a[i] = (int)ceil((100 - progresses[i]) / (double)speeds[i]);
    }
    int current = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[current] < a[i])
        {
            answer.push_back(i - current);
            current = i;
        }
        // 배포가 되는 current가 마지막 작업이라면, 1개를 반환
        // (예외처리 (i-current ==0인데 해당 작업이 배포되므로) 역전되는 다음 작업을 찾는 방식을 통해 연산을 진행했기 때문)
        // 역전이 되지 않더라도 마지막 작업까지 무조건 배포되므로 current <= x <=i의 개수를 구한다.
        if (i == size - 1)
            i == current ? answer.push_back(1) : answer.push_back(i - current + 1);
    }
    return answer;
}