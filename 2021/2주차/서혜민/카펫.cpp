#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/*

2021.07.19 서혜민

갈색과 노란색으로 칠해진 격자의 수의 합은 카펫의 넓이이다.
세로를 2부터해서 카펫의 넓이의 제곱근까지
넓이를 세로로 나눴을 때 똑바로 나눠지는 값을 가로로하여
노란색 격자의 수는 (세로-2)*(가로-2)이므로 이 값이 주어진 노락색 격자의 수와 같다면

해당 가로와 세로를 벡터에 푸쉬해준다.

*/

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<int> answer;
    int garo, sero;
    for (sero = 2;sero <= sqrt(sum);sero++) {
        if ((sum % sero)==0) {
            garo = sum / sero;
            int yellowCount = (sero - 2) * (garo - 2);
            if (yellow == yellowCount) {
                answer.push_back(garo);
                answer.push_back(sero);
                return answer;
            }
        }
    }
}

int main() {
    solution(24,24);
}