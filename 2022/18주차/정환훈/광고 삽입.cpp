#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int ad[360001]; // 변환된 시간 hh:mm:ss에 보고 있는 시청자의 수
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    // log 파싱해서 ad[i] 값 구하기
    for(int i=0;i<logs.size();i++){
        int logStartH = stoi(logs[i].substr(0, 2));
        int logStartM = stoi(logs[i].substr(3, 2));
        int logStartS = stoi(logs[i].substr(6, 2));

        int logEndH = stoi(logs[i].substr(9, 2));
        int logEndM = stoi(logs[i].substr(12, 2));
        int logEndS = stoi(logs[i].substr(15, 2));
        
        int logStart = logStartH * 3600 + logStartM * 60 + logStartS;
        int logEnd = logEndH * 3600 + logEndM * 60 + logEndS;
        
        // 3초~6초 시청 = ad[2], ad[3], ad[4], ad[5] ++
        for(int j=logStart;j<logEnd;j++){
            ad[j]++;
        }
    }
    
            
    int playTimeH = stoi(play_time.substr(0, 2));
    int playTimeM = stoi(play_time.substr(3, 2));
    int playTimeS = stoi(play_time.substr(6, 2));
    int adTimeH = stoi(adv_time.substr(0, 2));
    int adTimeM = stoi(adv_time.substr(3, 2));
    int adTimeS = stoi(adv_time.substr(6, 2));
    
    int playTime = playTimeH * 3600 + playTimeM * 60 + playTimeS;
    int adTime = adTimeH * 3600 + adTimeM * 60 + adTimeS;
    
    long long sum = 0;
    long long maxSum = 0;
    queue<int> q;
    
    // 초기 0초에 광고 삽입했다는 가정
    for(int i=0;i<adTime;i++){
        sum += ad[i];
        q.push(ad[i]);
    }
    
    maxSum = sum;
    int index = 0;
    // 0~adTime, 1~adTime+1, 2~adTime+2 이렇게 구하다가 maxSum 나오면 그 때 index 기억
    for(int i=adTime;i<playTime;i++){
        sum -= q.front();
        q.pop();
        sum += ad[i];
        q.push(ad[i]);
        if(maxSum < sum){
            maxSum = sum;
            index = i - adTime + 1;
        }
    }
    
    // index 시간으로 변환
    int s = index % 60;
    index /= 60;
    int m = index % 60;
    index /= 60;
    int h = index;
    
    if(h < 10)
        answer += "0";
    answer += to_string(h);
    answer += ":";
    if(m < 10)
        answer += "0";
    answer += to_string(m);
    answer += ":";
    if(s < 10)
        answer += "0";
    answer += to_string(s);
    return answer;
}