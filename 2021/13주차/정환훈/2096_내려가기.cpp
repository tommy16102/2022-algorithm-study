#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int px[3];
int nx[3] = { 0,0,0 };
int lx[3] = { 0,0,0 };

int l_now[3]; // 최솟값 구할때 현재 값
int m_now[3]; // 최댓값 구할때 현재 값
int n_max[3] = { 0, }; // 다음 최솟값들
int n_min[3] = { 0, }; // 다음 최댓값들

int get_max(int a, int b, int c) {
    int r1 = max(a, b);
    return max(r1, c);
}
int get_min(int a, int b, int c) {
    int r1 = min(a, b);
    return min(r1, c);
}

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
}

void solve() {


    for (int i = 0; i < n; i++) {
        cin >> m_now[0] >> m_now[1] >> m_now[2];
        l_now[0] = m_now[0];
        l_now[1] = m_now[1];
        l_now[2] = m_now[2];

        l_now[0] += n_min[0];
        l_now[1] += n_min[1];
        l_now[2] += n_min[2];

        m_now[0] += n_max[0];
        m_now[1] += n_max[1];
        m_now[2] += n_max[2];

        n_max[0] = max(m_now[0], m_now[1]);
        n_max[1] = get_max(m_now[0], m_now[1], m_now[2]);
        n_max[2] = max(m_now[1], m_now[2]); 

        n_min[0] = min(l_now[0], l_now[1]);
        n_min[1] = get_min(l_now[0], l_now[1], l_now[2]);
        n_min[2] = min(l_now[1], l_now[2]);


    }

    //for (int i = 0; i < n; i++) {
    //    cin >> px[0] >> px[1] >> px[2];

    //    nx[0] += max(px[0], px[1]);
    //    nx[1] += get_max(px[0], px[1], px[2]);
    //    nx[2] += max(px[1], px[2]);

    //    lx[0] += min(px[0], px[1]);
    //    lx[1] += get_min(px[0], px[1], px[2]);
    //    lx[2] += min(px[1], px[2]);


    //    cout << " max : " << nx[0] << " " << nx[1] << " " << nx[2] << endl;
    //    cout << " Min : " << lx[0] << " " << lx[1] << " " << lx[2] << endl;

    //}

    int r1 = get_max(m_now[0], m_now[1], m_now[2]);
    int r2 = get_min(n_min[0], n_min[1], n_min[2]);

    cout << r1 << " " << r2;
}


int main() {
    input();
    solve();
    return 0;
}