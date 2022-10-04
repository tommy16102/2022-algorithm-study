#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int> v;
    int n, m, l, num;

    int start, end, mid, ans = 1000;
    cin >> n >> m >> l;

    v.push_back(0);
    v.push_back(l);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    start = 1;
    end = l - 1;

    while (end >= start) {
        int rest = 0;
        mid = (start + end) / 2;
        for (int i = 1; i < v.size(); i++) {
            int dist = v[i] - v[i - 1];
            int cnt = dist / mid;
            if (cnt > 0) {
                if (dist % mid == 0) rest += cnt - 1;
                else rest += cnt;
            }
        }
        if (rest > m) start = mid + 1;
        else {
            end = mid - 1;
            ans = min(mid, ans);
        }
    }
    cout << ans;
    
    return 0;
}
