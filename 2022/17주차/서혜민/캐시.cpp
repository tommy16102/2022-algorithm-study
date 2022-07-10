#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

// cacheSize가 0일 때, 예외 존재!!

deque<string> dq;

int solution(int cacheSize, vector<string> cities) {

    int answer = 0;
    
    for (int i = 0; i < cities.size(); i++) {
        
        string city = cities[i];
        for (int j = 0; j < city.length(); j++) {
            if (city[j] >= 'A' && city[j] <= 'Z') city[j] += 32;
        }
        
        bool haveCity = false;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == city) {
                dq.erase(dq.begin() + j);
                dq.push_back(city);
                answer++;
                haveCity = true;
            } 
            if (haveCity) break;      
        }
        
        if (!haveCity) {
            if (dq.size() >= cacheSize) {
                if (cacheSize == 0) answer += 5;
                else {
                    dq.pop_front();
                    answer += 5;
                    dq.push_back(city);
                }
            }
            else {
                answer += 5;
                dq.push_back(city);
            }
        }
    }
    
    return answer;
}
