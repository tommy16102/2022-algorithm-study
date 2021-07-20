#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/16
    
    기본 아이디어 : 몸무게별로 줄 세워서 가장 무거운 애랑 가장 가벼운 애랑 해보고
    탈 수 있으면 둘이 보내고 못타면 무거운 애 내쫓는다
    마지막 경우만 한 대 더 필요한지 체크


*/

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());

    int left = 0; // 제일 무거움
    int right = people.size() - 1; // 제일 가벼움


    while (left < right) {
        if (people[left] + people[right] > limit) {
            left++; // 무거운애 혼자 탈출
        }
        else {
            left++; right--; // 둘이 손잡고 탈출
        }
        answer++;
    }

    if (left == right)
        answer++;

    return answer;
}
