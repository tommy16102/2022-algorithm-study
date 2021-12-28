/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
14889 스타트와 링크
2021/08/05 이호준
# 아이디어
1. 조합을 이용해서 풀었다.
※ 조합을 next_permutation을 통해 구현하는 법을 익힐 수 있었다.
문제에서 nCn/2를 구하는 것과 같은 경우의 수이므로 n-n/2만큼 false를 n/2만큼 true를 넣어주면된다.
nCr n-r false, r true
이떄 false, true순으로 넣어야 next_permutation을 사용할 수 있다. (오름차순 정렬이므로)

2. 백준 가장 빠른 코드들을 봤는데 수학적으로 잘 푼 것 같다. 예전에 이런방식으로 접근했었던 것이 기억나는 것 같다.
// 구글 코드
// 그래프의 전체 값에서 선택된 인덱스의 행과 열 값들을 뺴주면 결국 남는게 문제에서 구하는 팀간의 차이가 된다.
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

    cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    //for (auto a : map) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}

    int min = 2000;
    vector<bool> combination(n, false); // nCn/2
    for (int i = n / 2; i < n; i++)
        combination[i] = true;
    do
    {
        if (min == 0)
            break;
        int check = 0;
        /*for (auto a : combination)
			cout << a << " ";
		cout << endl;*/
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (combination[i] && combination[j])
                {
                    check += map[i][j];
                }
                else if (!combination[i] && !combination[j])
                {
                    check -= map[i][j];
                }
            }
        }
        if (abs(check) < min)
            min = abs(check);
    } while (next_permutation(combination.begin(), combination.end()));

    cout << min;
    return 0;
}

// 구글 코드
// 그래프의 전체 값에서 선택된 인덱스의 행과 열 값들을 뺴주면 결국 남는게 문제에서 구하는 팀간의 차이가 된다.
//#include <stdio.h>
//#include <stdlib.h>
//
//using namespace std;
//
//int N, in, total = 0;
//int arr[20][20];
//int x[20] = { 0 };
//int mini = 2000;
//
//void dfs(int idx, int cnt, int res) {
//	if (cnt == N / 2) {
//		if (mini > abs(res)) mini = abs(res);
//		return;
//	}
//	if (idx < N - 1) {
//		dfs(idx + 1, cnt + 1, res - x[idx]);
//		dfs(idx + 1, cnt, res);
//	}
//}
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			scanf("%d", &in);
//			total += in;
//			x[i] += in;
//			x[j] += in;
//		}
//	}
//
//	dfs(0, 0, total);
//	printf("%d\n", mini);
//	return 0;
//}
