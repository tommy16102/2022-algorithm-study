#include <string>
#include <vector>
#include <stack>
using namespace std;

/*

2022.2.26

vector와 번호 별 삭제 여부를 저장하는 bool 형 배열 => 효율성 6~10 케이스 시간초과
이후, set을 통해 삭제 여부 저장 배열없이, iterator로 유사 연결리스트 => 정확 2 케이스 core dumped
vector를 통해 prev는 이전, next는 다음 노드의 번호를 저장하도록 연결리스트 구현.

*/

string solution(int n, int k, vector<string> cmd) {
    
    int now = k;
    vector<int> prev;
    vector<int> next;
    stack<int> remove;

    for (int i = 0; i < n + 1; i++) {
        prev.push_back(i - 1);
        next.push_back(i + 1);
    }
    now++;

    for (int i = 0; i < cmd.size(); i++) {
        char c = cmd[i][0];
        
        if (c == 'U') {
            int num = stoi(cmd[i].substr(2));
            while(num--) now = prev[now];
        }
        else if (c == 'D') {
            int num = stoi(cmd[i].substr(2));
            while(num--) now = next[now];
        }
        else if (c == 'C') {
            remove.push(now);
            next[prev[now]] = next[now];
            prev[next[now]] = prev[now];

            if (next[now] == n + 1) now = prev[now];
            else now = next[now];
        }
        else if (c == 'Z') {
            int index = remove.top();
            next[prev[index]] = index;
            prev[next[index]] = index;
            remove.pop();
        }
    }

    string answer(n, 'O');

    while (!remove.empty()) {
        answer[remove.top() - 1] = 'X';
        remove.pop();
    }

    return answer;
}
