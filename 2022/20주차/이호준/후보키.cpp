/*******************************************************************
Algorithm Study
2019 Kakao Blind
후보키 level 2
2022/09/20 이호준
# 아이디어
1. 조합 구현
*******************************************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool isUniqueCheck[8];
vector<vector<string>> relations;
vector<string> minimality_check;

bool isCandidate(vector<int> candidate_index){
    unordered_map<string, bool> check;
    for(int i = 0; i< relations.size(); i++){
        string current_key = "";
        for(int index : candidate_index){
            current_key += (relations[i][index] + "_" );
        }
        if(check[current_key] == false){
            check[current_key] = true;
        }else{
            return false;
        }
    }
    return true;
}

void dfs(int &answer, int current, vector<int> &candidate, vector<int> current_keys){
    if(current >= candidate.size())
        return;
    
    string current_key = "";
    for(int index : current_keys)
        current_key += (to_string(index));
    current_key += (to_string(candidate[current]));
    
    
    for(auto check_string : minimality_check){
        if(check_string.size() <= current_key.size()){
            size_t result = check_string.find(current_key);
            size_t result2 = current_key.find(check_string);
            if(result != string::npos || result2 != string::npos){
                return;
            }
        }
    }
    current_keys.push_back(candidate[current]);
    if(isCandidate(current_keys)){
        answer += 1;
        minimality_check.push_back(current_key);
    }else {
        dfs(answer, current + 1, candidate, current_keys);
    }
    current_keys.pop_back();
    dfs(answer, current + 1, candidate, current_keys);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    relations = relation;
    int column_size = relation[0].size();
    
    for(int i = 0 ; i < column_size; i++){
        unordered_map<string, bool> unique_check;
        bool isUnique = true;
        for(int j = 0; j < relation.size(); j++){
            if(unique_check[relation[j][i]] == false){
                unique_check[relation[j][i]] = true;
            }else{
                isUnique = false;
                break;
            }
        }
        if(isUnique) {
            answer += 1;
            isUniqueCheck[i] = true;
            minimality_check.push_back(to_string(i));
        }
    }
    
    // 순열..? 결국 모든 조합을 보긴해야할 듯..!
    vector<int> candidate_columns;
    
    for(int i = 0; i < column_size; i++){
        if(!isUniqueCheck[i]){
            candidate_columns.push_back(i);
        }
    }
    
    dfs(answer, 0, candidate_columns, vector<int>());
    for(auto a : minimality_check) {
        // cout << a << " " << a.size() << " \n";
    }

    for(int i = 0; i< minimality_check.size(); i++){
        for(int j = i+1; j < minimality_check.size(); j++){
            if(i != j){
                string small, large;
                int count = 0;
                if(minimality_check[i].size() < minimality_check[j].size()){
                    small = minimality_check[i];
                    large = minimality_check[j];
                }else{
                    small = minimality_check[j];
                    large = minimality_check[i];
                }
                vector<bool> visited(large.size(), false);
                for(int a = 0; a < small.size(); a++){
                    bool out = false;
                    for(int b = 0; b < large.size(); b++){
                        if(!visited[b] && large[b] == small[a]){
                            visited[b] = true;
                            count++;
                        }
                    }
                }
                if(count == small.size()){
                    answer-=1;
                    break;
                }
            }
        }
    }
    return answer;
}