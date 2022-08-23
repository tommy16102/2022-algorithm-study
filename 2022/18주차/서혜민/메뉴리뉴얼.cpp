#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
map<int, int> courseMap;

void initCourseMap(vector<int> course) {
    for (int i : course) courseMap[i] = 2;
}

void dfs(int cnt, int idx, string now, string str) {
    if (now.length() == cnt) {
        sort(now.begin(), now.end());
        m[now]++;
    }
    else if (idx >= str.length()) return;
    else {
        dfs(cnt, idx + 1, now + str[idx], str);
        dfs(cnt, idx + 1, now, str);
    }
}

void makeDfs(vector<string> orders, vector<int> course) {
    for (int i : course) {
        for (string s : orders) dfs(i, 0, "", s);
    }
}

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<pair<string,int>> sortMap() {
    vector<pair<string,int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), comp);
    return v;
}

vector<string> calc(vector<pair<string,int>> v) {
    vector<string> ans;
    for (auto pair : v) {
        if (pair.second < 2) break;
        if (courseMap[pair.first.length()] <= pair.second) {
            courseMap[pair.first.length()] = pair.second;
            ans.push_back(pair.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    initCourseMap(course);
    makeDfs(orders, course);
    return calc(sortMap());
}
