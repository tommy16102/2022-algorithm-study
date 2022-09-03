/*******************************************************************
Algorithm Study
2020 Kakao Blind
괄호 압축 level 2
2022/09/03 이호준
# 아이디어
1. 순수 구현
2. solutio을 재귀로 사용하면 된다는 간단한 생각...을 못했다.
*******************************************************************/
#include <string>
#include <vector>

using namespace std;

bool isRight(string p) {
    vector<char> stack;
    for(auto a: p) {
        if(a == '(') stack.push_back(a);
        else {
            if(stack.empty()) return false;
            stack.pop_back();
        }
    }
    return stack.empty();    
}

string solution(string p) {
    if(p.empty()) return p;
    string answer = "";
    
    string u = "", v = "";
    int l = 0, r = 0;
    
    for(int i=0; i<p.length(); ++i) {
        if(p[i] == '(') l++;
        else r++;
        
        if(l == r) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(isRight(u)) answer = u + solution(v); 
    else { 
        answer = "(" + solution(v) + ")"; 
        
        for(int i=1; i<u.length()-1; ++i) {
            answer += u[i] == '(' ? ')' : '(';
        }
    }
    
    return answer;
}