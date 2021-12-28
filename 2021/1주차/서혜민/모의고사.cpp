#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.12 서혜민

answer 배열 - 수포자 3명의 답을 찍는 방식의 패턴을 저장!
count배열 - 수포자 3명의 맞은 정답의 개수를 저장!
for문을 돌려 문제마다 정답과 수포자의 찍은 답을 비교하여
맞을 때마다 count배열 내 수를 더해준다.

이후, count배열 내에서 가장 큰 수를 찾은 뒤, 
해당 수를 맞춘 수포자를 벡터에 넣어주면 끝!.

*/

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