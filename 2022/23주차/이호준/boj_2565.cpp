/*******************************************************************
2565 전깃줄
2022/10/17 이호준
# 아이디어
1.DP
2.가장 긴 증가하는 부분순열.
*******************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[101];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<pair<int, int>> lines;
    cin >> n;
    lines.push_back({ 0,0 });
    for (int i = 1; i <= n;i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({ a,b });

    }
    sort(lines.begin(),lines.end());
    dp[1] = 1;
    int answer = 100;

    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (lines[i].second > lines[j].second) {
                if(dp[i] <= dp[j]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        answer = min(answer, n - dp[i]);
    }

    cout << answer;
    return 0;
}