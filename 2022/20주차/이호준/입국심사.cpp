/*******************************************************************
Algorithm Study
고득점 Kit
2022/09/22 이호준
# 아이디어
1. 이분탐색 아이디어
2. 최소 최대를 통한 이분탐색
3. 값의 범위를 보고 -> 선형으로 풀어야한다는 것을 알아야한다.
*******************************************************************/
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times.back();

    while (min <= max) {

        long long avg = (max + min) / 2;
        long long tmp = 0;

        for (int i = 0; i < times.size(); i++) {
            tmp += (avg / (long long) times[i]);
        }

        if (tmp >= n) {
            max = avg - 1;
            answer = avg;
        }
        else min = avg + 1;
    }
    return answer;
}