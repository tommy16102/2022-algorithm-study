#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct file{
    int index;
    string originhead;
    string head;
    int number;
    string originnum;
    string tail;    
};

bool compare(const file& f1, const file& f2){
    
    if(f1.head == f2.head){
        if(f1.number == f2.number){
            return f1.index < f2.index;
        }
        else return f1.number < f2.number;
    }
    else return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<string> heads;
    vector<int> numbers;
    vector<string> tails;
    vector<file> fs;
    for(int i=0;i<files.size();i++){
        string fileStr = files[i];
        string head = "";
        string number = "";
        string tail = "";
        
        bool start = false;
        
        int j = 0;
        while(j < fileStr.size() && !isdigit(fileStr[j])){
            head += fileStr[j];
            j++;
        }
        
        while(j < fileStr.size() && isdigit(fileStr[j])){
            number += fileStr[j];
            j++;
            if(number.size() == 5) break;
        }
        
        tail = fileStr.substr(j);
        
        //cout << head << " " << number << " " << tail << endl;
        file f;
        f.originhead = head;
        string temp = "";
        for(int i=0;i<head.size();i++){
            temp += toupper(head[i]);
        }
        f.head = temp;
        f.tail = tail;
        f.originnum = number;
        f.number = stoi(number);
        f.index = i;
        fs.push_back(f);        
    }                
    sort(fs.begin(), fs.end(), compare);
    
    for(int i=0;i<fs.size();i++){
        answer.push_back(fs[i].originhead + fs[i].originnum + fs[i].tail);
    }
    
    return answer;
}
