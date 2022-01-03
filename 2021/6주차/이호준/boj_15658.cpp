/*******************************************************************
Algorithm Study
Baekjoon 6주차
15658 연산자 끼워넣기(2)
2021/08/12 이호준
# 아이디어
1. dfs로 모든 경우를 탐색하는데 
사용되었을 때와 사용안되었을 때로 나눠서 탐색하고
합이 생성되었는지 확인하는 bool 배열을 만든다. 
>> 이 방식은 operation이 value수보다 훨씬 4n까지 많을 수 있는 이 문제에서 중복되는 체킹하는 횟수가 많아 시간초과를 유발했다.

2. 연산자별로 개수만 알면된다.
for문으로 중복 체크할 필요없이 연산자의 개수를 저장해 남아 있다면 dfs를 수행하면된다.
이 방식이 더 완벽하다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, int made, vector<int> &values);

int max_value = -1000000000;
int min_value = 1000000000;

int a, b, c, d;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> values(n, 0);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    cin >> a >> b >> c >> d;
    dfs(1, values[0], values);

    cout << max_value << endl;
    cout << min_value << endl;

    return 0;
}

void dfs(int current, int made, vector<int> &values)
{
    if (current == values.size())
    {
        if (made > max_value)
            max_value = made;
        if (made < min_value)
            min_value = made;
        return;
    }
    if (a > 0)
    {
        a--;
        dfs(current + 1, made + values[current], values);
        a++;
    }
    if (b > 0)
    {
        b--;
        dfs(current + 1, made - values[current], values);
        b++;
    }
    if (c > 0)
    {
        c--;
        dfs(current + 1, made * values[current], values);
        c++;
    }
    if (d > 0)
    {
        d--;
        dfs(current + 1, made / values[current], values);
        d++;
    }
}
