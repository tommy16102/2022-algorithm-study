#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210906 투포인터 : 정렬 후 앞뒤로 두고 최솟값 비교

long long n;
vector<long long> v;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }
}

void solve() {
    sort(v.begin(), v.end()); // 정렬

    int f = 0; // 앞포인터
    int b = v.size() - 1; // 뒷포인터
    long long min = abs(v[f] + v[b]); // 초깃값
    long long minA = v[f];
    long long minB = v[b];


    while (f != b) { // 두 포인터 만나기 전까지
        if (abs(v[f] + v[b]) < min) { // 현재 포인터값 최솟값 비교
            min = abs(v[f] + v[b]);
            minA = v[f];
            minB = v[b];
        }

        if (v[f] + v[b] == 0) { // 0일 시 바로 탈출
            minA = v[f];
            minB = v[b];
            break;
        }

        else if (v[f] + v[b] < 0) { // 포인터 합이 음수면 앞포인터 이동
            f++;
        }
        else if (v[f] + v[b] > 0) { // 양수면 뒷포인터 이동
            b--;
        }
    }

    if (minA < minB)
        cout << minA << " " << minB;
    else
        cout << minB << " " << minA;

}


int main() {

    input();
    solve();
    return 0;
}