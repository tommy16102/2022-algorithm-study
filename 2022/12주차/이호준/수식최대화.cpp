#include <string>
#include <vector>

using namespace std;

vector<char> op;
vector<long long> values;

vector<char> priority[6] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '-', '+'},
    {'*', '+', '-'}
};

void calculate(vector<char> priority, vector<char> op, vector<long long> values, long long& answer);
    
void splitOpAndValue(string expression);
long long getValue(char op, long long a, long long b);

long long solution(string expression) {
    long long answer = 0;
    // 1. 숫자와 연산자 각 vector로 나누기
    splitOpAndValue(expression);
    // 2. 우선순위 순열을 통해서 값 연산 (6가지 경우의 수)
    long long temp;
    calculate(vector<char>({'+', '-', '*'}), op, values, answer);
    calculate(vector<char>({'+', '*', '-'}), op, values, answer);
    calculate(vector<char>({'-', '+', '*'}), op, values, answer);
    calculate(vector<char>({'-', '*', '+'}), op, values, answer);
    calculate(vector<char>({'*', '-', '+'}), op, values, answer);
    calculate(vector<char>({'*', '+', '-'}), op, values, answer);
    //calculate(priority[0], op, values, answer);
    //calculate(priority[1], op, values, answer);
    //calculate(priority[2], op, values, answer);
    //calculate(priority[3], op, values, answer);
    //calculate(priority[4], op, values, answer);
    //calculate(priority[5], op, values, answer);
    return answer;
}

void splitOpAndValue(string expression){
    string number = "";
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] >= '0' && expression[i] <= '9'){
            number += expression[i];
        }else{
            // operator
            op.push_back(expression[i]);
            values.push_back(stoll(number));
            number = "";
        }
    }
    if(number!=""){
        values.push_back(stoll(number));
    }
}
void calculate(vector<char> priority, vector<char> op, vector<long long> values, long long& answer){
    for(int i = 0; i<3; i++){
        if(values.size()==1){
            break;
        }
        char current_op = priority[i];
        for(int a = 0; a < op.size(); a++){
            if(op[a] == current_op){
                values[a] = getValue(current_op, values[a], values[a+1]);
                op.erase(op.begin()+a);
                a++;
                values.erase(values.begin()+a);
                a--;
                a--;
            }
        }
    }
    if(values[0] < 0){
        values[0] = -values[0];
    }
    if(answer < values[0]){
        answer = values[0];
    }
}

long long getValue(char op, long long a, long long b){
    if(op == '+'){
        return a + b;
    }else if (op == '-'){
        return a - b;
    }else if (op == '*'){
        return a * b;
    }
}