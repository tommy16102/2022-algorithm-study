/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Sort / 가장큰 수
2021/07/18 이호준
# 아이디어
1. 숫자를 문자로 바꿔 정렬한다.
[9, 5, 34, 30, 3] 순서로 정렬된다.
작은 자리수 부터 정렬한 후 끼워맞추기로 한다.
34 30 3(3) 
=> 34330
===============> 구현 못함
2. 문자열 다루는 문제를 전체적으로 다루지 못해 구글에서 검색해서 풀이를 보았다.
sort함수의 compare을 만들어 정렬하는 방법.
string의 정렬방법에 대해서 배웠다.
결국 큰 수를 만들어야 하는데 이를 string의 크기비교로 적절히 변형해 풀었다.
출처 : https://mungto.tistory.com/22
*******************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//합친 문자 비교해서 큰순으로 정렬하기, ex ) 6, 10 이 있다면 610과 106하고 어떤게 큰지 비교
// 610이 더크므로 6, 10순으로 정렬하게 된다.
bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> temp;
    for (auto &num : numbers)
        temp.push_back(to_string(num));
    sort(temp.begin(), temp.end(), cmp);
    for (auto &a : temp)
        cout << a << "\t";

    // 예외처리 => 0 이 맨앞에 있다는 것은 0*라는 것으로 0이 정답이다.
    if (temp.at(0) == "0")
        return "0";
    // 정렬한대로 합치면 정답..
    for (auto &num : temp)
        answer += num;
    return answer;
}

void print(vector<int> numbers, string answer)
{
    string t = solution(numbers);
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main()
{
    print({6, 10, 2}, "6210");
    print({3, 30, 34, 5, 9}, "9534330");
    print({0, 0, 0, 0, 0, 0, 0}, "0");
    return 0;
}

//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <functional>
//using namespace std;
//
//string solution(vector<int> numbers) {
//	string answer = "";
//	vector<string> sorted;
//	sorted.reserve(numbers.size());
//	for (auto & a : numbers)
//		sorted.push_back(to_string(a));
//	sort(sorted.begin(), sorted.end(), greater<>());
//
//	// 1000 추가
//
//	return answer;
//}
//
//int main(void) {
//	vector<int> a = { 6, 10, 2 };
//	vector<int> b = { 3, 30, 34, 5, 9 };
//
//	// [6, 10, 2]	"6210"
//	// [3, 30, 34, 5, 9]	"9534330"
//	cout << "answer : 6210\t>>  " << solution(a) <<endl;
//	cout << "\nanswer : 9534330\t>>  " << solution(b);
//
//}