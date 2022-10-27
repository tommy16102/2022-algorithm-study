/*******************************************************************
17609 회문
2022/10/27 이호준
# 아이디어
1. Two Pointer
*******************************************************************/

#include <iostream>
#include <string>

using namespace std;


int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string input_string;
        cin >> input_string;
        
        int miss_count = 0;

        // 짝, 홀
        int left = 0;
        int right = input_string.size() - 1;
        int returnLeft = 0;
        int returnRight = 0;
        bool end = false;

        while(left <= right){
            if(input_string[left] != input_string[right]){
                if(miss_count < 1){
                    miss_count++;
                    returnRight = right;
                    returnLeft = left;
                    left++;
                }else if(miss_count < 2){
                    miss_count++;
                    right = returnRight - 1;
                    left = returnLeft;
                }else {
                    end = true;
                    break;
                }
            }else{
                left++;
                right--;
            }
        }
        if(end){
            cout << 2 <<"\n";
            continue;
        }

        if(miss_count == 0){
            cout << 0 << "\n";
        }else{
            cout << 1 << "\n";
        }
    }

    return 0;
}

