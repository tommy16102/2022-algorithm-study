/*******************************************************************
Algorithm Study
Baekjoon OJ DP
1141 접두사
2022/01/04 이호준
# 아이디어
1. string을 정렬하고 순서대로 비교하면 접두사 여부를 알 수 있다. find를 이용해서 찾은 위치가 index 0 이라면 접두사이다.
접두사관계라면 해당 string을 제외해준다. (answer-=1)
*******************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<string> inputs;
    cin >> n;
    int answer = n;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        inputs.push_back(input);
    }

    sort(inputs.begin(), inputs.end());
    string current = inputs[0];

    for (int i = 1; i < inputs.size(); i++)
    {
        if (inputs[i].find(current) == 0)
        {
            // cout << inputs[i] << " current : " << current << endl;
            answer -= 1;
        }
        current = inputs[i];
    }

    cout << answer;

    return 0;
}