#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

2021.09.20

요청된 시간/요청된 시간이 같다면 작업 시간을 기준으로 오름차순으로 정렬한 jobs 벡터에서
0으로 초기화한 현재 시간인 time보다 이전인 요청시간을 가진 작업 있다면 time에 해당 작업의 시간을 더해주고,
누적된 작업의 시간-요청 시간을 저장하는 sum에 이를 더한 뒤, 벡터에서 지워준다.
하지만 time 보다 이전인 작업이 없다면 어떠한 작업도 수행될 수 없으므로, 현재 시간을 늘려줘야 한다.

*/

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1]<b[1];
    else a[0]<b[0];
}

int solution(vector<vector<int>> jobs) {
    
    int time = 0;
    int sum = 0;
    int size = jobs.size();

    sort(jobs.begin(),jobs.end(),cmp);
    
    while(jobs.size()>0){
        
        bool canGo = false;
        
        for(int i=0;i<jobs.size();i++){
            if(jobs[i][0]<=time){
                sum+=time+jobs[i][1]-jobs[i][0];
                time+=jobs[i][1];
                jobs.erase(jobs.begin()+i);
                canGo=true;
                break;
            }
        }
        
        if(!canGo) time++;
    }
    
    return sum / size;
}
