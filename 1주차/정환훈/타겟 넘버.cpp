#include <string>
#include <vector>

using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : 주어진 전체 합을 구한다.
    전체 합 - 부분집합 * 2 = 타겟 넘버
    인 부분집합을 구한다.
    부분집합을 구하는 방법은 dfs로 구현,
    자신을 더하고 넘기거나 더하지 않고 넘기거나 두 갈래의 재귀로 구현.

*/

void sum(vector<int> numbers, vector<int>& sums, int index, int temp) {

    if (numbers.size() <= index) {
        sums.push_back(temp);
        return;
    }

    sum(numbers, sums, index + 1, temp + numbers[index]);
    sum(numbers, sums, index + 1, temp);

}


int solution(vector<int> numbers, int target) {

    int answer = 0;
    int every_sum = 0;



    for (int i = 0; i < numbers.size(); i++) {
        every_sum += numbers[i];
    }

    vector<int> sums;


    sum(numbers, sums, 0, 0);

    for (int i = 0; i < sums.size(); i++) {
        if (every_sum - sums[i] * 2 == target) {
            answer++;
        }
    }
    return answer;
}