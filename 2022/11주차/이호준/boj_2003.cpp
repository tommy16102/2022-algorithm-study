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