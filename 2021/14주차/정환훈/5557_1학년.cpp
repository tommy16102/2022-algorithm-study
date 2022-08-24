#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
long long d[200][200]; // dp[a][b] = a까지 왔을 때 결괏값이 b인 경로 개수
vector<int> numbers;
void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        numbers.push_back(t);
    }
}

// 11
//  8 3 2 4 8 7 2 4 0 8 8
// d[1][8]=1
// d[2][11] = 1 d[2][5] = 1
// d[3][13] = 1 d[3][9] = 1 d[3][7] = 1 d[3][3] = 1

void dfs(int now, int depth) {
    if (depth == numbers.size() - 1) {
        if (now == numbers.back()) {
            //answers++;
            return;
        }
    }
    if (now + numbers[depth] >= 0 && now + numbers[depth] <= 20) {
        dfs(now + numbers[depth], depth + 1);
    }
    if (now - numbers[depth] >= 0 && now - numbers[depth] <= 20) {
        dfs(now - numbers[depth], depth + 1);
    }
}

void solve() {
    
    for (int i = 1; i <= n; i++) { // 0으로 초기화
        for (int j = 1; j <= n; j++) {
            d[i][j] = 0;
        }
    }

    d[1][numbers.front()] = 1; // 시작 지점은 1로 두고

    for (int i = 1; i < n; i++) { // 몇칸까지 왔는지?
        for (int j = 0; j <= 20; j++) { // 현재까지 계산 결과는 뭔지?
            if (d[i][j]) { // 길이 있으면
                if (j + numbers[i] <= 20) { // 지금까지의 계산 결과에 현재 값을 더해서 범위 안이면
                    d[i + 1][j + numbers[i]] += d[i][j]; // 다음 계산 결과에 그만큼 길이 있음
                }
                if (j - numbers[i] >= 0) { // 지금까지의 계산 결과에 현재 값을 빼서 범위 안이면
                    d[i + 1][j - numbers[i]] += d[i][j]; // 다음 계산 결과에 그만큼 길이 있음
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    // 등호로 연결되므로 마지막 - 1 에 도착하였을 때, 그 값이 마지막 값과 같은 경로
   cout << d[n - 1][numbers.back()]; 
    
}

int main() {
    input();
    solve();
    return 0;
}