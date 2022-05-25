#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int ans = 0;
bool visited[8];
set<vector<string>> s;

bool compare(string s, string s2) {
    
    if (s.length() != s2.length()) return false;
    
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] == s2[i] || s2[i] == '*')) return false;
    }
    
    return true;
}

void find(vector<string> &user, vector<string> &ban, int now, int cnt) {
    if (cnt == ban.size()) {
        vector<string> v;
        for (int i = 0; i < user.size(); i++){
            if (visited[i]) v.push_back(user[i]); 
        }
        sort(v.begin(), v.end());
        s.insert(v);
        return;
    }
    
    for (int i = 0; i < user.size(); i++) {
        if (visited[i]) continue;
        if (compare(user[i], ban[now])) {
            visited[i] = 1;
            find(user, ban, now + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}
    
int solution(vector<string> user_id, vector<string> banned_id) {
    find(user_id, banned_id, 0, 0);
    
    return s.size();
}
