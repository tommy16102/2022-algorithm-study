/*******************************************************************
Algorithm Study
2019 Kakao Blind
무지의 먹방라이브 level 4
2022/09/21 이호준
# 아이디어
1. 정렬을 잘하여 수학적으로 논리적으로 접근하는 문제
2. 효율성 풀이를 위해 O(N) 으로 구현해야한다.

### 유튜브 알고리즘 참고함.
https://www.youtube.com/watch?v=Knmo90E42ls&t=1332s
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> foods; // first : 해당 음식 먹는데 필요한 시간, second : 번호 (정렬 전 원래 순서)
    int n = food_times.size();
    for (int i = 0; i < n; ++i)
        foods.push_back(make_pair(food_times[i], i + 1));
    sort(foods.begin(), foods.end()); 
    int pretime = 0; 
    for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); ++it, --n) {  
        long long spend = (long long)(it->first - pretime) * n;
        if (spend == 0) continue; 
        if (spend <= k) {  
            k -= spend; 
            pretime = it->first; 
        }
        else { 
            k = k % n; 
            sort(it, foods.end(), comp); 
            return (it + k)->second;   
        }
    }
    return -1;
}