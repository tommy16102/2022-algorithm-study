#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {  
    long long sum = 0;
    long long b4 = 0;
    long long eat = k;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<food_times.size();i++){
        sum += food_times[i];
        pq.push({-1 * food_times[i], i+1});
    }
    // 다 먹어서 k+1 시간에 먹을 게 없음
    if(sum <= eat) 
        return -1;
    
    // (가장 작은 수 - 이전에 뺀 수) * 현재 살아있는 음식 수만큼 eat 수가 올라간다
    // 예제에서는 [3,1,2] -> [2,0,1]이 되므로 이제 (2 - 1) * 2이 더해짐
    while((-pq.top().first - b4) * pq.size() <= eat){
        eat -= (-pq.top().first - b4) * pq.size();
        b4 = -pq.top().first;
        pq.pop();
    }
    
    vector<pair<int,int>> v;
    while(!pq.empty()){
        pair<int,int> now = pq.top();
        v.push_back({now.second, -1 * now.first});
        pq.pop();
    }
    // 원래 인덱스 순서대로 다시 배열
    sort(v.begin(), v.end());
    // 살아남은 원래 배열에서 남은 eat수만큼 더해주면 그곳이 다음에 먹을 곳
    return v[eat % v.size()].first;
}
