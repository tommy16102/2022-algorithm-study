#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 40^7
int sale[7];
vector<vector<int>> users;
pair<int,int> ans;
vector<int> emoticons;
void go(int depth){
    if(depth == emoticons.size()){        
        int plus = 0;
        int totalSum = 0;
        for(int i=0;i<users.size();i++){
            int percent = users[i][0];
            int price = users[i][1];
            int sum = 0;
            for(int j=0;j<emoticons.size();j++){
                if(percent <= sale[j]){
                    sum += emoticons[j] * (100-sale[j]) / 100;
                }
            }
            if(price <= sum){
                plus++;
            }
            else{
                totalSum += sum;
            }
        }
        if(ans.first < plus){
            ans = {plus, totalSum};
        }
        else if(ans.first == plus){
            if(ans.second < totalSum){
                ans.second = totalSum;
            }
        }
        return;
    }
    for(int i=1;i<=4;i++){
        sale[depth] = i*10;
        go(depth+1);
    }
}

vector<int> solution(vector<vector<int>> u, vector<int> e) {
    vector<int> answer;
    users = u;
    emoticons = e;
    ans = {0, 0};
    go(0);
    return {ans.first, ans.second};
}
