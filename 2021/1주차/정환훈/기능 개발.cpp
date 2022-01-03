#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : 기능 개발이 완료되는 남은 날수 days[]를 구한다
    벡터를 큐라고 생각하여, [0]의 숫자만큼 모든 항에서 빼고
    0 이하인 항목들을 만나면 pop하고, 그 숫자를 센다.
    이를 days가 빌때까지 반복
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> days(progresses.size(), 0);

    for (int i = 0; i < progresses.size(); i++) {
        int res = 100 - progresses[i];
        while (true) {
            days[i]++;
            if (res <= speeds[i] * days[i]) {
                break;
            }
        }
    }
    //  5일, 10일, 1일, 1일, 20일, 1일
    // [0]의 숫자만큼 모든 항에서 빼고
    // 0 5 -4 -4 15 -4
    // 0 이하인 것들은 다 pop
    // 5 -4 -4 15 -4 : 1개 pop
    // 0 -9 -9 10 -9 : 3개 pop
    // 10 -9
    // 0 -19
    vector<int> answer;

    while (!days.empty()) {

        
        int temp = days[0];
        for (int i = 0; i < days.size(); i++) {
            days[i] -= temp;
        }
        int num = 0;

        if (days[0] <= 0) {
            reverse(begin(days), end(days));

            for (int i = 0; i < days.size(); i++) {
                //cout << i << "에서 days[i] : " << days[i] << endl;
            }

            while (days[days.size() - 1] <= 0 && !days.empty()) {
                //cout << "P O P : " << days[days.size() - 1] << endl;;
                days.pop_back();
                num++;

            }
            if (!days.empty())
                reverse(begin(days), end(days));
        }
        //cout << "Num : " << num << endl;
        answer.push_back(num);

    }


    //for (int i = 0; i < answer.size(); i++) {
    //    cout << answer[i] << endl;
    //}

    return answer;
}