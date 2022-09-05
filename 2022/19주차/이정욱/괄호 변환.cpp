#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string s){
    vector<char> v;
    for(int i=0;i<s.size();i++){
        if(s[i] == ')' && !v.empty()) v.pop_back();
        else v.push_back(s[i]);
    }
    return v.empty();
}

string solution(string p) {
    string answer = "";
    if(p.size() == 0) return p;
    
    int left=0,right=0,i;
    string u="",v="";
    for(i=0;i<p.size();i++){
        if(p[i] == '(') left++;
        else right++;
        u += p[i];
        if(left == right) break;
    }
    for(++i;i<p.size();i++) v += p[i];
    
    if(check(u)) return u + solution(v);
    else{
        string s = "";
        for(int i=1;i<u.size()-1;i++){
            if(u[i] == ')') s += '(';
            else s += ')';
        }
        return '(' + solution(v) + ')' + s;
    }
}