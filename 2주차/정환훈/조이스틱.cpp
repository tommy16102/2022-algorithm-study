#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/18
    
    기본 아이디어 : left랑 right 중 짧은 길을 가는 거 계속 선택..
    ....이긴 한데? 

*/

int calc(char ch) {
    return min(ch - 'A', 'Z' - ch + 1);
}

int solution(string name) {

    int up_down = 0;
    int answer = 0;

    vector<int> move_to;

    for (int i = 0; i < name.size(); i++) {
        move_to.push_back(calc(name[i]));
        cout << move_to[i] << endl;
    }

    int id = 0;

    while (true) {
        int sum = 0;
        answer += move_to[id]; // 위아래 움직임
        move_to[id] = 0; // 해당 자리 맞춤

        for (int i = 0; i < move_to.size(); i++) {
            sum += move_to[i];
        }
        if (sum == 0) break; // 탈출 검사


        int left = 0; int right = 0;
        int left_total = left;
        int right_total = right;
        int temp = id;

        while (move_to[temp - left] == 0) {
            if (temp - left == 0) {
                temp = name.size() - 1;
                left = -1;
            }
            left++;
            left_total++;
        }
        temp = temp - left;
        
        int temp2 = id;
        while (move_to[temp2 + right] == 0) {
            if (temp2 + right == name.size() - 1) {
                temp2 = 0;
                right = -1;
            }
            right++;
            right_total++;
        }

        temp2 = temp2 + right;
        if (left_total > right_total) {
            id = temp2;
            answer += right_total;
        }
        else {
            id = temp;
            answer += left_total;
        }

    }

    answer += up_down;
    cout << "answer : " << answer;

    return answer;

}