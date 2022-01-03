/*******************************************************************
Algorithm Study
Baekjoon 9주차 다익스트라/이분탐색
2470 두 용액
2021/09/07 이호준
# 아이디어
1. 양수와 음수를 구분해서 vector에 모은다.
양수를 정렬하고 음수의 값을 양수에서 찾는다.
이때 binary Search를 이용하고 탐색에 성공하는 순간 용액차이가 0인 지점을 찾았으므로 바로 종료
탐색에 실패할경우 left와 right값을 검사하여 두 용액차가 최소가 되는값을 찾도록 한다.

근데 이 알고리즘은 헛점이 있는것으로 보인다.
예외처리가 많이 필요했다.
음수만 있는 경우, 양수만 있는 경우
음수 양수만 있는 경우에서도 양수만 사용했을 때가 더 적은경우, 음수만 사용했을 때가 더 적은 경우를 체크 해줘야했다.

다른 풀이를 찾아서 공부해야겠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int abs(int x) { return (x >= 0) ? x : -1 * x; };

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    vector<int> nums;

    vector<int> negative;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
            negative.push_back(x);
        else
            nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    pair<int, int> answer;
    int min;

    if (negative.empty() && !nums.empty())
    {
        cout << nums[0] << " " << nums[1];
    }
    else if (!negative.empty() && nums.empty())
    {
        sort(negative.begin(), negative.end(), greater<int>());
        cout << negative[1] << " " << negative[0];
    }
    else
    {
        int max = 2000000000;
        for (int i = 0; i < negative.size(); i++)
        {

            int left = 0;
            int right = nums.size() - 1;
            int find_value = -1 * negative[i];
            int answer_index = 0;
            bool finish = false;
            while (left <= right)
            {
                int mid = (left + right) / 2;

                if (nums[mid] == find_value)
                {
                    answer_index = mid;
                    finish = true;
                    break;
                }
                else if (nums[mid] > find_value)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            if (finish)
            {
                cout << negative[i] << " " << nums[answer_index];
                return 0;
            }

            if (right < nums.size() && right >= 0)
            {
                int check = nums[right] + negative[i];
                if (abs(check) < max)
                {
                    answer = {negative[i], nums[right]};
                    max = abs(check);
                }
            }

            if (left < nums.size())
            {
                int check = nums[left] + negative[i];
                if (abs(check) < max)
                {
                    answer = {negative[i], nums[left]};
                    max = abs(check);
                }
            }
        }
        int check1 = 2000000001;
        int check2 = 2000000001;
        if (nums.size() >= 2)
        {
            check1 = abs(nums[0] + nums[1]);
        }
        if (negative.size() >= 2)
        {
            check2 = abs(negative[0] + negative[1]);
        }
        int current = abs(answer.second + answer.first);

        if (check1 < check2)
        {
            if (check1 < current)
            {
                cout << nums[0] << " " << nums[1];
            }
            else
            {
                cout << answer.first << " " << answer.second;
            }
        }
        else
        {
            if (check2 < current)
            {
                cout << negative[1] << " " << negative[0];
            }
            else
            {
                cout << answer.first << " " << answer.second;
            }
        }
    }

    return 0;
}