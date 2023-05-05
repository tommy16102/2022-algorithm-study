/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT 표 병합
2023/05/05 이호준
# 아이디어
1. Union-Find 구현
*******************************************************************/
#include <string>
#include <vector>

#define MAPSIZE 50

using namespace std;

string map[51][51];

int mapSet[2501];

int find(int x){
    if(x == mapSet[x])
        return x;
    return mapSet[x] = find(mapSet[x]);
}

void unionCell(int x, int y, string mergeValue){
    
    if(x > y){
        int temp = y;
        y = x;
        x = temp;
    }
    mapSet[y] = x;
    map[x / MAPSIZE][x % MAPSIZE] = mergeValue;
}

void merge(int r1, int c1, int r2, int c2){
    int firstCellGroup = find(r1 * MAPSIZE + c1);
    int secondCellGroup = find(r2 * MAPSIZE + c2);
    
    if(firstCellGroup == secondCellGroup)
        return;
    
    int firstCell_r = firstCellGroup / MAPSIZE;
    int firstCell_c = firstCellGroup % MAPSIZE;
    int secondCell_r = secondCellGroup / MAPSIZE;
    int secondCell_c = secondCellGroup % MAPSIZE;
    string mergeValue = map[firstCell_r][firstCell_c];
    
    if(mergeValue == ""){
        mergeValue = map[secondCell_r][secondCell_c];
    }

    unionCell(firstCellGroup, secondCellGroup, mergeValue);
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i = 0; i <= 2500; i++)
        mapSet[i] = i;
    
    for(string command : commands){
        int opIndex = command.find(' ');
        int idx = command.find(' ', opIndex + 1);
        int idx2 = command.find(' ', idx + 1);
        
        string operation = command.substr(0, opIndex);
        if(operation == "UPDATE"){
            if(idx2 == string::npos){
                string value1 = command.substr(opIndex + 1, idx - opIndex -1);
                string value2 = command.substr(idx + 1 , idx2 - idx - 1);
                for(int i = 0; i < 50; i++){
                    for(int j = 0; j < 50; j++){
                        if(map[i][j] == value1)
                            map[i][j] = value2;
                    }
                }
            }else{
                int r = stoi(command.substr(opIndex + 1, idx - opIndex - 1)) - 1;
                int c = stoi(command.substr(idx + 1, idx2 - idx - 1)) - 1;
                string value = command.substr(idx2 + 1);
                int cell = find(r * MAPSIZE + c);
                map[cell / MAPSIZE][cell % MAPSIZE] = value;
            }
        }else if(operation == "MERGE"){
            int r = stoi(command.substr(opIndex + 1, idx - opIndex - 1)) - 1;
            int c = stoi(command.substr(idx + 1, idx2 - idx - 1)) - 1;
            int idx3 = command.find(' ', idx2 + 1);
            int r2 = stoi(command.substr(idx2 + 1, idx3 - idx2 - 1)) - 1;
            int c2 = stoi(command.substr(idx3 + 1)) - 1;
            merge(r, c, r2, c2);
        }else if(operation == "UNMERGE"){
            int r = stoi(command.substr(opIndex + 1, idx - opIndex - 1)) - 1;
            int c = stoi(command.substr(idx + 1, idx2 - idx - 1)) - 1;
            int cell = find(r * MAPSIZE + c);
            string unmergeValue = map[cell / MAPSIZE][cell % MAPSIZE];
            
            for(int i = 2500; i >= 0; i--){
                if(find(i) == cell){
                    mapSet[i] = i;
                    map[i / MAPSIZE][i % MAPSIZE] = "";
                }
            }
            map[r][c] = unmergeValue;
        }else{
            int r = stoi(command.substr(opIndex + 1, idx - opIndex - 1)) - 1;
            int c = stoi(command.substr(idx + 1, idx2 - idx - 1)) - 1;
            int cell = find(r * MAPSIZE + c);
            if(map[cell / MAPSIZE][cell % MAPSIZE] == "")
                answer.push_back("EMPTY");
            else
                answer.push_back(map[cell / MAPSIZE][cell % MAPSIZE]);
        }
        
    }
    
    return answer;
}