#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    
    s = s.substr(1, s.length() - 2);
    
    vector<vector<int>> tuples;
    
    int startIndex = 0;
    int open, close;
    
    while (1) {
        int findIndex = s.find('{', startIndex);
        if (findIndex == -1) break;
        
        open = findIndex;
        close = s.find('}', open);
        
        vector<int> nums;
        string num;
        for (int i = open + 1; i < close; i++) {
            
            if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            }
            
            if (i == close - 1 || (num != "" && (s[i] <'0' || s[i] >'9'))) {
                nums.push_back(stoi(num));
                num = "";
            }
        }
        
        tuples.push_back(nums);
        startIndex = close + 1;
    
    }
    
    sort(tuples.begin(), tuples.end(), comp);
    
    
    vector<int> answer;
    map<int, int> m;
    for (int i = 0; i < tuples.size(); i++) {
        for (auto j : tuples[i]) {
            if (!m[j]) {
                answer.push_back(j);
                m[j] = 1;
            }
        }
    }
    
    return answer;
}