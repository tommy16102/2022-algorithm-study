#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int stuck[501];

bool cmp(pair<double,int> p1, pair<double,int> p2){
    
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    
    return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> p;
    sort(stages.begin(), stages.end());
    for(int i=0;i<stages.size();i++){
        int stage = stages[i];
        stuck[stage]++;
    }
    
    // stage n의 실패율 = sutck[n] / sutck[n] + stuck[n+1] ... 이상인 친구들
    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=i;j<=N+1;j++){
            sum += stuck[j];
        }
        //cout << i <<  "의 실패율 : " << (double)stuck[i] / (double)sum << endl;
        if(sum == 0)
            p.push_back({0, i});
        else
            p.push_back({(double)stuck[i] / (double)sum, i});
    }
    sort(p.begin(), p.end(), cmp);
    for(int i=0;i<p.size();i++){
        answer.push_back(p[i].second);
    }
    
    return answer;
}
