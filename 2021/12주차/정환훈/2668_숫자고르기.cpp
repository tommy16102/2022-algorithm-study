#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int sequel[101]; // 순서대로 1.2.3.4.5 담겨있는 배열
int rd[101]; // 사용자가 인풋한대로 랜덤하게 담겨있는 배열
int s; // 크기, 사이즈
vector<int> results; // 결과

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s; // 사이즈

    for (int i = 1; i <= s; i++) { // 배열들 자리에 넣기
        sequel[i] = i;
        int temp;
        cin >> temp;
        rd[i] = temp;
    }

}

void can_cycle(int id) { // 각 id에서 시작해서 사이클이 이뤄지는지 확인하는 함수인데 반복문으로 구현
    vector<int> lists; // 사이클 번호들 담겨있음
    bool v[101] = { false, }; // 여기 왔나?
    v[id] = true; // 지금 왔으니까
    int next_id = rd[id]; // 다음 갈 인덱스는 사용자 인풋의 배열 값
    int next = rd[next_id];
    lists.push_back(id);

    while (next != id && v[next_id] == false) { // next == id와 같아지면 사이클이 이뤄짐, 이미 간 곳 다시 방문하려하면 사이클 안이뤄짐
        int now_id = next_id; // 지금 밟고 있는 인덱스
        v[now_id] = true; // 방문 처리
        next_id = rd[now_id]; // 다음 인덱스
        next = rd[next_id]; // 다음 값
        lists.push_back(next); // 다음 값들을 번호들에 넣음
    }

    if (next == id) { // 사이클 이뤄졌다고 판단하면
        for (int i = 0; i < lists.size(); i++) {
            results.push_back(lists[i]); // result 에다가 다 넣어줌
        }
    }
}

void solve() {

    for (int i = 1; i <= s; i++) { // 각각의 인덱스에서 사이클 이뤄지는지 테스트
        can_cycle(i);
    }

    sort(results.begin(), results.end()); // 결과 정렬
    results.erase(unique(results.begin(), results.end()), results.end()); // 결과 중복 제거
    cout << results.size() << endl; // 결과 크기
    for (int i = 0; i < results.size(); i++) { // 결과 작은순대로 출력
        cout << results[i] << endl;
    }

}


int main() {
    input();
    solve();
    return 0;
}