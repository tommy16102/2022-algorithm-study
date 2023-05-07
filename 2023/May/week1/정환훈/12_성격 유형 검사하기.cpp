#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> m;
    string ans = "";
    for(int i=0;i<survey.size();i++){
        int c = choices[i];
        char a = survey[i][0]; char b = survey[i][1];
        if(c >= 1 && c <= 3){
            m[a] += 4 - c;
        }
        else if(c >= 5 && c <= 7){
            m[b] += c - 4;
        }
    }
    if(m['T'] > m['R']) ans += "T";
    else ans += "R";
    if(m['F'] > m['C']) ans += "F";
    else ans += "C";
    if(m['M'] > m['J']) ans += "M";
    else ans += "J";
    if(m['N'] > m['A']) ans += "N";
    else ans += "A";
    return ans;
}
