/*******************************************************************
Algorithm Study
Baekjoon OJ DP
1406 에디터
2022/01/18 이호준
# 아이디어
1. 링크드 리스트로 하면 될 줄 알았다. 하지만 linked list의 단점인 중간지점 접근에 시간이 오래걸리므로 올바른 자료구조가 아니였다.

=> 2개의 스택을 이용하여 커서의 위치를 기준으로 스택 왼쪽 오른쪽으로 구현하여 풀이하였다.
링크드 리스트로 했을 경우 주어진 테스트케이스는 모두 통과하지만 시간초과가 발생하였다.
*******************************************************************/
//#include <iostream>
//#include <string>
//#include <list>
//
// using namespace std;
//
// int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	string input;
//
//	getline(cin, input);
//
//	int number;
//
//	cin >> number;
//
//	list<char> results;
//	int cursor = 0;
//
//	for (int i = 0; i < input.size(); i++) {
//		results.push_back(input[i]);
//	}
//	cursor = input.size();
//
//	for (int i = 0; i < number; i++) {
//		char command;
//		cin >> command;
//
//		if (command == 'L') {
//			if (cursor >= 1) {
//				cursor--;
//			}
//		}
//		else if (command == 'D') {
//			if (cursor + 1 <= results.size()) {
//				cursor++;
//			}
//		}
//		else if (command == 'B') {
//			if (cursor != 0) {
//				list<char>::iterator iter = results.begin();
//				for (int j = 0; j < cursor-1; j++) {
//					iter++;
//				}
//				results.erase(iter);
//				cursor--;
//			}
//		}
//		else if (command == 'P') {
//			char x;
//			cin >> x;
//			if (cursor != results.size()) {
//				list<char>::iterator iter = results.begin();
//				for (int j = 0; j < cursor; j++) {
//					iter++;
//				}
//				results.insert(iter, x);
//			}
//			else {
//				results.push_back(x);
//			}
//			cursor++;
//		}
//	}
//
//	for (auto a : results)
//		cout << a;
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    getline(cin, input);

    int number;

    cin >> number;

    int cursor = 0;

    vector<char> left;
    vector<char> right;

    for (int i = 0; i < input.size(); i++)
    {
        left.push_back(input[i]);
    }
    cursor = input.size();

    for (int i = 0; i < number; i++)
    {
        char command;
        cin >> command;

        if (command == 'L')
        {
            if (!left.empty())
            {
                right.push_back(left.back());
                left.pop_back();
            }
        }
        else if (command == 'D')
        {
            if (!right.empty())
            {
                left.push_back(right.back());
                right.pop_back();
            }
        }
        else if (command == 'B')
        {
            if (!left.empty())
            {
                left.pop_back();
            }
        }
        else if (command == 'P')
        {
            char x;
            cin >> x;
            left.push_back(x);
        }
    }

    for (auto a : left)
        cout << a;
    reverse(right.begin(), right.end());
    for (auto a : right)
        cout << a;

    return 0;
}
