#include <string>
#include <vector>

using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : 학생들의 체육복 수 벡터를 만든 후 최신화한다.
    이후 그리디하게 앞의 학생에게 빌려본 후 없으면 뒤에 학생에게 빌려본다.

*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> student(n, 1);
    int answer = 0;
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i] - 1]++;
    }

    vector<int> temp = student;

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 0) {
            if (i != 0) {
                if (temp[i - 1] == 2) {
                    temp[i - 1]--;
                    temp[i]++;
                    continue;
                }
            }
            if (i != temp.size()) {
                if (temp[i + 1] == 2) {
                    temp[i + 1]--;
                    temp[i]++;
                    continue;
                }
            }
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] >= 1)
            answer++;
    }
    return answer;
}