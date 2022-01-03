#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool visited[51];
vector<int> answers;
void dfs(string begin, string target, int n, vector<string>& words) {

    if (begin == target) { // 길 찾음
        answers.push_back(n);
        return;
    }

    if (n == target.size() + 1) // 문자열 길이 넘어감
        return;

    for (int i = 0; i < words.size(); i++) { // 단어들 하나씩 비교
        int dif = 0; // 다른 글자수
        for (int j = 0; j < begin.size(); j++) { // 글자 비교
            if (begin[j] != words[i][j]) { // 다른게
                dif++; // 숫자 세기
            }
        }        
        if (dif == 1 && visited[i] == false) { // 1글자만 다르고 아직 안 바꿔본 거면
            visited[i] = true; // 백트래킹 
            dfs(words[i], target, n + 1, words); // dfs
            visited[i] = false; // 백트래킹
        }
    }



}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, target, 0, words);
    if (answers.empty()) {
        return 0;
    }
    sort(answers.begin(), answers.end());
    answer = answers[0];
    return answer;
}