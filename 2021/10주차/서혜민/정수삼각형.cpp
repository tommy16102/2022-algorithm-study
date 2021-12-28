#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.09.13

dp를 통해 삼각형의 값을 아래로 이동하면서 더해나갈 때, 더했을 때 더 큰 값이 나오도록 더해 나가며,
모든 더해주는 과정이 끝난 뒤, max_element를 이용해서 가장 밑바닥에서 큰 값을 꺼낸다.

*/

int solution(vector<vector<int>> triangle) {
    int tSize = triangle.size();
    for (int i = 1;i < tSize;i++) {
        int ttSize = triangle[i].size();
        for (int j = 0;j < ttSize;j++) {
            if (j == 0) triangle[i][j] += triangle[i - 1][j];
            else if (j == ttSize-1) triangle[i][j] += triangle[i - 1][j - 1];
            else triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }

    return *max_element(triangle[tSize - 1].begin(), triangle[tSize - 1].end());
}
