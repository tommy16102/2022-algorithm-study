/*******************************************************************
Algorithm Study
Baekjoon OJ DP
2096 내려가기
2021/10/06 이호준
# 아이디어
1. DP 이용
※ 4MB문제로
10^6개의 최대 개수를 가지고 있으므로 모든 값을 가지고 dp를 진행하면 메모리 초과가 발생하는 문제이다.
입력에서 한줄 씩 받아 dp를 진행하면 문제없다.
문제의 3가지 경우수에 대해서 max와 min을 구하도록 구현하면 끝난다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> max_answer(3);
    vector<int> min_answer;
    vector<int> line(n, 0);

    cin >> max_answer[0] >> max_answer[1] >> max_answer[2];
    min_answer = max_answer;

    for (int i = 1; i < n; i++)
    {

        cin >> line[0] >> line[1] >> line[2];

        int temp = max_answer[0];
        int temp2 = max_answer[1];

        max_answer[0] = max(temp, temp2) + line[0];
        max_answer[1] = max(max(temp, temp2), max_answer[2]) + line[1];
        max_answer[2] = max(max_answer[2], temp2) + line[2];

        temp = min_answer[0];
        temp2 = min_answer[1];
        min_answer[0] = min(temp, temp2) + line[0];
        min_answer[1] = min(min(temp, temp2), min_answer[2]) + line[1];
        min_answer[2] = min(min_answer[2], temp2) + line[2];
    }

    cout << *max_element(max_answer.begin(), max_answer.end()) << " " << *min_element(min_answer.begin(), min_answer.end());

    return 0;
}