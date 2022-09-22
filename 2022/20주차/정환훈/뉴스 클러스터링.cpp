#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
map<string, int> m1;
map<string, int> m2;

int solution(string str1, string str2) {
    int answer = 0;
    string s1 = str1; string s2 = str2;
    vector<string> s1Strs; vector<string> s2Strs;
    vector<string> strs;
    for(int i=0;i<s1.size();i++){
        if(i < s1.size() - 1){
            string now = s1.substr(i, 2);
            if(isalpha(now[0]) && isalpha(now[1])){
                now[0] = toupper(now[0]); now[1] = toupper(now[1]);
                m[now]++;
                m1[now]++;
                s1Strs.push_back(now);
                strs.push_back(now);
            }
        }
    }
    
    for(int i=0;i<s2.size();i++){
        if(i < s2.size() - 1){
            string now = s2.substr(i, 2);
            if(isalpha(now[0]) && isalpha(now[1])){
                now[0] = toupper(now[0]); now[1] = toupper(now[1]);
                m[now]++;
                m2[now]++;
                s2Strs.push_back(now);
                strs.push_back(now);
            }
        }
    }
    
    if(m.size() == 0) return 65536;
    
    sort(strs.begin(), strs.end());
    strs.erase(unique(strs.begin(), strs.end()), strs.end());
    
    int anb = 0;
    int aub = 0;
    
    for(int i=0;i<strs.size();i++){
        aub += max(m1[strs[i]], m2[strs[i]]);
        anb += min(m1[strs[i]], m2[strs[i]]);
    }
    
    answer = (double)anb / (double)(aub) * 65536;
    return answer;
}
