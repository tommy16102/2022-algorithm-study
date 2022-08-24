#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 987654321;
int arr[201][201];

void initArr(int n, vector<vector<int>> fares) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = MAX;
            if (i == j) arr[i][j] = 0;
        }
    }
    for (int i = 0; i < fares.size(); i++) {
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
}

void washall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
}

int getAnswer(int n, int s, int a, int b) {
    int answer = arr[s][a] + arr[s][b];
    for (int i = 1; i <= n; i++) {
        if (i != s && arr[s][i] != MAX) answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }
    return answer;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    initArr(n, fares);
    washall(n);
    return getAnswer(n, s, a, b);
}
