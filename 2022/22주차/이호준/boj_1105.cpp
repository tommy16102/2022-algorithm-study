/*******************************************************************
1105 팔
2022/10/11 이호준
# 아이디어
1. Greedy
*******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string l, r;

    cin >> l >> r;

    int ans = 0;
    if (l.size() == r.size()) {
        for (int i = 0; i < l.size(); ++i) {
            if (l[i] != r[i]) break;
            if (l[i] == r[i] && l[i] == '8') ++ans;
        }
    }
    cout << ans;

    return 0;
}