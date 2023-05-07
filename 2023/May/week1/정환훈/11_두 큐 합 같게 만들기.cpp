#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> q1, vector<int> q2) {
    int answer = -2;
    long long sum1 = 0;
    long long sum2 = 0;
    deque<int> d1; deque<int> d2;
    for(auto e : q1){
        sum1 += e;
        d1.push_back(e);
    }
        
    for(auto e : q2){
        sum2 += e;
        d2.push_back(e);
    }        
    
    deque<int> t1 = d1;
    deque<int> t2 = d2;
    
    if((sum1+sum2)%2 == 1) return -1;
    int i = 0;
    do{
        if(i > 606060) return -1;
        if(sum1 == sum2) return i;
        else if(sum1 > sum2){
            int top = d1.front();
            d1.pop_front();
            d2.push_back(top);
            sum1 -= top;
            sum2 += top;
            i++;
        }
        else{
            int top = d2.front();
            d2.pop_front();
            d1.push_back(top);
            sum2 -= top;
            sum1 += top;
            i++;
        }         
    }while(true);
    return -1;
}
