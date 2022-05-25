#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getMinIndex(unordered_map<string, int>& current_loc){
    int min_value = 2100000000;
    for(pair<string, int> a : current_loc){
        if(min_value > a.second && a.second != -1){
            min_value = a.second;
        }
    }
    return min_value;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> temp = gems;
    
    // 중복제거 보석 개수 구하기
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    unordered_map<string, int> current_loc;
    for(auto a : temp){
        current_loc.insert({a, -1});
    }
    int find_num = temp.size();
    
    int left = 0;
    int left_index = 0;
    int right = 0;
    int current_buy_count = 0;
    // gem 돌면서 있으면 업데이트 ( 만약 첫번째라면 업데이트 x )
    // 투포인터 알고리즘
    while(left <= right){
        if(right == gems.size()){
            if(current_buy_count == find_num){
            if(!answer.empty()){
                int temp_length = answer[1] - answer[0]+1;
                int current_length = right - left;
                if(temp_length > current_length){
                    answer.clear();
                    answer.push_back(left+1);
                    answer.push_back(right);
                }
            }else{
                answer.push_back(left+1);
                answer.push_back(right);
            }
            string left_string = gems[left];
            current_loc[left_string] = -1;
            left = getMinIndex(current_loc);
            current_buy_count--;
            }
            break;
        }
        if(current_buy_count < find_num){
            string current_gem = gems[right];
            if(current_loc[current_gem] == -1){
                current_loc[current_gem] = right;
                current_buy_count++;
            }else{
                if(current_loc[current_gem]!= left){
                    current_loc[current_gem] = right;
                }else{
                    current_loc[current_gem] = right;          
                    left = getMinIndex(current_loc);
                }
            }
            right++;
        }else if(current_buy_count == find_num){
            if(!answer.empty()){
                int temp_length = answer[1] - answer[0]+1;
                int current_length = right - left;
                if(temp_length > current_length){
                    answer.clear();
                    answer.push_back(left+1);
                    answer.push_back(right);
                }
            }else{
                answer.push_back(left+1);
                answer.push_back(right);
            }
            string left_string = gems[left];
            current_loc[left_string] = -1;
            left = getMinIndex(current_loc);
            current_buy_count--;
        }
    }
    
    return answer;
}