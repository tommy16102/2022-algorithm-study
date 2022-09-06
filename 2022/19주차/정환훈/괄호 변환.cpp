#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check1(string u){ // 균형잡힌 괄호 문자열 판단
    int l = 0; int r = 0;
    for(int i=0;i<u.size();i++){
        if(u[i] == '(') l++;
        else if(u[i] == ')') r++;
    }
    return l==r;
}

bool check2(string u){ // 올바른 괄호 문자열 판단
    stack<char> st;
    for(int i=0;i<u.size();i++){
        char c = u[i];
        if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            if(st.empty())
                return false;
            char t = st.top();
            st.pop();
            if(t == ')')
                return false;
        }
    }
    return st.empty();
}

string go(string p){
    // 1
    if(p == "") return "";
    
    // 2
    string u =""; string v ="";
    for(int i=0;i<=p.size();i+=2){
        string tu = p.substr(0, i);
        string tv = p.substr(i);
        if(tu != "" && check1(tu) && check1(tv)){
            u = tu; v = tv;
            break;
        }
    }
    
    // 3
    if(check2(u)){
        // 3-1
        return u + go(v);
    }
    // 4
    else{
        string t = "";
        // 4-1
        t += "(";
        // 4-2
        t += go(v);
        // 4-3
        t += ")";
        // 4-4
        u = u.substr(1, u.size() - 2);
        // 4-5
        for(int i=0;i<u.size();i++){
            t += (u[i] == '(') ? ')' : '(';
        }
        return t;
    }
}

string solution(string p) {
    if(check2(p)) return p;
    return go(p);
}
