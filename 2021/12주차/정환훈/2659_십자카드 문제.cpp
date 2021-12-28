#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> watch_number; // 사용자가 입력한 숫자들
int target = 0; // 찾고자 하는 시계수
vector<int> watches; // 시계수 목록

vector<int> make_watch(int num) { // num을 시계수 자리수가 각각 담긴 int 벡터로 반환해주는 함수

    int d = num % 10;
    int c = (num / 10) % 10;
    int b = (num / 100) % 10;
    int a = (num / 1000) % 10;
    int n1 = a * 1000 + b * 100 + c * 10 + d; // 후보1
    int n2 = b * 1000 + c * 100 + d * 10 + a; // 2
    int n3 = c * 1000 + d * 100 + a * 10 + b; // 3
    int n4 = d * 1000 + a * 100 + b * 10 + c; // 4

    // 이중에서 가장 작은 친구가 시계수
    int min_a = min(n1, n2); 
    int min_b = min(n3, n4);
    int min_total = min(min_a, min_b);

    // 다시 벡터로 넣어주기 위해 자릿수 구하기
    d = min_total % 10;
    c = (min_total / 10) % 10;
    b = (min_total / 100) % 10;
    a = (min_total / 1000) % 10;


    vector<int> watch = { a,b,c,d }; // 만들어진 시계수 벡터
    return watch;
}

bool isWatch(int num) { // 해당 수가 시계수인지 판별
    // 자릿수 구하기
    int d = num % 10;
    int c = (num / 10) % 10;
    int b = (num / 100) % 10;
    int a = (num / 1000) % 10;
    if (a == 0 || b == 0 || c == 0 || d == 0) // 0 포함시 아님
        return false;
    vector<int> nv = { a,b,c,d }; // 현재 자리순
    vector<int> watch = make_watch(num); // 시계수로 만든 자리순
    for (int i = 0; i < 4; i++) {
        if (watch[i] != nv[i]) // 해당 수와 시계수로 만든 자릿수가 다를 시 false
            return false;
    }
    return true; // 통과시 true
}

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        watch_number.push_back(temp);
    }
    int n1 = watch_number[0] * 1000 + watch_number[1] * 100 + watch_number[2] * 10 + watch_number[3];
    vector<int> watchify = make_watch(n1); // 시계수로 만들기
    for (int i = 0; i < 4; i++) { // 시계수 만든 걸 4자리 수로 복원
        target *= 10;
        target += watchify[i];
    }
}


void solve() {
    for (int i = 0; i < 10000; i++) {
        if (isWatch(i)) { // 시계수이면 넣음
            watches.push_back(i);
            //cout << i << endl;
        }
    }

    for (int i = 0; i < watches.size(); i++) {
        if (target == watches[i]) { // 시계수 목록에서 사용자가 말한 시계수 찾음
            cout << i + 1;
            break;
        }
    }
}


int main() {
    input();
    solve();
    return 0;
}