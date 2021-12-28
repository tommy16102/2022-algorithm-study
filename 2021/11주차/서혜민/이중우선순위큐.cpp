#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//2021.09.19
//원소를 넣어줄 때는 넣고 나서 sort를 통해 오름차순으로 정렬, 최대값은 pop_back, 최소값은 erase를 통해 벡터에서 제거한다.


vector<int> solution(vector<string> operations) {
    vector<int> v;
    
    for(int i=0;i<operations.size();i++){
        string cmd = operations[i];
        
        if(cmd[0]=='I'){
            int num = stoi(cmd.substr(2));
            v.push_back(num);
            sort(v.begin(),v.end());
        }
        
        else{
            if(v.empty()) continue;
            if("1" == cmd.substr(2)){
                v.pop_back();
            }
            else v.erase(v.begin());
        }
        
    }
    
    if(v.empty()) return {0,0};
    else return {v.back(),v.front()};
}
