#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    // [name].{index, count}
    unordered_map<string, pair<int,int>> report_info;
    for(int i = 0; i< id_list.size(); i++){
        report_info.insert({id_list[i], {i, 0}});
    }
    vector<int> attack_info[1001];
    for(int i =0; i< report.size(); i++){
        string current_info = report[i];
        int delimiter = current_info.find(' ');
        string reporter = current_info.substr(0, delimiter);
        string bad_user = current_info.substr(delimiter+1);
        int reporter_index = report_info[reporter].first;
        int bad_user_index = report_info[bad_user].first;
        attack_info[reporter_index].push_back(bad_user_index);
    }

    for(int i = 0; i < id_list.size(); i++){
        sort(attack_info[i].begin(), attack_info[i].end());
    }
    
    for(int i = 0; i < id_list.size(); i++){
        attack_info[i].erase(unique(attack_info[i].begin(),attack_info[i].end()),attack_info[i].end());
    }
    
    vector<int> who_attack[1001];
    
    for(int i= 0; i< id_list.size(); i++){
        vector<int> temp = attack_info[i];
        for(int a = 0; a < temp.size();a++){
            report_info[id_list[temp[a]]].second++;
            who_attack[temp[a]].push_back(i);
        }
    }

    for(int i = 0; i< id_list.size(); i++){
        if(report_info[id_list[i]].second >= k){
            for(int a = 0 ; a < who_attack[i].size(); a++){
                answer[who_attack[i][a]]++;
            }
        }
    }
    
    
    return answer;
}