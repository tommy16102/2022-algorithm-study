#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<string, int> cntMap;
map<string, set<string>> singoMap;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    for (int i = 0; i < report.size(); i++) {
        
        string s = report[i];
        int idx = s.find(" ");
        
        string from = s.substr(0, idx);
        string to = s.substr(idx + 1, s.length() - idx - 1);
        
        if (singoMap[to].find(from) == singoMap[to].end())  cntMap[to]++;
        singoMap[to].insert(from);
    
    }
    
    vector<int> ans(id_list.size(), 0);
    
    for (int i = 0; i < id_list.size(); i++) {
        
        string id = id_list[i];
        if (cntMap[id] < k) continue;
        
        set s = singoMap[id];
        
        for (int j = 0; j < id_list.size(); j++) {
            
            auto it = s.find(id_list[j]);
            if(it == s.end()) continue;
            ans[j]++;
            
        }
        
    }
    
    return ans;
    
}