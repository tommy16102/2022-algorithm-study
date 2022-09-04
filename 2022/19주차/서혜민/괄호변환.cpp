#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool checkCorrect(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!s.empty() && c == ')' && s.top() == '(') s.pop();
        else s.push(c);
    }
    return s.empty();
}

int findPos(string p) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') cnt1++;
        else cnt2++;
        if (cnt1 == cnt2) return i;
    }
}

string calc(string p) {
    if (p == "") return p;
    int pos = findPos(p);
    string u = p.substr(0, pos + 1);
    string v = p.substr(pos + 1);
    string ans = "";
    if (checkCorrect(u)) ans = u + calc(v);
    else {
        ans = "(" + calc(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            ans += (u[i] == '(') ? ')' : '(';
        }
    }
    return ans;
}

string solution(string p) {
    return calc(p);
}
