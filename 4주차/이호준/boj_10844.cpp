/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
10844 쉬운 계단 수
2021/07/28 이호준
# 아이디어
1. 뒷자리가 무엇이냐에 따라 생성할 수 있는 가지수가 2개, 1개로 나뉜다.
0, 9일 경우 1개만 생성되고
그외에는 2개의 케이스를 만들 수 있다.
뒷자리의 count만 새면서 N까지 이동한다.

※ 2차원 배열을 이용해서 푸는것이 더 좋은 방법일 수 있는 것 같다. DP의 형태를 따라감
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long answer = 0;
    cin >> N;
    if (N == 1)
    {
        cout << 9;
        return 0;
    }
    vector<long long> num(10, 2);
    num[0] = num[1] = num[9] = 1;
    for (int i = 2; i < N; i++)
    {
        vector<long long> before(10, 0);
        for (int i = 0; i < 10; i++)
            before[i] = num[i] % 1000000000;
        for (int j = 0; j < 10; j++)
        {
            int temp = before[j];
            num[j] -= temp;
            if (temp)
            {
                switch (j)
                {
                case 0:
                    num[1] += temp;
                    break;
                case 9:
                    num[8] += temp;
                    break;
                default:
                    num[j - 1] += temp;
                    num[j + 1] += temp;
                    break;
                }
            }
        }
    }
    for (auto &a : num)
    {
        answer += a % 1000000000;
    }
    cout << answer % 1000000000;
    return 0;
}

/*
	1자리 123456789 9개
	2자리 1 2,0
	      2 3 1
		  3 4 2   17
		  4 5 3
		  5 6 4
		  6 7 5
		  7 8 6
		  8 9 7
		  9 x 8

		  if 0  1 x
	결국 내 앞자리가1,2,3,4,5,6,7,8 이라면 2개 생성 0, 9 라면 1개
	3자리 17 + 15 = 32
	4 61
	5 116
	0과 9를 만드는 자리 1, 8
*/