#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxDif = 0;
int cnt = 0;
vector<int> org(11);
vector<int> v(11, 0);
vector<int> ans(11);

void makeScore(int index, int n) {
    
    if(index > 11 || n > cnt) return;
    if(n == cnt) {
        
        int A = 0;
        int B = 0;
        
        for (int i = 0; i < 11; i++) {
            if (org[i] >= v[i] && org[i] > 0) A += (10 - i);
            else if (v[i] > org[i] && v[i] > 0 ) B += (10 - i);
        }
        
        if ((B - A) > maxDif) {
            maxDif = B - A;
            ans = v;
        }
        
        if ((B - A) == maxDif) {
            for (int i = 10; i >= 0; i--) {
                if (ans[i] > v[i]) break;
                else if (ans[i] < v[i]) {
                    ans = v;
                    break;
                }
            }
        }
        
        return;
        
    }
    
    for (int i = index; i < 11; i++) {
        
        int val = org[i] + 1;
        if (val + n > cnt) val = cnt - n;
        
        v[i] = val;
        makeScore(i + 1, val + n);
        v[i] = 0;
        
    }
    
}

vector<int> solution(int n, vector<int> info) {
    
    for(int i = 0; i < info.size(); i++) org[i] = info[i];
    cnt = n;
    
    makeScore(0, 0);
    
    if (maxDif == 0) return { -1 };
    else return ans;

}
