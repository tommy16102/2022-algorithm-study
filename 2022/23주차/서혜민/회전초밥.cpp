#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[3001];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, d, k, c;
    int result = 0;
    cin >> n >> d >> k >> c;

    arr[c] = 1;
    int cnt = 1;
    int l = 0, r = k - 1;

    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        v.push_back(num);
        if (i < k) {
            arr[num]++;
            if (arr[num] == 1) cnt++;
        }
    }

    for (int i = 0;i < k;i++) v.push_back(v[i]);
    while (1) {
        result = max(result, cnt);
        if (l == n) break;
        arr[v[l]]--;
        if (arr[v[l++]] == 0) cnt--;
        arr[v[++r]]++;
        if (arr[v[r]] == 1) cnt++;
    }
    cout << result;
    return 0;
}
