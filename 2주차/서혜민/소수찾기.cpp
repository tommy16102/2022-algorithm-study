#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

/*

2021.07.19 서혜민

먼저, 에라토스테네스의 체로 문제 내에서 만들 수 있는 가장 큰 수까지 소수를 구한다.
0과 1은 소수가 아니므로 1로 초기화한 뒤, for문을 통해서 2부터 9999999의 제곱근까지
이 수들의 제곱에서 부터 이 수들이 더해지는 수는 소수가 아니게 된다.

다음으로, 입력받은 numbers문자열을 내림차순으로 정렬을 한다. 
정렬을 해서 나온 수는, numbers문자열로 만들 수 있는 가장 큰 수이다.

다음으로, 이 numbers문자열에 존재하는 숫자의 개수를 알기 위해
길이 10인 countOrg배열의 인덱스가 numbers문자열 내의 숫자로서 
for문을 통해 개수를 배열에 저장을 해준다.

이제 가장 작은 소수인 2부터 가장 큰 수까지 for문을 통해서
이 수가 소수이면서, 문자열에 존재하는 수로 만들 수 있는 수인지 만들어준 countOrg배열을 통해서 확인을 하면 된다.

*/
bool num[10000000];
int solution(string numbers) {
    //에라토스테네스의 체, 0이면 소수.
    num[0] = 1; num[1] = 1; //0하고 1은 소수x.
    for (int i = 2;i <= sqrt(9999999);i++) {
        if (num[i] == 1) continue; 
        for (int j = i * i;j <= 9999999;j += i) {
            num[j] = 1;
        }
    }
  
    sort(numbers.begin(), numbers.end(), greater<>());
    int maxNum;//만들 수 있는 가장 큰 수.
    int countOrg[10] = { 0, };//0~9 개수 저장
    for (int i = 0;i < numbers.length();i++) {
        countOrg[numbers[i]-'0']++;
    }
    if (numbers[0] == '0') return 0;
    else {
        maxNum = stoi(numbers);
    }

    int answer = 0;
    int count[10];
    bool succ = true;
    int countNum = 0;
    for (int i = 2;i <= maxNum;i++) {
        succ = true;
        countNum = 0;
        copy(countOrg, countOrg + 10, count);
        string number = to_string(i);
        if (num[i]) continue;//num[i]가 1이면 이 수는 소수가 x.
        else {      
            for (int j = 0;j < number.length();j++) {
                cout << endl;
                if (count[number[j]-'0'] == 0) {
                    succ = false;
                    break;
                }
                else {
                    count[number[j]-'0']--;
                    countNum++;
                }
            }
            if (succ==true && countNum==number.length()) {
                answer++;
            }
        }   
    }
    return answer;
}

int main() {
    cout << solution("011");
}