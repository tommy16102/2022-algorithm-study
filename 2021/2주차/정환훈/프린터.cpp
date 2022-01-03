#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/17
    
    기본 아이디어 : ...?

*/

int solution(vector<int> priorities, int location) {
    int answer = 0;


    deque<int> document_number;
    vector<int> prior_list = priorities;
    vector<int> document_priority;


    sort(prior_list.begin(), prior_list.end());
    prior_list.erase(unique(prior_list.begin(), prior_list.end()), prior_list.end());
    // 중요도에서 중복 제거 이제 1, 2, 3, 4, 5 이런 식으로 나옴
    

    vector<int> prior_nums;

    for (int i = 0; i <= prior_list.back(); i++) {
        int k = 0;
        for (int j = 0; j < priorities.size(); j++) {
            if (i == priorities[j]) {
                k++;
            }
            if (j == priorities.size() - 1 && k != 0) {
                prior_nums.push_back(k);
            }
        }
    }

    reverse(prior_nums.begin(), prior_nums.end());

    for (int i = 0; i < priorities.size(); i++) {
        document_priority.push_back(priorities[i]);
    }

    int k = 0;
    int id = 0;

    int i; 
    while (!prior_list.empty()) {
        int flag = 1;
        int max = prior_list.back();
        for (i = id; i < document_priority.size(); i++) {

            if (max == document_priority[i] && prior_nums[k] > 0) {
                document_priority[i] = -1;
                answer++;
                prior_nums[k]--;
                if (location == i) {
                    return answer;
                }

                if (prior_nums[k] == 0) {
                    k++;
                    //cout << "prior list " << prior_list.back() << "을 펑 " << endl;
                    prior_list.pop_back();
                    id = i;
                    flag = 0;
                    break;
                }
            }

            else {
                //cout << "지나갔지롱";
            }

        }
        if (flag == 1)
            id = 0;
    }

    return answer;
}