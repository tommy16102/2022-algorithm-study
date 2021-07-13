#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3]{ 0, };
    int answer1[5] = { 1,2,3,4,5 };
    int answer2[8] = { 2,1,2,3,2,4,2,5 };
    int answer3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    for (int i = 0;i < answers.size();i++) {
        if (answers[i] == answer1[i % 5]) count[0]++;
        if (answers[i] == answer2[i % 8]) count[1]++;
        if (answers[i] == answer3[i % 10]) count[2]++;
    }
    int max = 0;
    for (int i = 0;i < 3;i++) {
        if (max < count[i]) max = count[i];
    }
    for (int i = 0;i < 3;i++) {
        if (max == count[i]) answer.push_back(i+1);
    }
    return answer;
}

int main() {
    vector<int> a = { 1,3,2,4,2};
    vector<int> ans = solution(a);
    for (int i = 0;i < ans.size();i++) cout << ans[i] << ' ';
}