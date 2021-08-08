/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
1759 암호만들기
2021/08/06 이호준
# 아이디어
1. 모음 1개, 자음 2개를 넣어놓고 dfs? 처럼 구현하려했으나 가지수가 겹치는 경우가 많고 vector조작이 너무 많다.
2. 성공 풀이
   조합으로 4개를 고른후 해당 string이 모음1개, 자음2개를 만족하는 지 check한다.
   set을 이용해 정렬하면서 저장한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> sets;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, n;
    cin >> r >> n;
    string input = "";
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        input += temp;
    }
    //cout << input << endl;

    vector<bool> combination;
    for (int i = 0; i < n - r; i++)
        combination.push_back(false);
    for (int i = 0; i < r; i++)
        combination.push_back(true);

    do
    {
        string answer = "";
        for (int i = 0; i < combination.size(); i++)
        {
            if (combination[i] == true)
            {
                answer += input[i];
                if (answer.size() == r)
                    break;
            }
        }
        int vowel_count = 0;
        if (answer.find('a') != string::npos)
            vowel_count++;
        if (answer.find('e') != string::npos)
            vowel_count++;
        if (answer.find('i') != string::npos)
            vowel_count++;
        if (answer.find('o') != string::npos)
            vowel_count++;
        if (answer.find('u') != string::npos)
            vowel_count++;

        // 자음 2개 이하
        if (vowel_count < 1 || r - vowel_count < 2)
            continue;
        //cout << answer << endl;
        sort(answer.begin(), answer.end());
        if (sets.find(answer) == sets.end())
        {
            sets.insert(answer);
        }

    } while (next_permutation(combination.begin(), combination.end()));

    for (auto a : sets)
        cout << a << endl;

    return 0;
}

//void dfs(vector<char>& vowel, vector<char>& consonant, string make, int r, int vowel_count, int consonant_count, vector<char> &left);
//
//int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	int r, n;
//	cin >> r >> n;
//
//	vector<char> vowel;
//	vector<char> consonant;
//
//	for (int i = 0; i < n; i++) {
//		char temp;
//		cin >> temp;
//		if (temp == 'a' || temp == 'e' || temp == 'u' || temp == 'o' || temp == 'i') {
//			vowel.push_back(temp);
//		}
//		else {
//			consonant.push_back(temp);
//		}
//	}
//	string answer = "";
//	vector<char> left;
//	dfs(vowel, consonant, answer, r, 0, 0, left);
//	for (auto a : sets)
//		cout << a << endl;
//	return 0;
//}

//void dfs(vector<char>& vowel, vector<char>& consonant, string make, int r, int vowel_count, int consonant_count, vector<char> &left)
//{
//	if (make.size() == r) {
//		sort(make.begin(), make.end());
//		if (sets.find(make) == sets.end()) {
//			sets.insert(make);
//		}
//		return;
//	}
//
//	if (vowel_count < 1) {
//		for (int i = 0; i < vowel.size(); i++) {
//			char v = vowel[i];
//			vowel.erase(vowel.begin() + i);
//			string temp = make;
//			make += v;
//			dfs(vowel, consonant, make, r, vowel_count + 1, consonant_count, left);
//			make = temp;
//			vowel.insert(vowel.begin() + i, v);
//		}
//	}
//
//	if (consonant_count < 2) {
//		for (int i = 0; i < consonant.size()-1; i++) {
//			char v = consonant[i];
//			consonant.erase(consonant.begin() + i);
//			make += v;
//			for (int j = i; j < consonant.size()-i; j++) {
//				char v2 = consonant[j];
//				consonant.erase(consonant.begin() + j);
//				make += v2;
//				dfs(vowel, consonant, make, r, vowel_count, consonant_count + 2, left);
//				consonant.insert(consonant.begin() + j, v2);
//			}
//			consonant.insert(consonant.begin() + i, v);
//		}
//	}
//	if (make.size() == 3) {
//		for (auto a : vowel) left.push_back(a);
//		for (auto a : consonant) left.push_back(a);
//		cout << "make : "<< make << endl;
//	}
//
//	for (int i = 0; i < left.size(); i++) {
//		char v = left[i];
//		left.erase(left.begin() + i);
//		make += v;
//		dfs(vowel, consonant, make, r, vowel_count, consonant_count, left);
//		left.insert(left.begin() + i, v);
//	}
//
//}

/*
dfs
모음 vector
자음 vector
모음 1개, 자음 2개를 

int vowel_count, int consonant_count
*/
