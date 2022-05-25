#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_value = 0;
vector<int> current_max;
vector<int> apeach;

bool visited[11];

int calculate(vector<int>& lion){
    int score = 0;
    for(int i = 0; i < 10; i++){
        if(apeach[i] != 0 || lion[i] != 0){
            if(apeach[i] >= lion[i]){
                score -= (10-i);
            }else{
                score += (10-i);
            }
        }
    }
    if(score == 0)
        score = -1;
    
    return score;
}

void dfs(int n, int current_count, vector<int>& lion, int step){
    if(current_count == n){
        int current_score = calculate(lion);
        if(current_score >= max_value){
            if(current_score == max_value){
                // 낮은것 부터 체크
                if(!current_max.empty()){
                    for(int i = 10; i >= 0; i--){
                        if(lion[i] > current_max[i]){
                            current_max = lion;
                            break;
                        }else if (lion[i] == current_max[i]){
                            continue;
                        }else{
                            break;
                        }
                    }   
                }
                
            }else{
                max_value = current_score;
                current_max = lion;
            }
        }
        return;
    }
    
    for(int i = step; i < 11; i++){
        if(i == 10){
            lion[i] = n-current_count;
            dfs(n, n, lion, i+1);
            lion[i] = 0;
        }else{
            lion[i] = apeach[i] + 1;
            if(current_count + apeach[i] + 1 <= n){
                dfs(n, current_count + apeach[i] + 1, lion, i+1);
            }
            lion[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    // 15:22
    vector<int> answer;
    vector<int> lion(info.size(), 0);
    apeach = info;
    
    dfs(n, 0, lion, 0);
    
    if(max_value == 0 || current_max.empty()){
        answer.push_back(-1);
    }else{
        answer = current_max;
    }
    
    return answer;
}