/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
3190 뱀
2021/09/03 이호준
# 아이디어
1. 덱을 이용해 뱀의 몸을 표현한다.
오른쪽 회전 i 증가, 왼쪽회전 i 감소 방향은 dx dy를 이용해 구현
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, nums;

    cin >> n;
    cin >> nums;

    vector<vector<int>> map(n, vector<int>(n, 0));

    map[0][0] = 1;
    for (int i = 0; i < nums; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = 2;
    }

    /*for (auto a : map) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}*/
    int change;
    cin >> change;
    queue<pair<int, char>> changes;
    for (int i = 0; i < change; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        changes.push({x, y});
    }

    deque<pair<int, int>> snake;
    snake.push_back({0, 0});
    int direction = 0;
    for (int i = 1;; i++)
    {
        /*for (auto a : map) {
			for (auto b : a)
				cout << b << " ";
			cout << endl;
		}
		cout << endl;*/
        if (changes.front().first == i - 1)
        {
            if (changes.front().second == 'D')
            {
                direction++;
                if (direction == 4)
                    direction = 0;
            }
            else
            {
                direction--;
                if (direction == -1)
                    direction = 3;
            }
            changes.pop();
        }
        int nx = snake.back().first + dx[direction];
        int ny = snake.back().second + dy[direction];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 1)
        {
            cout << i << endl;
            return 0;
        }

        snake.push_back({nx, ny});
        if (map[nx][ny] != 2)
        {
            // is not apple
            map[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        map[nx][ny] = 1;
    }

    return 0;
}

/*

꼬리, 머리, 방향


1. 0 R -> 0 -1  
     L -> 0  1

0 -1 R -1 0

오른쪽 회전 i 증가, 왼쪽회전 i 감소

*/
