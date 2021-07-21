/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
12904 A와B
2021/07/21 이호준
# 아이디어
1. DFS => 시간초과
2. S->T 너무 많은 경우의 수
   T->S로 이동해보자...

※ 다양한 관점에서 문제를 바라봐야겠다. DFS는 생각보다 시간이 많이 걸린다는 것을 유의하자.
string.back(), string.pop_back(),string.find()
reverse() // <algorithm>
에 대해서 공부하게 되었다.
*******************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//void dfs(string target, string current, bool& result) {
//	if (result)
//		return;
//	if (target.size() == current.size()) {
//		if (target == current) {
//			result = true;
//		}
//	}
//	else {
//		dfs(target, current + "A",result);
//		reverse(current.begin(), current.end());
//		dfs(target, current + "B", result);
//	}
//}
//
//int main(void) {
//	string S, T;
//	cin >> S;
//	cin >> T;
//	bool result = false;
//	dfs(T, S, result);
//	cout << ((result == true) ? "1" : "0" )<< endl;
//	return 0;
//}
int main(void)
{
    string S, T;
    cin >> S;
    cin >> T;
    int result = 0;
    while (1)
    {
        if (T.size() == S.size())
        {
            if (T == S)
            {
                result = 1;
            }
            break;
        }
        char temp = T.back();
        T.pop_back();
        if (temp == 'B')
            reverse(T.begin(), T.end());
    }
    cout << result << endl;
}
// BAA
// AABB
// BBAABA
/*
AAA
AB
BA
AAAAAAAB
BAAAAAAAB

B
ABAAA

B
BA
ABB


*/