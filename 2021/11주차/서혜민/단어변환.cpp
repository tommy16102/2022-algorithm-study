#include string
#include algorithm
#include vector
using namespace std;

 2021.09.18 dfs

bool visited[50];
vectorstring v(50);
int answer = 51;

void dfs(string start, string target, int ans, int size) {
    if (start == target) {
        answer = min(ans, answer);
        return;
    }
    if (ans = size) return;

    for (int i = 0;i  size;i++) {
        if (visited[i]) continue;
        int count = 0;
        for (int j = 0;j  start.length();j++) {
            if (count  1) break;
            if (start[j] != v[i][j]) count++;
        }
        if (count == 1) {
            visited[i] = 1;
            answer, dfs(v[i], target, ans + 1, size);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vectorstring words) {
    for (int i = 0;i  words.size();i++) {
        v[i] = words[i];
    }
    auto it = find(v.begin(), v.end(), target);
    if (it == v.end()) return 0;
    else {
        for (int i = 0;i  words.size();i++) {
            int count = 0;
            for (int j = 0;j  begin.length();j++) {
                if (begin[j] != v[i][j]) count++;
                if (count  1) break;
            }
            if (count == 1) {
                visited[i] = 1;
                dfs(v[i], target, 1, words.size());
                visited[i] = 0;
            }
        }
        return answer;
    }
}