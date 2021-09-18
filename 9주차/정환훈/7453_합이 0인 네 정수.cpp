#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int n;

vector<long long> a;
vector<long long> b;
vector<long long> c;
vector<long long> d;
vector<long long> ab; // 가능한 ab의 모든 합
vector<long long> cd; // 가능한 cd의 모든 합

long long answer = 0;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int va; int vb; int vc; int vd;
        cin >> va >> vb >> vc >> vd;
        a.push_back(va);
        b.push_back(vb);
        c.push_back(vc);
        d.push_back(vd); 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
}

void solve() {
    sort(ab.begin(), ab.end()); // 가능한 ab의 합들이 정렬
    sort(cd.begin(), cd.end()); // cd ..

    int f = 0; // ab의 앞
    int b = ab.size() - 1; // cd의 뒤
    while (f < ab.size() && b >= 0) { // 범위 안 벗어나는 이상
        long long sum = ab[f] + cd[b]; // ab의 앞포인터 + cd의 뒷포인터
        if (sum == 0) { // 정답인 경우
            long long abCount = 0; // ab의 중복 값 개수
            long long cdCount = 0; // cd의 중복 값 개수
            long long abSum = ab[f]; // ab의 합
            long long cdSum = cd[b]; // cd의 합
            while (abSum == ab[f]) { // 중복 값 개수 세기
                abCount++;
                f++;
                if (f == ab.size()) break; // 포인터가 끝 도달 시
            }
            while (cdSum == cd[b]) { // cd의 경우에도
                cdCount++;
                b--;
                if (b == -1) break; // 포인터가 끝 도달 시 
            }

            answer += abCount * cdCount; // 경우의 수
        }

        else if (sum > 0) // 양수면 양수(cd포인터) 감소
            b--;
        else if (sum < 0)  // 음수면 음수(ab포인터) 증가
            f++;
    }

    cout << answer;
}


int main() {

    input();
    solve();
    return 0;
}