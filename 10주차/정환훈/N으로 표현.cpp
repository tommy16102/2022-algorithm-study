#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // 210916

vector<int> answers;
int N_GL; int number_gl;
void dfs(int depth, int number) {
    if (depth >= 9)
        return;

    if (number == number_gl) { // 정답 발견
        answers.push_back(depth);
        return;
    }

    int n = 0;
    for (int i = 0; i < 8; i++) { // 1~8자리 까지
        n = n * 10 + N_GL;
        dfs(depth + i + 1, number + n);
        dfs(depth + i + 1, number - n);
        if (number != 0) {
            dfs(depth + i + 1, number * n);
            dfs(depth + i + 1, number / n);
        }
    }
}

int solution(int N, int number) { // N : 1 ~ 9

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    N_GL = N; number_gl = number;

    dfs(0, 0);
    
    if (!answers.empty()) {
        sort(answers.begin(), answers.end());
        return answers[0];
    }
    return -1;
}