#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0;i < participant.size();i++) {
        if (i == participant.size() - 1 || participant[i]!=completion[i]) return participant[i];
    }
}
/*
string solution(vector<string> participant, vector<string> completion) {
    
    for (int i = 0;i < participant.size();i++) {
        for (int j = 0;j < completion.size();j++) {
            if (participant[i] == completion[j]) {
                participant.erase(participant.begin() + i);
                completion.erase(completion.begin() + j);
                i--;
                break;
            }
        }
        if (participant.size() == 1) break;  
    }  
    return participant[0];
}
*/
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