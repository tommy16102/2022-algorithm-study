/**
 * Algorithm Study
 * Programmers 코딩테스트 고득점 Kit
 * 완전탐색 / 모의고사
 * 2021 / 07 / 12  이호준
 * 패턴을 통해 채점하는 방식이다.
 * check 함수를 통해 pattern마다 2중 for문을 통해 채점하도록 구현하였다.
 * 미팅을 통해 혜민의 풀이가 가장 명확하고 출제의도와 같았다
 * 패턴마다 패턴의 길이를 이용해 % 연산을 통해 하나의 포문으로 모든 문제를 채점할 수 있었다.
 * 해당 지식을 얻게 되었다.
 * 1주차 / 서혜민 / 완탐.cpp 참조
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> pattern, vector<int> answers, int size)
{
    int score = 0;
    if (answers.size() <= size)
    {
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == pattern[i])
                score++;
        }
    }
    else
    {
        for (int i = 0; i <= answers.size() - size; i += size)
        {
            for (int j = 0; j < size; j++)
                if (answers[i + j] == pattern[j])
                    score++;
        }
        int location = (answers.size() / size) * size;
        for (int i = 0; i < answers.size() % size; i++)
        {
            if (answers[location + i] == pattern[i])
                score++;
        }
    }
    return score;
}

vector<int> solution(vector<int> answers)
{
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<vector<int>> patterns({first, second, third});
    vector<int> answer;
    int max = -1;
    for (int i = 0; i < 3; i++)
    {
        int score = check(patterns[i], answers, patterns[i].size());
        if (score > max)
        {
            answer.clear();
            answer.push_back(i + 1);
            max = score;
        }
        else if (score == max)
        {
            answer.push_back(i + 1);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}