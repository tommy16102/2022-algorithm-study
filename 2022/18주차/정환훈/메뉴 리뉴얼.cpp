#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> all[11];
char temp[11];
int sel[11];
map<string, int> m;

void nCr(int depth, int id, int n, int r, string now){
    if(depth == r){
        string s = "";
        for(int i=0;i<r;i++){
            s += temp[i];
        }
        sort(s.begin(), s.end());
        all[r].push_back(s);
        m[s]++;
        return;
    }
    
    for(int i=id;i<n;i++){
        if(sel[i])
            continue;
        sel[i] = true;
        temp[depth] = now[i];
        nCr(depth+1, i, n, r, now);
        sel[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        
        string now = orders[i];
        int n = now.size();
        for(int r=1;r<=n;r++){
            nCr(0, 0, n, r, now);
            // nC1 + nC2 + nC3 + .... + nCn
        }
    }
    
    for(int i=0;i<course.size();i++){
        int n = course[i];
        int maxValue = 0;
        for(int j=0;j<all[n].size();j++){
            maxValue = max(maxValue, m[all[n][j]]);
        }
        for(int j=0;j<all[n].size();j++){
            if(m[all[n][j]] == maxValue && maxValue != 1){
                answer.push_back(all[n][j]);
            }
        }        
    }    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}