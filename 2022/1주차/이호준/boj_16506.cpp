/*******************************************************************
Algorithm Study
Baekjoon OJ DP
16506 CPU
2022/01/04 이호준
# 아이디어
1. 문제에 주어진 대로 parsing하여 machine code로 바꾸는 구현문제
bitset에 대해서 공부했다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string input;
        string machinecode = "";
        getline(cin, input);
        string opcode = input.substr(0, input.find(" "));
        input = input.substr(input.find(" ") + 1);
        bool is_format2 = false;
        if (opcode[opcode.size() - 1] == 'C')
        {
            is_format2 = true;
        }
        if (is_format2)
        {
            opcode = opcode.substr(0, opcode.size() - 1);
        }

        // opcode
        if (opcode == "ADD")
        {
            machinecode += "0000";
        }
        else if (opcode == "SUB")
        {
            machinecode += "0001";
        }
        else if (opcode == "MOV")
        {
            machinecode += "0010";
        }
        else if (opcode == "AND")
        {
            machinecode += "0011";
        }
        else if (opcode == "OR")
        {
            machinecode += "0100";
        }
        else if (opcode == "NOT")
        {
            machinecode += "0101";
        }
        else if (opcode == "MULT")
        {
            machinecode += "0110";
        }
        else if (opcode == "LSFTL")
        {
            machinecode += "0111";
        }
        else if (opcode == "LSFTR")
        {
            machinecode += "1000";
        }
        else if (opcode == "ASFTR")
        {
            machinecode += "1001";
        }
        else if (opcode == "RL")
        {
            machinecode += "1010";
        }
        else if (opcode == "RR")
        {
            machinecode += "1011";
        }
        // index 45
        is_format2 == true ? machinecode += "10" : machinecode += "00";

        int chunk_point = input.find(" ");
        string D = bitset<3>(stoi(input.substr(0, input.find(" ")))).to_string();
        machinecode += D;
        input = input.substr(chunk_point + 1);
        /*cout << input << endl;
        cout << D << endl;*/

        if (opcode == "MOV" || opcode == "NOT")
        {
            machinecode += "000";
            input = input.substr(2);
        }
        else
        {
            int chunk_point = input.find(" ");
            string A = bitset<3>(stoi(input.substr(0, input.find(" ")))).to_string();
            machinecode += A;
            input = input.substr(chunk_point + 1);
        }

        if (is_format2)
        {
            string C = bitset<4>(stoi(input)).to_string();
            machinecode += C;
        }
        else
        {
            string B = bitset<3>(stoi(input)).to_string();
            machinecode += B;
            machinecode += "0";
        }
        cout << machinecode << endl;
    }
    return 0;
}