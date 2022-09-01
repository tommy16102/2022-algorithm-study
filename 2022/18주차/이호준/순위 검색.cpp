/*******************************************************************
Algorithm Study
2021 Kakao Blind
순위검색 level 2
2022/08/31 이호준
# 아이디어
1. 경우의 수 -> 비트마스킹을 이용해 표현 -> db를 생성해 나중에 탐색에 유용
2. 이분탐색 -> Yes or No Decision Problem
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> data_parse(string data) {
    vector<string> ret;
    string tmp = "";
    
    for(auto c: data) {
        if(c == ' ') {
            if(tmp != "and") ret.push_back(tmp);
            tmp = "";
        }
        else tmp += c;
    }        
    
    ret.push_back(tmp);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    unordered_map<string, vector<int>> db;
    for(auto inf: info) {
        vector<string> key = data_parse(inf);
        
        for(int i=0; i<16; ++i) {
            string tmp = "";            
            for(int j=0; j<4; ++j) {
                tmp += (i & (1 << j)) ? key[j] : "-";
            }
            db[tmp].push_back(stoi(key[4]));
        }
    }
    
    for(auto &iter: db) sort(iter.second.begin(), iter.second.end());    
    
    for(auto q: query) {
        vector<string> key = data_parse(q);
        
        string k = key[0] + key[1] + key[2] + key[3];
        vector<int> res = db[k];
        
        int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(key[4]));
        answer.push_back(cnt);
    }
    
    return answer;
}