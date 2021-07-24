/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
10610 30
2021/07/24 이호준
# 아이디어
1. next_permutation을 사용한다.
2. 결국 30의 배수.. 0이 있고 3의 배수 판정법을 사용하자..
최대값이니까 30의 배수라면 내림차순으로 정렬한 것이 답이네

※ 문제가 N = 10^5개라고 했다. int로는 안되는 수이다.
*******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string input;
    unsigned long long sum = 0;
    getline(cin, input);
    if (input.find("0") == string::npos)
    {
        cout << -1;
        return 0;
    }
    sort(input.begin(), input.end(), greater<>());
    for (auto &a : input)
    {
        sum += a;
    }
    if (sum % 3 == 0)
        cout << input;
    else
        cout << -1;
    return 0;
}

/*
0이 없으면 x
100000
68930
98630
*/

// 런타임 에러 (out_of_range)
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//	string input;
//	getline(cin, input);
//	if (input.find("0") == string::npos) {
//		cout << -1;
//		return 0;
//	}
//	sort(input.begin(), input.end(), greater<>());
//	do {
//		if (stoll(input) % 30 == 0) {
//			cout << input;
//			return 0;
//		}
//	} while (prev_permutation(input.begin(), input.end() - 1));
//	cout << -1;
//	return 0;
//}