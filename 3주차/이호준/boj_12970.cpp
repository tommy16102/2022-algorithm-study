/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
12970 AB
2021/07/21 이호준
# 아이디어
1. 최대로 만들 수 있는 개수가 몇개일까? 10 개라면 5* 5, 11개라면 5*6
2. N > K 라면 A 1개로 만들 수 있다.
3. N == K 라면 2개의 조합으로 만들 수 있다. 짝수 2*(N/2), 홀수 (N/2)+ (N/2)+1
4. N < K 라면 최대 개수까지는 만들 수 있다. 그 이상의 K는 모두 실패
   최대로 만들 수 있는 경우를 보면 5*5, 5*6으로 N/2, N/2+1을 기준으로 해당 개수를 몇개나 포함할 수 있나가 중요하다.
   N/2를 x 라하면 1* x, 1*x +y , 2 *x + y, ... , x *x 이런식으로 최대보다 작은수를 표현할 수 있다.
   즉 N/2개의 B를 기준으로 2*5 + 알파로 N/2을 몫으로 하여 몫과 나머지로 해당 K를 만족시키고 
   만약 이때 만들어진 string의 길이가 N보다 적다면 앞에 B를 N길이가 되도록 붙여준다. 
*******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    string answer = "";
    cin >> N >> K;
    if (N > K)
    {
        if (K == 0)
        {
            for (int i = 0; i < N - 1; i++)
                answer += "B";
            answer += "A";
        }
        else
        {
            // BABBBB  (n-k-1)1 k
            for (int i = 0; i < N - K - 1; i++)
                answer += "B";
            answer += "A";
            for (int i = 0; i < K; i++)
                answer += "B";
        }
        cout << answer;
    }
    else if (N == K)
    {
        if (K < 4)
            answer = "-1";
        else
        {
            if (N % 2 == 0)
            {
                // 4 2 + 2, 6 3 + 3
                int count = N - (N / 2) - 2;
                for (int i = 0; i < count; i++)
                    answer += "B";
                for (int i = 0; i < 2; i++)
                    answer += "A";
                for (int i = 0; i < N / 2; i++)
                    answer += "B";
            }
            else
            {
                // 5 2 + 3   ABABB, 7 ,3 + 4 BABABBB, 9, 5 + 4 BBABABBBB
                int count = N - N / 2 - 1 - 2;
                for (int i = 0; i < count; i++)
                    answer += "B";
                answer += "ABA";
                for (int i = 0; i < N / 2; i++)
                    answer += "B";
            }
        }
        cout << answer;
    }
    else
    {
        if (N % 2 == 0)
        {
            if (K > (N / 2) * (N / 2))
                answer = "-1";
            else
            {
                // 8 4 4
                for (int i = 0; i < N / 2; i++)
                    answer += "B";
                for (int i = 0; i < K / (N / 2); i++)
                    answer = "A" + answer;
                if (K % (N / 2))
                {
                    // BBBB
                    answer.insert(answer.end() - (K % (N / 2)), 'A');
                }
                while (answer.size() != N)
                    answer = "B" + answer;
            }
        }
        else
        {
            if (K > (N / 2) * (N / 2 + 1))
                answer = "-1";
            else
            {
                // 5 * 6
                int max = N / 2 + 1;
                for (int i = 0; i < max; i++)
                    answer += "B";
                for (int i = 0; i < K / max; i++)
                    answer = "A" + answer;
                if (K % max)
                {
                    // BBBB
                    answer.insert(answer.end() - (K % max), 'A');
                }
                while (answer.size() != N)
                    answer = "B" + answer;
            }
        }
        cout << answer;
    }
    return 0;
}
/*
	A B
	0 <= i < j < 6
	0 1 2 3 4 5
    A A B A B B
	
	3+ 3 + 2
	
	k == 0 BBBBBBA
	BABAB

	BBBBB
	BBABB

	BABBB 3
	BABAB 2 + 1
	BAAAB 1 + 1 + 1

	ABABB 3 + 2

	if N > K

	ABB
	3 2
	ABB
	3 1
	BAB

	4 2
	BABB
	3 3
	6 6
	BAABBB
	5 5
	4 4
	AABB
	2 2
	3 3
	ABB
	5 5 
	ABABB

	4 6 6
	AAAB

	10
	9 * 1 8 * 2 3 * 7, 4 * 6, 5 * 5, 6 * 4
	AAAABBBBB
	6 6
	6665

	11
	1* 10, 2* 9, 3* 8, ... 4*7, 5*6, 6*5
*/