#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int calculateFee(vector<int> fees, float time){
    if(time <= fees[0]){
        return fees[1];
    }else{
        return fees[1] + ceil((time-fees[0])/fees[2]) * fees[3];
    }
}

int changeTime(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3));
    //cout << "changeTime = " << hour * 60 + minute << "\n";
    return hour * 60 + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, pair<int, int>> cars;
    vector<string> car_info;
    for(int i =0; i< records.size(); i++){
        string current_info = records[i];
        int delimiter = current_info.find(' ');
        int delimiter2 = current_info.rfind(' ');
        string time = current_info.substr(0, delimiter);
        string car_number = current_info.substr(delimiter+1, 4);
        string status = current_info.substr(delimiter2+1);
        if(cars.find(car_number)!= cars.end()){
            // 있다면
            if(cars[car_number].first==-1){
                cars[car_number].first= changeTime(time);
            }else{
                int in_time = cars[car_number].first;
                cars[car_number].second+= (changeTime(time) - in_time);
                cars[car_number].first = -1;
            }
        }else{
            cars.insert({car_number, {changeTime(time), 0}});
            car_info.push_back(car_number);
        }
    }
    
    for(auto a = cars.begin(); a != cars.end(); a++){
       // cout <<"MAP INFO = " << a->first << " " << a->second.first << " "<< a->second.second << "\n";
        if(a->second.first!=-1){
            a->second.second += (changeTime("23:59") - a->second.first);
        }
    }
    
    sort(car_info.begin(), car_info.end());
    for(int i =0; i < car_info.size() ; i++){
        answer.push_back(calculateFee(fees,cars[car_info[i]].second));
    }
    return answer;
}