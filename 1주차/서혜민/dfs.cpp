#include <string>
#include <vector>
#include <iostream>
using namespace std;

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