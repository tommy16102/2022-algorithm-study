/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
5430 AC
2021/09/03 이호준
# 아이디어
1. 덱을 이용해서 앞뒤로 빼면서 진행한다.
실제 reverse를 하기에 시간이 많이 걸려서 시간초과가 발생하기 떄문.
reverse인 경우를 알기위한 bool 변수를 설정하고 덱을 이용!

입력값을 parsing할때 string의 find와 substr을 쓰면 시간초과가 발생한다.
string method들은 매우 느린것 같다.
꼭 필요한 곳이 아니면 사용하지 말아야겠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
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
        string command;
        getline(cin, command);
        int x;
        cin >> x;
        cin.ignore();
        deque<int> nums;
        string inputs;
        getline(cin, inputs);
        inputs = inputs.substr(1);
        /*for (int i = 0; i < x; i++) {
			int location = 0;
			if (i == x - 1) location =  inputs.find(']');
			else location = inputs.find(',');
			nums[i] = stoi(inputs.substr(0, location));
			inputs = inputs.substr(location+1);
		}*/
        int j = 0;
        while (inputs[j] != '\0')
        {
            int x = 0;
            while (inputs[j] >= '0' && inputs[j] <= '9')
            {
                x *= 10;
                x += int(inputs[j] - '0');
                j++;
            }
            if (x != 0)
                nums.push_back(x);
            j++;
        }

        bool isReverse = false;
        bool isError = false;

        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (nums.empty())
                {
                    isError = true;
                    break;
                }
                if (isReverse)
                {
                    nums.pop_back();
                }
                else
                {
                    nums.pop_front();
                }
            }
        }
        if (isError)
            cout << "error\n";
        else
        {
            cout << "[";
            if (!isReverse)
            {
                for (int i = 0; i < nums.size(); i++)
                {
                    cout << nums[i] << (i != nums.size() - 1 ? "," : "");
                }
            }
            else
            {
                if (!nums.empty())
                {
                    for (int i = nums.size() - 1; i >= 0; i--)
                    {
                        cout << nums[i] << (i != 0 ? "," : "");
                    }
                }
            }

            cout << "]\n";
        }
    }

    return 0;
}