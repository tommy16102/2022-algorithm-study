#include <string>
#include <iostream>
using namespace std;

int solution(string str) {
    
    int answer = 0;
    int part = 0;
    int priorPart = 0;
    
    for (int i = 0; i < str.length() - 1; i++) {
        
        part = str[i] - '0';
        if (str[i + 1] == '0') {
            part = 10;
            i++;
        }
        
        char mult = str[i + 1];
        
        if (mult == 'D') {
            part = part * part;
        }
        else if (mult == 'T'){
            part = part * part * part;
        }
        
        answer += part;
        
        if (i + 2 < str.length()) {
            char op = str[i + 2];
            if (op == '*') {
                answer += (priorPart + part);
                part *= 2;
                i++;
            }
            else if (op == '#') {
                answer -= (2 * part);
                part *= -1;
                i++;
            }
        }
        
        priorPart = part;
        i++;
        
    }
    
    return answer;

}
