/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
1764 듣보잡
2021/08/18 이호준
# 아이디어
1. map에 넣고 count 증가로 확인
*******************************************************************/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    map<string, int> maps;
    int answer = 0;
    string name;
    for (int i = 0; i < n; i++)
    {
        getline(cin, name);
        maps.insert({name, 0});
    }

    for (int i = 0; i < m; i++)
    {
        getline(cin, name);
        map<string, int>::iterator a = maps.find(name);
        if (a != maps.end())
        {
            answer++;
            a->second++;
        }
    }

    cout << answer << "\n";

    for (auto a : maps)
        if (a.second != 0)
            cout << a.first << "\n";

    return 0;
}