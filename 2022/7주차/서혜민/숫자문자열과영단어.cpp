#include <string>
#include <vector>
#include <regex>
using namespace std;

/*

2.23

regex_replace(대상 문자열, 정규식, 바꿀 문자열)을 통해서
대상 문자열 내의 정규식과 일치하는 문자열을 모두 세번째 인자 문자열로 바꿔준다.

/*

string numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    for(int i=0;i<10;i++) s = regex_replace(s, regex(numbers[i]), to_string(i));
    return stoi(s);
}