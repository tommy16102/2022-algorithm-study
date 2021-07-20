#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/14
    
    기본 아이디어 : (각 옷의 종류) + 1을 전부 곱한다
    이를 위해서 각 옷의 종류->숫자를 매핑시킨 map과
    각 옷의 종류를 곱했는지 판단하는 bool flag가 있음
    map에서 옷 종류 개수를 센 후 flag로 체크하면서 
    answer = 1에서 각 옷의 종류 + 1 을 곱함

*/

int solution(vector<vector<string>> clothes) {

    int answer = 0;
    unordered_map<string, int> map;
    unordered_map<string, bool> flag;
    for (int i = 0; i < clothes.size(); i++) {
        map.insert(make_pair(clothes[i][1], 0));
        flag.insert(make_pair(clothes[i][1], false));
    }
    for (int i = 0; i < clothes.size(); i++) {
        map[clothes[i][1]]++;
    }

    answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        if (flag[clothes[i][1]] == false) {
            answer *= map[clothes[i][1]] + 1;
            flag[clothes[i][1]] = true;
        }
    }

    answer--;
    return answer;
}