/*******************************************************************
Algorithm Study
2022 KAKAO TECH INTERNSHIP 코딩테스트 공부
2023/05/01 이호준
# 아이디어
1. DP
DFS로 가능하지만 중복된 연산을 줄이고 최적화하기위해 DP(Memoization) 수행
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 2100000000

using namespace std;

int maxAlp, maxCop;
// [a][b] a, b일 때 다 풀때까지 걸리는 최소 cost
int cache[151][151];

int solve(int alp, int cop, vector<vector<int>>& problems) {
    if(alp >= maxAlp && cop >= maxCop) return 0;
    
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    
    int& ret = cache[alp][cop];
    if(ret != 0) return ret;
    ret = INF;
    
    for(vector<int> v : problems) {
        if(alp < v[0] || cop < v[1]) continue;
        ret = min(ret, solve(alp + v[2], cop + v[3], problems) + v[4]);
    }
    
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    problems.insert(problems.begin(), {0, 0, 0, 1, 1});
    problems.insert(problems.begin(), {0, 0, 1, 0, 1});
    for(vector<int> v: problems) {
        maxAlp = max(maxAlp, v[0]);
        maxCop = max(maxCop, v[1]);
    }
    
    return solve(alp, cop, problems);
}