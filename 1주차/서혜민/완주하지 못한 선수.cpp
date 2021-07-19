#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.07.12 서혜민

참가자인 participant와 완주자인 completion간의 차이를 이용한 풀이법이다.
참가자가 완주를 했다면 완주자에도 그 참가자가 있을 것이다!
각각의 벡터에서 처음부터 비교를 해나가면서, 다른 사람이 나왔다면, 이 사람은 완주를 못했음을 의미하므로,
이 사람을 리턴하고,
participant는 항상 completion보다 1이 크므로 마지막까지 비교를 하면서 다른 사람이 나오지 않았다면,
이 사람이 완주를 못했음을 의미한다.

*/

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0;i < participant.size();i++) {
        if (i == participant.size() - 1 || participant[i]!=completion[i]) return participant[i];
    }
}

int main() {
    vector<string> v;
    vector<string> v1;
    v.push_back("marina");
    v.push_back("josipa");
    v.push_back("nikola");
    v.push_back("vinko");
    v.push_back("filipa");

    v1.push_back("josipa");
    v1.push_back("filipa");
    v1.push_back("marina");
    v1.push_back("nikola");

    cout<<solution(v, v1);
}