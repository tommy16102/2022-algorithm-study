#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


bool area[101][101];

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    for (int i = 0; i < 4; i++) {
        int x1; int y1;
        int x2; int y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1 + 1; j <= x2; j++) {
            for (int k = y1 + 1; k <= y2; k++) { // 오른쪽 위의 점들을 체크
                area[j][k] = true;
            }
        }
    }

}

int solve() {

    int answer = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (area[i][j]) {
                answer++;
            }
        }
    }

    cout << answer;

    return answer;
}


int main() {
    input();
    solve();
    return 0;
}