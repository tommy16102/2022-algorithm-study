#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

map<int, int> stageMap;
vector<pair<int, double>> stageVec;

void initMap(vector<int> stages) {
    for (int stage: stages) stageMap[stage]++;
}

void initVec(int size, int N) {
    for (int i = 1; i <= N; i++) {
        int stageMan = stageMap[i];
        if (size == 0) stageVec.push_back({i, 0});
        else stageVec.push_back({i, stageMan / (double)size});
        size -= stageMan;
    }
}

bool comp(pair<int,double> a, pair<int,double> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> makeVec() {
    vector<int> v;
    for (auto pair : stageVec) v.push_back(pair.first);
    return v;
}
vector<int> solution(int N, vector<int> stages) {
    initMap(stages);
    initVec(stages.size(), N);
    sort(stageVec.begin(), stageVec.end(), comp);
    return makeVec();
}