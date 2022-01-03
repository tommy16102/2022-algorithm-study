#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.19 서혜민

bigger는 예를 들어 3과 30이 있을 때 이 두로 330과 303을 만들 수 있는 데, 이 두 수 중에서 
더 큰 값을 가지는 수를 만들 수 있도록 정렬이 되도록 sort함수의 세번째 인자로 들어간다.
그래서 이를 통해 numbers 벡터는 앞에서부터 가장 큰 수를 만들 수 있도록 정렬이 된다.

결국, numbers에서 앞에서부터 하나씩 추출을 해서 string으로 변환을 하면서
숫자를 의미하는 문자열이 정답이 된다.

이때 0이 여러개 있을 시, 해당 문자열은 단순 0으로 변환을 해준다.

*/
bool bigger(int a, int b) {
    int num1 = stoi(to_string(a) + to_string(b));
    int num2 = stoi(to_string(b) + to_string(a));
    return num1 > num2;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), bigger);
    string answer = "";
    for (auto i : numbers) {
        answer += to_string(i);
    }
    if (answer[0] == '0') answer = '0';
    return answer;
}

int main() {
    string answer = solution({ 0,0,0 });
    cout << endl << answer << endl;
}