#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.07.19 서혜민

1. priorities벡터 내의 어디에 위치했는지 알려주는 인덱스와, 중요도를 짝으로 해 벡터에 넣어준다.
2. 인덱스 0에 위치한 문서를 기준으로 나머지 문서가 모두 중요도가 낮다면 이 문서는 인쇄가 될 수 있으므로,
   이 문서는 벡터에서 지워준다.
3. 만약 중요도가 높은 문서가 있다면, 이 문서는 벡터에서 지우고 새롭게 푸시를 해줘, 가장 뒤에 있는 인덱스에
   위치하게 된다.

*/

int solution(vector<int> priorities, int location) {
    vector<pair<int, int>> v;
    for (int i = 0;i < priorities.size();i++) {
        v.push_back(make_pair(i, priorities[i]));
    }

    bool canCopy = true;
    int count = 0;
    while (!v.empty()) {
        int index = v[0].first;
        int max = v[0].second;
        canCopy = true;
        for (int i = 1;i < v.size();i++) {
            if (max < v[i].second) {
                canCopy = false;
                break;
            }
        }
        if (canCopy && index == location) {
            v.erase(v.begin());
            return ++count;
        }
        else if (canCopy) {
            count++;
        }
        else v.push_back(make_pair(index, max));
        v.erase(v.begin());
    }
}

int main() {
    cout << solution({ 1,1,9,1,1,1 }, 0);
}