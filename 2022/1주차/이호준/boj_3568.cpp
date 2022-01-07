/*******************************************************************
Algorithm Study
Baekjoon OJ DP
3568 iSharp
2022/01/04 이호준
# 아이디어
1. string의 find와 substr을 통해 input string을 변경하면서 진행한다. stack을 이용해 순서를 반대로 한다.
*******************************************************************/
#include <string>
#include <vector>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;

    getline(cin, input);

    int index;
    index = input.find(" ");

    string type = input.substr(0, index);
    input = input.substr(index + 1);

    bool end = false;
    vector<char> stack;
    while (input != ";")
    {
        index = input.find(",");
        if (index == string::npos)
        {
            index = input.find(";");
            end = true;
        }
        string answer = type;
        if (index >= 0)
        {
            for (int i = 0; i < index; i++)
            {
                if (input[i] == '*' || input[i] == '[' || input[i] == ']' || input[i] == '&')
                {
                    char temp = input[i];
                    if (input[i] == '[')
                    {
                        temp = ']';
                    }
                    else if (input[i] == ']')
                    {
                        temp = '[';
                    }
                    stack.push_back(temp);
                }
                else
                {
                    continue;
                }
            }
            int size = stack.size();
            for (int i = 0; i < size; i++)
            {
                answer += stack.back();
                stack.pop_back();
            }
            answer += " ";
            for (int i = 0; i < index - size; i++)
            {
                answer += input[i];
            }
            answer += ";";
            cout << answer << endl;
            if (!end)
            {
                input = input.substr(index + 2);
            }
            else
            {
                input = ";";
            }
        }
    }
    return 0;
}

// #include<iostream>
// #include<string>
// #include<vector>

// using namespace std;

// int main(void) {

// 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// 	string input;

// 	getline(cin, input);

// 	int index;
// 	index = input.find(" ");

// 	string type = input.substr(0, index);
// 	input = input.substr(index + 1);
// 	vector<char> stack;
// 	while (input != ";") {
// 		index = input.find(",");
// 		if (index == string::npos) {
// 			index = input.find(";");
// 		}
// 		string answer = type;
// 		if (index >= 0) {
// 			for (int i = 0; i < index; i++) {
// 				if (input[i] == '*' || input[i] == '[' || input[i] == ']' || input[i] == '&') {
// 					char temp = input[i];
// 					if (input[i] == '[') {
// 						temp = ']';
// 					}else if (input[i] == ']') {
// 						temp = '[';
// 					}
// 					stack.push_back(temp);
// 				}
// 				else {
// 					continue;
// 				}
// 			}
// 			int size = stack.size();
// 			for (int i = 0; i < size; i++) {
// 				answer += stack.back();
// 				stack.pop_back();
// 			}
// 			answer += " ";
// 			for (int i = 0; i < index - size; i++) {
// 				answer += input[i];
// 			}
// 			answer += ";";
// 			cout << answer << endl;
// 			if (index + 2 < input.size()) {
// 				input = input.substr(index + 2);
// 			}
// 			else {
// 				input = ";";
// 			}
// 		}
// 	}
// 	return 0;
// }
