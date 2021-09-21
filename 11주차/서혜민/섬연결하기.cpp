#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//구글의 도움을 많이 받았다.
//생전 처음 들어보는 크루스칼 알고리즘이 뭔지 알게되었다.
//내가 아직 모르는 알고리즘이 참 많이 있다는 걸 깨닫게되었다.

int arr[100];

bool cmp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int getParent(int i){
    if(i==arr[i]) return i;
    return arr[i]= getParent(arr[i]);
}

int solution(int n, vector<vector<int>> costs) {
    
    int answer=0;
    
    for(int i=0;i<n;i++) arr[i]=i;
    
    sort(costs.begin(),costs.end(),cmp);
    
    for(int i=0;i<costs.size();i++){
        int start=getParent(costs[i][0]);
        int end=getParent(costs[i][1]);
        int cost=costs[i][2];
        
        if(start!=end){
            answer+=cost;
            arr[end]=start;
        }
    }
    return answer;
}
