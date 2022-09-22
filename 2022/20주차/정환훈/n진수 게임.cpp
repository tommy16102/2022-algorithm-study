#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toKBase(int n, int k){
    int t = n;
    string ret = "";
    if(n == 0) return "0";
    
    while(t > 0){
        int r = t%k;
        if(r <= 9)
            ret += to_string(r);
        else{
            switch(r){
                case 10:
                    ret += "A";
                    break;
                case 11:
                    ret += "B";
                    break;
                case 12:
                    ret += "C";
                    break;
                case 13:
                    ret += "D";
                    break;
                case 14:
                    ret += "E";
                    break;
                case 15:
                    ret += "F";
                    break;
            }
        }
        t /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(int n, int t, int m, int p) {        
    string answer = "";
    string str = "";
    for(int i=0;i<=m*t;i++){
        str += toKBase(i, n);
    }
    
    for(int i=0;i<str.size();i++){
        if(answer.size() == t)
            break;
        if(i%m == p-1){
            answer += str[i];
        }
    }
    
    return answer;
}
