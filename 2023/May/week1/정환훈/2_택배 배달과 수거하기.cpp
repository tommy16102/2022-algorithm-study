#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> del, vector<int> pick) {
    long long answer = 0;
    int d = 0;
    int p = 0;    
    //   for i in range(n-1, -1, -1):
    for(int i=n-1;i>=0;i--){
        long long cnt = 0;
        d -= del[i];
        p -= pick[i];
        while(d < 0 || p < 0){
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i+1)*2*cnt;
    }    
    return answer;    
}
