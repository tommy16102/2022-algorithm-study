#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isSosu(long long int n) {
    
    if (n == 1) return false;
    
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
    
}

string makeSosu(int n, int k) {
    
    long long int x;
    
   for(int i = 1; i <= n; i++) {
       if (pow(k, i) <= n) x = i;
       else break;
   }
    
    string s = "";
    
    for (int i = x; i >= 0; i--) {
        if (n >= pow(k, i)) {
            long long int p;
            for (int j = 1; j <= k; j++) {
                if (pow(k, i) * j <= n) p = j;
                else break;
            }
            s += to_string(p);
            n -= pow(k, i) * p;
        }
        else s += '0';
    }
    
    return s;

}

int solution(int n, int k) {
    
    string num = makeSosu(n, k);
    
    int cnt = 0;
    int startIndex = 0;
    
    string partNum;
    
    while(1) {
        
        while (num[startIndex] == '0') startIndex++;
        if (startIndex >= num.length()) break;
        
        int index = num.find('0', startIndex);
        
        if (index == -1) {
        
            partNum = num.substr(startIndex);
        
            if(isSosu(stoll(partNum))) cnt++;
            
            break;
            
        }
        
        partNum = num.substr(startIndex, index - startIndex);
        
        if(isSosu(stoll(partNum))) cnt++;
        
        startIndex += (index - startIndex) + 1;
        
    }
    
    return cnt;
    
}