/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Greedy / 구명보트
2021/07/18 이호준
# 아이디어
최대 2명을 테울수 있는 구명보트에서 limit무게를 초과하면 안된다.
작은 값들은 2명씩 테울 수 있지만
어떻게하면 무거운 사람을 최대한 2명씩 테우도록 하는것이 문제다.
몸무게를 오름차순으로 정렬한 후
무거운사람, 제일 가벼운 사람이 세트가 되도록 하였다.
이때 무거운 사람이 우선순위고 가벼운 사람의 가능한 최대 무게보다
무겁다면 무거운 사람을 혼자 태워 보낸다.

# 효율성의 문제
효율성 테스트 케이스 1, 3에서 실패가 나왔었다.
원래 solution2함수처럼 작성했었는데 알고리즘은 개선할 부분을 못찾겠어서
삭제하는 비용이 클 수 있다는 생각에 삭제를 하지않고 index로 계산하는 방법으로 수행했다.
삭제의 비용이 생가보다 크다는 것을 알게 되었다.
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// sort 후 뒤 앞
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    int front = 0;
    int back = people.size() - 1;
    for (int i = 0; i < people.size(); i++)
    {
        if (back < front)
            break;
        if (front == back)
        {
            answer++;
            break;
        }
        int max = limit - people[back];
        if (people[front] > max)
        {
            back--;
            answer++;
        }
        else
        {
            front++;
            back--;
            answer++;
        }
    }
    return answer;
}

int main(void)
{
    // [70, 50, 80, 50]	100	3
    //	[70, 80, 50]	100	3
    vector<int> a = {70, 50, 80, 50};
    vector<int> b = {70, 80, 50};
    cout << "정답 : 3 \t>>" << solution(a, 100) << endl;
    cout << "정답 : 3 \t>>" << solution(b, 100);
}

/*
solution 2 
1과 동일한 알고리즘 
그러나 people vector에서 삭제를 하면서 진행했다.
해당 풀이는 모두 정답을 찾지만
효율성에서 테스트 1, 3에서 시간초과가 났다.
삭제의 비용이 크다는 것을 알게 되었다.
*/

//int solution2(vector<int> people, int limit) {
//	int answer = 0;
//	sort(people.begin(), people.end());
//	while (!people.empty()) {
//		int max = limit - people.back();
//		if (people.size() == 1) {
//			answer++;
//			break;
//		}
//		if (people[0] > max) {
//			people.pop_back();
//			answer++;
//		}
//		else {
//			people.erase(people.begin());
//			people.pop_back();
//			answer++;
//		}
//
//	}
//	return answer;
//}