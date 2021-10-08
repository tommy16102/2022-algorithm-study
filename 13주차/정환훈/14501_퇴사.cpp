#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int times[100]; // 소요 시간
int rewards[100]; // 받는 돈
int d[21];
void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tt;
        int rt;
        cin >> tt >> rt;
        times[i] = tt;
        rewards[i] = rt;
        d[i] = 0;
    }
}

void dfs(int start, int depth, int end, int money, int id) {
    if (depth == end + 1) { // end날까지의 일과가 끝남
        d[id] = max(d[id], money); // 현재 id에 값 대입
        return;
    }

    dfs(start, depth + 1, end, money, id); // 일 안하고 다음날로 dfs
    if (depth + times[depth] <= end + 1) { // 일 가능하면 일 하고
        if (times[depth] == 0) // 이거 depth가 범위가 넘어간 경우는 빼고
            return;
        dfs(start, depth + times[depth], end, money + rewards[depth], id); // 일해서 그만큼 시간+돈 경과해서 dfs
    }

}


void solve() {


    for (int i = 1; i <= n; i++) {
        dfs(1, 1, i, d[i], i);
    }

    //for (int i = 1; i <= n + 1; i++) {
    //    cout << i << " : " << d[i] << endl;
    //}

    cout << d[n]; // n날까지의 수익 최댓값
}


int main() {
    input();
    solve();
    return 0;
}