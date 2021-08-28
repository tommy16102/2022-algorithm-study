/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
7758 회사에 있는 사람
2021/08/18 이호준
# 아이디어
1. set에 넣고 중복시 erase
2. map에 넣고 삭제대신 값 ++;
=> 처음에 0인것으로 했는데
틀렸다. ?? -> 혹시 다시 들어갈 수도 있다고 생각해서 %2 == 0 으로 했더니 정답!

map과 set에 compare함수를 적용하는 법을 배웠다.
greater<string> 사전식 역순이 맞았다.
*******************************************************************/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    cin.ignore();

    map<string, int, greater<string>> s;
    string name;
    for (int i = 0; i < n; i++)
    {
        getline(cin, name);
        name = name.substr(0, name.find(" "));
        map<string, int>::iterator a;
        a = s.find(name);
        if (a == s.end())
        {
            s.insert({name, 0});
        }
        else
        {
            a->second++;
        }
    }
    for (auto a : s)
        if (a.second % 2 == 0)
            cout << a.first << "\n";

    return 0;
}

//#include<iostream>
//#include <string>
//#include <set>
//
//using namespace std;
//
//
//int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	int n;
//
//	cin >> n;
//	cin.ignore();
//
//	set<string, greater<string>> s;
//	string name;
//	for (int i = 0; i < n; i++) {
//		getline(cin, name);
//		name = name.substr(0, name.find(" "));
//		if (s.find(name) == s.end()) {
//			s.insert(name);
//		}
//		else {
//			s.erase(name);
//		}
//	}
//	for (auto a : s)
//		cout << a << "\n";
//	return 0;
//}