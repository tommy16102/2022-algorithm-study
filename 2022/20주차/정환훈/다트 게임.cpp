#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int value[3] = {0, 0, 0};
    vector<int> nums;
    vector<string> bonuses;
    
    for(int i=0;i<dartResult.size();i++){
        if(isdigit(dartResult[i])){
            if(dartResult[i+1] == '0'){
                nums.push_back(10);
                i++;
            }
            else{
                nums.push_back((dartResult[i] - '0'));
            }
        }
        else{
            string bonus = "";
            while(!isdigit(dartResult[i]) && i < dartResult.size()){
                bonus += dartResult[i];
                i++;
            }
            i--;
            bonuses.push_back(bonus);
        }
    }
    for(int i=0;i<3;i++){
        cout << nums[i] << " , " << bonuses[i] << endl;
    }
    
    for(int i=0;i<3;i++){
        value[i] = nums[i];
        for(int j=0;j<bonuses[i].size();j++){
            if(bonuses[i][j] == 'S'){
                value[i] = pow(value[i], 1);
            }
            else if(bonuses[i][j] == 'D'){
                value[i] = pow(value[i], 2);
            }
            else if(bonuses[i][j] == 'T'){
                value[i] = pow(value[i], 3);
            }
            else if(bonuses[i][j] == '#'){
                value[i] *= -1;
            }
            else if(bonuses[i][j] == '*'){
                if(i != 0){
                    value[i-1] *= 2;
                }
                value[i] *= 2;
            }
        }
    }
    
    answer += value[0]; answer += value[1]; answer += value[2];
    return answer;
}
