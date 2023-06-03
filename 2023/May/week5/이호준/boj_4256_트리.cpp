/*******************************************************************
Algorithm Study
Baekjoon 4256 트리
2023/06/03 이호준
# 아이디어
1. 트리.. 어렵다
풀이를 보고 이해했다.
inorder 는 트리를 left와 right로 나눌 수 있다.
pre 오더는 루트 -> 레프트 롸이트 로 루트부터 접근
이를 이용해 postorder의 left -> right -> root 의 접근을 시도한다.
현재 노드에서 다음 루트 노드는 pos + 1 (pre에서 left는 +1이다)
그리고 right는 left 트리의 전체 노드의 수로 연산할 수 있다.
*******************************************************************/

#include <vector>
#include <iostream>

using namespace std;

int T;
int N;
vector<int> v_pre;
vector<int> v_in;

void post_order(int start, int end, int pos){
    for (int i = start; i < end; ++i) {
        if(v_in[i] == v_pre[pos]){
            post_order(start, i, pos + 1);
            post_order(i+1, end, pos + 1 + i - start);
            cout << v_pre[pos] << ' ';
        }
    }
}

int main(void) {
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> N;
        v_pre = vector<int>(N);
        v_in = vector<int>(N);

        for (int j = 0; j < N; ++j) {
            cin >> v_pre[j];
        }
        for (int j = 0; j < N; ++j) {
            cin >> v_in[j];
        }
        post_order(0, N, 0); cout <<"\n";
    }
}