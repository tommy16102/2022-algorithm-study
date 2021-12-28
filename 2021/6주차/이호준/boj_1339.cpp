/*******************************************************************
Algorithm Study
Baekjoon 6주차
1339 단어수학
2021/08/14 이호준
# 아이디어
1. greedy한 조건을 찾기 위해.. 다른문자보다 더 긴 문자열에 대해서 긴 부분들만 먼저 9 8 로 초기화해준다.
= > 문제 발생 
10개일때 988 88 .. 88 보다 899 99 .. 99 가 더 크다.
2. 그냥 dfs만 구현.. 정답..
greedy한 상황이 어떤것일까?
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int used[26];

void dfs(int current, int answer, int &max, vector<char> &left, vector<string> &input);
int getValue(vector<string> &input);

bool compare(const string &a, const string &b)
{
    return a.size() > b.size();
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int max_value = 0;
    cin >> n;
    cin.ignore();
    vector<string> input(n, "");
    for (int i = 0; i < n; i++)
    {
        getline(cin, input[i]);
    }
    sort(input.begin(), input.end(), compare);
    int current = 9;
    int min = input[n - 1].size();

    if (min == 1 && min == input[0].size())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < input[i].size(); j++)
            {
                if (used[input[i][j] - 'A'] == 0)
                {
                    used[input[i][j] - 'A'] = current--;
                }
            }
        }
        cout << getValue(input) << endl;
        return 0;
    }

    // 사용안한 변수 체크
    vector<char> left;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (used[input[i][j] - 'A'] == 0)
            {
                left.push_back(input[i][j]);
                used[input[i][j] - 'A'] = -1; // 사용안한 변수 등록시 중복 안하기 위해
            }
        }
    }

    for (int i = 0; i < left.size(); i++)
    {
        used[left[i] - 'A'] = current;
        dfs(current - 1, 1, max_value, left, input);
        used[left[i] - 'A'] = -1;
    }

    if (left.size() == 0)
        max_value = getValue(input);

    cout << max_value;

    return 0;
}

void dfs(int current, int answer, int &max_value, vector<char> &left, vector<string> &input)
{
    if (answer == left.size())
    {
        int temp = getValue(input);
        if (temp > max_value)
            max_value = temp;
        return;
    }

    for (int i = 0; i < left.size(); i++)
    {
        if (used[left[i] - 'A'] == -1)
        {
            used[left[i] - 'A'] = current;
            dfs(current - 1, answer + 1, max_value, left, input);
            used[left[i] - 'A'] = -1;
        }
    }
}

int getValue(vector<string> &input)
{
    int sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < input[i].size(); j++)
        {
            temp = temp * 10 + used[input[i][j] - 'A'];
        }
        sum += temp;
    }
    return sum;
}
