#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.12 서혜민

res벡터에 작업까지 걸리는 일수를 저장한다.
처음의 값을 max로 지정한 뒤, for문을 통해서 max보다 작다면 result벡터에 그 값을 넣어주다가
max보다 큰 값을 만나면 이 값을 max로 지정한뒤, answer벡터에 현재 result벡터에 저장된 값의 수를 저장한다.

*/

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> res;
    for (int i = 0;i < progresses.size();i++) {
        int count = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            count++;
        }
        res.push_back(count);
    }
    vector<int> answer;
    vector<int> result;
    
    int max = -1;
    for (int i = 0;i < res.size();i++) {
        if (i == 0) {
            max = res[i];
        }
        else if (max < res[i]) {
            max = res[i];
            answer.push_back(result.size());
            result.clear();
        }
        result.push_back(res[i]);
        if (i == res.size() - 1) {
            answer.push_back(result.size());
        }
    }
    return answer;
   
}

int main() {
    vector<int> p = { 93, 30, 55 };
    vector<int> s = { 1, 30, 5 };
    vector<int> so = solution(p, s);
    for (int i = 0;i < so.size();i++) {
        cout << so[i] << ' ';
    }
}