/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 
DFS/BFS 단어변환
2021/09/24 이호준
# 아이디어
1. BFS를 이용한다. 
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    int words_size = begin.size();
    string curWord = "";
    string temp = "";
    queue<string> q;
    q.push(begin);

    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    while (1)
    {
        int size = q.size();
        while (size--)
        {
            curWord = q.front();
            temp = curWord;
            q.pop();

            if (curWord == target)
            {
                return answer;
            }

            for (int i = 0; i < words_size; ++i)
            {
                temp = curWord;
                for (int j = 0; j < 26; ++j)
                {
                    if ('a' + j == curWord[i])
                        continue;
                    else
                    {
                        temp[i] = 'a' + j;
                        if (find(words.begin(), words.end(), temp) != words.end())
                        {
                            q.push(temp);
                        }
                    }
                }
            }
        }

        if (q.empty())
            return 0;
        answer++;
    }

    return answer;
}
