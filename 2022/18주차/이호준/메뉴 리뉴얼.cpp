/*******************************************************************
Algorithm Study
2021 Kakao Blind
메뉴리뉴얼 level 2
2022/08/30 이호준
# 아이디어
1. 조합
*******************************************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
-> 조합 경우의 수 넣은 후
*/
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;
    
    unordered_map<string, int> menu_counts;
    
    for(int i = 0; i<course.size(); i++){
        for(int j = 0; j <orders.size(); j++){
            if(orders[j].size() < course[i])
                continue;
            vector<int> combinations;
            // orders.size() C course
            // 0 1 2 3 4
            for(int a = 0; a < orders[j].size() - course[i]; a++){
                combinations.push_back(0);
            }
            for(int a = 0; a < course[i]; a++){
                combinations.push_back(1);
            }
            do{
                string temp = "";
                for(int a = 0; a < combinations.size(); a++){
                    if(combinations[a]){
                        temp += orders[j][a];
                    }
                }
                sort(temp.begin(), temp.end());
                if(menu_counts.find(temp) == menu_counts.end()){
                    menu_counts[temp] = 1;
                }else{
                    menu_counts[temp]++;
                }
                
            }while(next_permutation(combinations.begin(), combinations.end()));     
        }
        
        int max = 2;
        vector<string> candidates;
        for(auto a : menu_counts){
            if(a.second >= max){
                if(a.second != max){
                    max = a.second;
                    candidates.clear();
                }
                candidates.push_back(a.first);
            }
        }
        for(auto c : candidates){
            answer.push_back(c);
        }
        menu_counts.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}