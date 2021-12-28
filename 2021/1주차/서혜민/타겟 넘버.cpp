#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.12 서혜민

재귀를 돌릴 calc 함수의
첫번째 매개변수는 계산을 할 벡터의 인덱스
두번째 매개변수는 벡터
세번째 매개변수는 최종 목표 결과값
네번째 매개변수는 계산(+또는 -)했을 때의 결과값

배열의 처음부터 끝까지 배열의 원소들을 더하거나, 빼가는 과정을 재귀로 하면서
해당 목표값에 도달하게 되면 answer를 하나씩 늘려준다.

*/

int answer = 0;
void calc(int index, vector<int> numbers, int target, int result) {
    if (index == numbers.size()) {
        if (result == target) answer++;
    }
    else {
        calc(index + 1, numbers, target, result + numbers[index]);
        calc(index + 1, numbers, target, result - numbers[index]);
    }
}

int solution(vector<int> numbers, int target) {
    int result = answer;
    calc(0, numbers, target,0);
    return answer;
}

int main() {
    vector<int> a = { 1,1,1,1,1 };
    cout<<solution(a, 3);
}