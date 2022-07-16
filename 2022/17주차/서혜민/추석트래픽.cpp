#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<double,double>> v;

int solution(vector<string> lines) {
    
    for (string line : lines) {
        
        int h = stoi(line.substr(11, 2)) * 60 * 60 * 1000;
        int m = stoi(line.substr(14, 2)) * 60 * 1000;
        int s = stoi(line.substr(17, 2)) * 1000;
        double ms = stod(line.substr(20, 3));
        
        double endTime = h + m + s + ms;
        
        double sec = stod(line.substr(24, line.length() - 25)) * 1000;
        
        double startTime = endTime - sec + 1;
        
        v.push_back({startTime, endTime});
        
    }
    
    int answer = 0;
    
    for (int i = 0; i < v.size(); i++) {
        
        double endTime = v[i].second;
        int cnt = 1;
        bool extended = false;
        
        for (int j = i + 1; j < v.size(); j++) {
            
            double startTime = v[j].first;
            
            if (startTime <= endTime) cnt++;
            else if (!extended) {
                extended = true;
                endTime += 999;
                if (startTime <= endTime) cnt++;
            }
            
        }
        
        answer = max(answer, cnt);
        
    }
    
    return answer;
}
