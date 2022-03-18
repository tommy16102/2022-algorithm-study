#include <string>
#include <vector>
#include <queue>
using namespace std;

/*

2.24

각 P를 시작점으로 BFS 탐색을 진행해 거리 2 이내에 P가 나오는지 확인.

*/

int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
bool visited[5][5];

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i = 0; i < 5; i++) {

        bool keepDist = true;
        queue<pair<pair<int, int>, int>> queue;

        for(int x = 0; x < 5; x++) {

            for(int y = 0; y < 5; y++) {

                if( places[i][x][y] == 'P') {

                    queue.push({ {x, y}, 0});
                    visited[x][y] = 1;

                    while(!queue.empty()) {

                        int placeX = queue.front().first.first;
                        int placeY = queue.front().first.second;
                        int dist = queue.front().second;
                        queue.pop();

                        if(dist > 2) break;

                        if(dist > 0 && places[i][placeX][placeY] == 'P'){

                            keepDist = false;
                            break;

                        }

                        for(int j = 0; j < 4; j++) {

                            int newX = placeX + moveX[j];
                            int newY = placeY + moveY[j];

                            if(newX < 0 || newY < 0 || newX > 4 || newY > 4) continue;

                            if(visited[newX][newY]) continue;

                            if(places[i][newX][newY] == 'X') continue;
                            else {
                                queue.push({{newX, newY}, dist + 1});
                                visited[newX][newY] = 1;
                            }

                        }

                    }

                }

                while(!queue.empty()) queue.pop();
                for(int a = 0; a < 5; a++) {
                    for(int b = 0; b < 5; b++) {
                        visited[a][b] = 0;
                    }
                }

                if(!keepDist) break;

            }

            if(!keepDist) break;

        }

        if(keepDist) answer.push_back(1);
        else answer.push_back(0);

    }

    return answer;

}
