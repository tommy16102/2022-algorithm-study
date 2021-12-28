#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
2021.09.22
진입 지점, 진출 지점을 기준으로 정렬을 한 뒤, 카메라 위치를 가장 진입 지점이 앞인 원소의 진출지점으로 설정한 뒤,
그 다음원소부터 해당 원소의 진입지점과 진출지점이 카메라위치보다 이전, 즉 이전의 진입 진출 지점에 포함이 되면 해당 원소의 진출지점을 카메라위치로 바꾼다.
하지만 진입지점이 카메라 위치보다 뒤에 있을 때는 해당 카메라는 만날 수 없으므로, 새롭게 카메라 위치를 해당 원소의 진출지점으로 설정한다.
*/

bool comp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1]<b[1];
    else return a[0]<b[0];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end(),comp);
    
    int cam = routes[0][1];
    int ans=1;
    
    for(int i=1;i<routes.size();i++){
        if(routes[i][0]<cam){
            if(routes[i][1]<cam){
                cam=routes[i][1];
            }
        }
        if(routes[i][0]>cam){
            ans++;
            cam=routes[i][1];
        }
    }
    
    return ans;
}
