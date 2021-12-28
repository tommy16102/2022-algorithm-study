#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> songs;
    multimap<string, int> answers;
    unordered_multimap<pair<string, int>, int, pair_hash> answer_map;

    for (int i = 0; i < genres.size(); i++)
    {
        string genre = genres[i];
        int play = plays[i];
        if (songs.find(genre) == songs.end())
        {
            songs.insert({genre, play});
        }
        else
        {
            songs[genre] += play;
        }
        answers.insert({genre, play});
        answer_map.insert({{genre, play}, i});
    }
    for (auto a : answers)
    {
        cout << a.first << " " << a.second << endl;
    }

    vector<pair<string, int>> check(songs.begin(), songs.end());

    sort(check.begin(), check.end(), cmp);

    for (int i = 0; i < check.size(); i++)
    {
        string genre = check[i].first;
        multimap<string, int>::iterator it;
        vector<int> temp;
        for (it = answers.equal_range(genre).first; it != answers.equal_range(genre).second; ++it)
        {
            temp.push_back((*it).second);
            cout << (*it).first << (*it).second << endl;
        }
        sort(temp.begin(), temp.end(), greater<>());
        for (auto a : temp)
        {
            cout << a << endl;
        }
        answer.push_back(answer_map.find({genre, temp[0]})->second);
        if (temp.size() >= 2)
        {
            if (temp[0] == temp[1])
            {
                // answer_map "A" "800"->0 "A" "800" ->3
                auto range = answer_map.equal_range({genre, temp[0]}).first;
                auto range2 = answer_map.equal_range({genre, temp[0]}).second;
                int count = 0;
                for (auto a = range; a != range2; ++a)
                {
                    count++;
                    if (count == 2)
                    {
                        answer.push_back(a->second);
                        break;
                    }
                }
                /*for_each(range.first, range.second, [&count, &answer](auto& x) {count++;
				if (count == 2) {
					answer.push_back(x.second);
					return;
				}});*/
            }
            else
            {
                answer.push_back(answer_map.find({genre, temp[1]})->second);
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<string> genre = {"A", "A", "A", "A", "A"};
    vector<int> plays = {5, 5, 5, 5, 5};

    vector<int> answer = solution(genre, plays);

    cout << "answer : " << endl;
    for (auto a : answer)
    {
        cout << a << " ";
    }

    return 0;
}