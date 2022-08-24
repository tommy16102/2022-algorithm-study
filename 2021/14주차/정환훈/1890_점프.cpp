#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int board[101][101];
long long way[101][101];

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            way[i][j] = 0;
        }
    }
}


void solve2() {

    way[1][1] = 1;

    for (int i = 1; i <= n; i++) { // 세로
        for (int j = 1; j <= n; j++) { // 가로
            if (i == n && j == n) { // 끝칸 도달시 해당 칸 길 가지수 출력
                cout << way[n][n];
                return;
            }
            if (way[i][j]) { // 도달 할 수 있는 블록일 시
                int jump = board[i][j]; // 점프할 칸수
                if (i + jump <= n) // 세로 점프 가능
                    way[i + jump][j] += way[i][j]; // 점프한 곳에 기록
                if (j + jump <= n) // 가로 점프 가능
                    way[i][j + jump] += way[i][j]; // 점프한 곳에 기록
            }
        }
    }

    //cout << endl;
    //for (int i = 1; i <= 4; i++) {
    //    for (int j = 1; j <= 4; j++) {
    //        cout << way[i][j] << " ";
    //    }
    //    cout << endl;
    //}


}

void dfs(int i, int j) { // dfs로 구현. 당연히 될리가 없다
    int jump = board[i][j];

    if (jump == 0) return;

    if (i + jump <= n) {
        way[i + jump][j]++;
        dfs(i + jump, j);
    }
    if (j + jump <= n) {
        way[i][j + jump]++;
        dfs(i, j + jump);
    }
}

void solve() { // 0 ~ 9 사이라는 걸로 0~9칸 전까지 확인하는 식으로 했는데 시간초과

    int garo = 1;
    while (garo < n) {
        if (garo + board[1][garo] <= n) {
            garo = garo + board[1][garo];
            way[1][garo]++;
        }
        else break;
    }

    int sero = 1;
    while (sero < n) {
        if (sero + board[sero][1] <= n) {
            sero = sero + board[sero][1];
            way[sero][1]++;
        }
        else break;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int temp = 1;
            while (j - temp >= 1 && temp <= 9) {
                if (board[i][j - temp] == temp) {
                    way[i][j] += way[i][j - temp];
                }
                temp++;
            }
            temp = 1;
            while (i - temp >= 1 && temp <= 9) {
                if (board[i - temp][j] == temp) {
                    way[i][j] += way[i - temp][j];
                }
                temp++;
            }
        }
    }

    cout << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << way[i][j] << " ";
        }
        cout << endl;
    }

    cout << way[n][n];

}


int main() {
    input();
    solve2();
    return 0;
}