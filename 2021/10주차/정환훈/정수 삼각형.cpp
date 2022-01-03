#include <iostream>
#include <string>
#include <vector>

using namespace std; // 210913

int solution(vector<vector<int>> triangle) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;

    for (int i = triangle.size() - 1; i >= 1; i--) { // 맨 아랫줄에서부터
        for (int j = 0; j < triangle[i].size() - 1; j++) { // 가로 줄에서 left right 비교
            int left = triangle[i][j]; // left
            int right = triangle[i][j + 1]; // right
            if (left > right) { // 둘 중 큰 값을 위에 값에 더해줌
                triangle[i - 1][j] += left;
            }
            else {
                triangle[i - 1][j] += right;
            }
        }
    }

    answer = triangle[0][0]; // 가장 큰 경로값이 맨 위에
    cout << answer;
    

    return answer;

}