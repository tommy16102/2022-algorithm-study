#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int calc(string s, int n) {
    string ans = "", str = "";
    int cnt = 0;
    for (int i = 0; i < s.length(); i+= n) {
        string part = s.substr(i, n);
        if (str == part) cnt++;
        else {
            if (str != "") ans += ((cnt == 1) ? "" : to_string(cnt)) + str;
            str = part;
            cnt = 1;
        }
        if (i + n >= s.length()) ans += ((cnt == 1) ? "" : to_string(cnt)) + str;
    }
    return ans.length();
}

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length(); i++) answer = min(answer, calc(s, i));
    return answer;
}
