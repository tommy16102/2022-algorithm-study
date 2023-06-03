/*******************************************************************
Algorithm Study
Baekjoon 21314 민겸 수
2023/06/03 이호준
# 아이디어
1. 구현. 그리디
*******************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getMax(string input){
    string answer = "";
    vector<char> temp;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == 'M')
            temp.push_back(input[i]);
        else{
            string current = "5";
            for(int a = temp.size() - 1; a >= 0; --a){
                current += "0";
            }
            answer += current;
            temp.clear();
        }
    }
    if(!temp.empty()){
        for(int i = 0; i < temp.size(); ++i){
            answer += "1";
        }
    }
    return answer;
}

string getMin(string input){
    string answer = "";
    vector<char> temp;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == 'M')
            temp.push_back(input[i]);
        else{
            if(temp.size() > 1){
                answer += "1";
                for(int a = 1; a < temp.size(); a++)
                    answer += "0";
            }else{
                for(int a = 0; a < temp.size(); a++)
                    answer += "1";
            }
            answer += "5";
            temp.clear();
        }
    }
    if(!temp.empty()){
        answer += "1";
        for(int i = 1; i < temp.size(); ++i){
            answer += "0";
        }
    }

    return answer;
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    cout << getMax(input) << "\n";
    cout << getMin(input) << "\n";

    return 0;
}