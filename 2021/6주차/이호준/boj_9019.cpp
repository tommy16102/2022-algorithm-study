/*******************************************************************
Algorithm Study
Baekjoon 6주차
9019 DSLR
2021/08/13 이호준
# 아이디어
1. 문제 이해가 어려웠다.
처음에 문제 이해를 못해 14 -> 41(L) 이런식인줄 알았지만 그런게 아니였다.
생각해보면 레지스터이기 때문에 앞에 0이있다고 생각하는게 맞았다...
그리고 내 생각대로 이게 최선일꺼라고 단정할 수 없다는 것을 배웠다.
내가 생각하지 못하는 케이스들이 매우 많이 존재하고 문제에서 나타내는 알고리즘 그대로를 표현해야겠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp, find;
        cin >> temp >> find;
        bool used[10001] = {
            false,
        };

        queue<pair<int, string>> q;

        q.push(make_pair(temp, ""));
        used[temp] = true;

        while (!q.empty())
        {
            int current = q.front().first;
            string make = q.front().second;
            q.pop();

            if (current == find)
            {
                cout << make << endl;
                break;
            }

            int test = current * 2 % 10000;
            if (!used[test])
            {
                used[test] = true;
                q.push(make_pair(test, make + "D"));
            }

            test = current == 0 ? 9999 : current - 1;
            if (!used[test])
            {
                used[test] = true;
                q.push(make_pair(test, make + "S"));
            }

            test = (current % 1000) * 10 + current / 1000;
            if (!used[test])
            {
                used[test] = true;
                q.push(make_pair(test, make + "L"));
            }

            test = current / 10 + (current % 10) * 1000;
            if (!used[test])
            {
                used[test] = true;
                q.push(make_pair(test, make + "R"));
            }
        }
    }

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int current, find;
//		cin >> current >> find;
//
//		queue<pair<int,string>> q;
//		string answer;
//		q.push(make_pair(current, ""));
//		while (!q.empty()) {
//			int temp;
//			temp = q.front().first;
//			answer = q.front().second;
//			if (temp == find) {
//				cout << answer << "\n";
//				break;
//			}
//			q.pop();
//			int d1 = 0, d4 = 0, size=0;
//			if (temp > find) {
//				if(current == 0) q.push(make_pair(9999, answer + "S"));
//				else q.push(make_pair(temp -1, answer + "S"));
//			}
//			if (temp < find) {
//				q.push(make_pair((2 * temp % 10000), answer + "D"));
//			}
//			d4 = temp % 10;
//			int temp2 = temp;
//			while (temp2 != 0) {
//				d1 = temp2 % 10;
//				temp2 /= 10;
//				size++;
//			}
//			q.push(make_pair((temp - d1 * pow(10, size-1)) * 10 + d1, answer + "L"));
//			q.push(make_pair(temp / 10 + d4 * pow(10, size-1), answer + "R"));
//		}
//	}
//
//	return 0;
//}