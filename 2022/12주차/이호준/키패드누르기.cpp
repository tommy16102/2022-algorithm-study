#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    int left = 9;
    int right = 11;
    string answer = "";
    for(int i = 0 ; i< numbers.size(); i++){
        int current = numbers[i];
        if(current == 1 || current == 4 || current == 7){
            left = current-1;
            answer+= "L";
        }else if (current == 3 || current == 6 || current ==9){
            right = current-1;
            answer+= "R";
        }else{
            int current_index = current-1;
            if(current == 0){
                current_index = 10;
            }
            int right_distance = abs(current_index/3 - right/3) + abs(current_index%3 - right %3);
            int left_distance = abs(current_index/3 - left/3) + abs(current_index%3 - left %3);
            if(left_distance < right_distance){
                answer+="L";
                left = current_index;
            }else if(left_distance > right_distance){
                answer+="R";
                right = current_index;
            }else{
                //same
                if(hand == "right"){
                    answer+="R";
                    right = current_index;
                }else{
                    answer+="L";
                    left = current_index;
                }
            }
        }
    }
    return answer;
}