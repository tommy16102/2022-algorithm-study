/*******************************************************************
Algorithm Study
Baekjoon 9주차 다익스트라/이분탐색
7453 합이 0인 네 정수
2021/09/07 이호준
# 아이디어
1. 굉장히 어려웠다.
ABCD의 4개를 bruteforce로 탐색하는 방식은 시간초과가 당연히 나는 O(n^4)이다.
다음으로 각 자리를 sort해서 음수 양수 조합을 생각해 보자고 생각했으나 이건 위와 같은 방식이였다.

n^2로 실시하기 위해 2개의 집합으로 나눠 A와B, C와D의 합의 집합을 구하고
두 집합을 sort한 후 두 개의 포인터를 통해 합이 0이 되는 케이스를 찾는 방식이 정답이였다.

결국 이분탐색의 두 개의 포인터로 구현을 할 수 있도록 어떻게 문제를 변형하는 가가 중점인 문제 인 것 같다.
문제를 이분탐색으로 처리할 수 있도록 문제를 풀어나가는 방식을 배울 수 있었다.

문제에 대한 알고리즘을 생각하고 어떻게 그와 같은 알고리즘으로 구현할 수 있을지 구현하는 능력이 중요하다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v1(n * n), v2(n * n);
    vector<long long> A(n), B(n), C(n), D(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v1[index] = A[i] + B[j];
            v2[index] = C[i] + D[j];
            index++;
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int front = 0, back = n * n - 1;
    long long count = 0;
    while (front < v1.size() && back >= 0)
    {
        long long sum = v1[front] + v2[back];
        if (sum == 0)
        {
            long long xcount = 0, ycount = 0;
            int x = v1[front];
            int y = v2[back];
            while (v2[back] == y)
            {
                ycount++;
                back--;
                if (back == -1)
                    break;
            }
            while (v1[front] == x)
            {
                xcount++;
                front++;
                if (front == v1.size())
                    break;
            }
            count += (ycount * xcount);
            continue;
        }
        if (sum > 0)
            back--;
        else
            front++;
    }
    cout << count;
}