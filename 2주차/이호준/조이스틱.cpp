/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Greedy / 조이스틱
2021/07/17 이호준
# 아이디어
1. A ~ Z 는 아스키코드로 65 ~ 90이다. 총 알파벳 수 26개.
알파벳 수의 절반인 13보다 클 경우 A에서 왼쪽으로 이동하는 값이 더 작다.
왼쪽 이동은 answer += 26 - (name[current] - target[current]);
ex ) A Z 왼쪽 1번 이동 >> 26-(90-65) = 26 - 25 = 1
오른쪽 이동은 answer += name[current] - target[current];로 정리할 수 있다.
ex ) A C 오른쪽 2번 이동 >> 67-65 = 2

첫번째 시도에서 그냥 greedy로 내 좌우만 생각해서 현상황에서의 이동방향을 찾았는데
해당 알고리즘은 항상 최선이 아니어서 시간초과로 답이아니었다.
근데 greedy는 원래 최선이 아니지 않나 ... 

두번째 생각에서 그냥 최선의 위치를 찾는게 맞다고 생각해
현 위치에서 left와 right로 이동하여 아직 맞춰지지 않은 알파벳을 찾는 데
걸리는 이동횟수를 비교하여 적은 쪽으로 이동하도록 구현하였다.
*******************************************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 65 ~ 90 26개

int solution(string name)
{
    int answer = 0;
    string target = "";
    for (int i = 0; i < name.size(); i++)
    {
        target += "A";
    }
    int current = 0;
    while (1)
    {
        // change count for matching character
        if (target[current] != name[current])
        {
            if (name[current] >= 'N')
            {
                answer += 26 - (name[current] - target[current]);
            }
            else
            {
                answer += name[current] - target[current];
            }
            target[current] = name[current];
        }
        // find next location left or right
        int left = 0;
        int right = 0;
        int temp = current;
        int right_location = 0;
        if (target != name)
        {
            // right count
            while (name[current + right] == target[current + right])
            {
                right++;
                if (current + right == name.size())
                    current = -(right);
            }
            right_location = current + right;
            current = temp;
            // left count
            while (name[current - left] == target[current - left])
            {
                left++;
                if (current - left < 0)
                    current = name.size() - 1 + left;
            }
            if (left < right)
            {
                answer += left;
                current = current - left;
            }
            else
            {
                answer += right;
                current = right_location;
            }
        }
        else
        {
            break;
        }
    }
    return answer;
}

int main(void)
{
    //"JEROEN"	56
    //	"JAN"	23
    cout << "정답 : 56  : " << solution("JEROEN") << endl;
    ;
    cout << "정답 : 23  : " << solution("JAN");
}

//// 45.5 시간초과
//
//int solution(string name) {
//	int answer = 0;
//	string target = "";
//	for (int i = 0; i < name.size(); i++) {
//		target += "A";
//	}
//	int current = 0;
//	while (target != name) {
//		if (target[current] != name[current]) {
//			if (name[current] >= 'N') {
//				answer += 26 - (name[current] - target[current]);
//			}
//			else {
//				answer += name[current] - target[current];
//			}
//			target[current] = name[current];
//		}
//		// find next location left or right
//		if (current + 1 < name.size() && target[current + 1] == name[current + 1]) {
//			current--;
//			if (current < 0) {
//				current = name.size() - 1;
//			}
//		}
//		else if (current + 1 == name.size()) {
//			current = 0;
//		}
//		else {
//			current++;
//		}
//		// cursor move
//		answer += 1;
//	}
//	return answer - 1;
//}