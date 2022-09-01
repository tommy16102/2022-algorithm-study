/*******************************************************************
Algorithm Study
2021 Kakao Blind
광고삽입 level 3
2022/09/01 이호준
# 아이디어
1. 시간을 sec 치환하여 보는 판단 (연산의 편의성)
2. sliding window algorithm
*******************************************************************/
#include <string>
#include <vector>

using namespace std;

int arr[360010]; 

int time_to_sec(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    
    return 3600*h + 60*m + s;
}

string time_tostring(int t) {
    string ret = "";
    
    int h = t / 3600; t %= 3600;
    int m = t / 60;
    int s = t % 60;
    
    ret += h >= 10 ? to_string(h) : ("0" + to_string(h));
    ret += ":";
    ret += m >= 10 ? to_string(m) : ("0" + to_string(m));
    ret += ":";
    ret += s >= 10 ? to_string(s) : ("0" + to_string(s));
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int END = time_to_sec(play_time);
    int ADV = time_to_sec(adv_time);
    
    int answer = 0;
    long long sum = 0;
    
    for(string log: logs) {
        int t1 = time_to_sec(log.substr(0, 8));
        int t2 = time_to_sec(log.substr(9));
        
        for(int i= t1; i < t2; ++i) arr[i]++;
    }
    
    for(int i=0; i<ADV; ++i) sum += arr[i];

    long long max_sum = sum;
    // sliding window
    for(int i=ADV; i<END; ++i) {
        sum -= arr[i-ADV];
        sum += arr[i];
        
        if(sum > max_sum) {
            max_sum = sum;
            answer = i - ADV + 1;
        }
    }
    
    return time_tostring(answer);
}