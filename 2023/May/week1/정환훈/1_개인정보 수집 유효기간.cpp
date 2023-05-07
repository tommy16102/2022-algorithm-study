#include <string>
#include <vector>
#include <map>
using namespace std;

int dtoi(string date){
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8);
    return stoi(year)*12*28 + stoi(month)*28 + stoi(day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;
    for(auto term : terms){
        m[term[0]] = stoi(term.substr(2));
    }
    int todayI = dtoi(today);
    for(int j=0;j<privacies.size();j++){
        string p = privacies[j];
        string date = p.substr(0, 10);
        int i = dtoi(date) + m[p[11]] * 28;
        if(todayI >= i) answer.push_back(j+1);
    }
    return answer;
}
