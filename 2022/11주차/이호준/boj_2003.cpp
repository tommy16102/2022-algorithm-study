/*******************************************************************
Algorithm Study
Baekjoon OJ Two pointer
2003 수들의 합 2
2022/04/05 이호준
# 아이디어
1. 왼쪽 오른쪽 포인터 2개를 가지고 알고리즘을 수행하면 된다.

오른쪽 포인터가 끝에 도달한다면 종료시점이다.
=> 왜냐하면 이전까지 합을 다 했는데도 도달하지 못했거나 도달한 상태이므로
더이상 체크할 상태가 없는 것이다.
-> 이점을 간과하고 다시 앞으로 돌아가는 코드를 작성했었다.

투 포인터의 의미를 명확히 알게 되었다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> inputs(n, 0);

    for(int i=0;i <n; i++){
        cin >> inputs[i];
    }

    int head = 0;
    int tail = 0;

    int current = 0;
    int answer = 0;

    // 앞에서 부터 체크
    // 값이 더 작으면 뒤에값 붙이기
    while(1){

        if(tail == n-1){
            if(current == m)
                answer++;
            if(head < n-1){
                current = inputs[++head];
                tail = head;
                continue;
            }else{
                break;
            }
        }

        if(head>=n-1){
            if(current == m)
                answer++;
            break;
        }

        if(current==m){
            answer++;
            current=inputs[++head];
            tail=head;
        }else if (current < m){
            current+=inputs[++tail];
        }else {
            current-=inputs[head++];
            if(head>tail){
                tail = head;
                current+=inputs[head];
            }
        }
    }
    cout << answer;

    return 0;
}

// 투포인터 올바른 풀이
// 소요시간 : 0MS
// #include <iostream>

// using namespace std;

// const int MAX = 10000;
// int arr[MAX];

// int main(void){

//         ios_base::sync_with_stdio(0); cin.tie(0);

//         int N, M;

//         cin >> N >> M;

//         for (int i = 0; i < N; i++)
//             cin >> arr[i];

//          int low = 0, high = 0; int sum = arr[0]; int result = 0;

//         //투 포인터 알고리즘 적용

//         while(low <= high && high < N){

//                  if (sum < M)
//                     sum += arr[++high];
//                 else if (sum == M){
//                     result++;
//                     sum += arr[++high];
//                 }else if (sum > M){
//                     sum -= arr[low++];
//                     if (low > high && low < N){
//                         high = low;
//                         sum = arr[low];
//                     }
//                  }
//         }
//         cout << result << "\n";

//         return 0;

// }
