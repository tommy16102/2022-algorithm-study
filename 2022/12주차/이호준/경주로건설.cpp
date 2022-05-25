#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

class Car {
    public:
        int x, y, cost, dir; 
};

struct cmp {
    bool operator()(const Car& a, const Car& b) {
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    int cost[25][25][4]; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
                cost[i][j][k] = INF; 
    for (int i = 0; i < 4; ++i)
        cost[0][0][i] = 0;
    
    priority_queue<Car, vector<Car>, cmp> pq;
    pq.push({ 0, 0, 0, -1}); 

    while (!pq.empty()) {
        Car current = pq.top();
        pq.pop();
        
        for (int i = 0; i < 4; ++i) {
            
            int next_x = current.x + dx[i];
            int next_y= current.y + dy[i];
            int nextDir = i;
            int nextCost = current.cost;

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || board[next_x][next_y] == 1)
                continue;

            nextCost += 100;
            if (current.dir == UP || current.dir == DOWN) 
                if (nextDir == LEFT || nextDir == RIGHT)
                    nextCost += 500;
            if (current.dir == LEFT || current.dir == RIGHT) 
                if (nextDir == UP || nextDir == DOWN)
                    nextCost += 500;

            if (nextCost < cost[next_x][next_y][nextDir]) {
                cost[next_x][next_y][nextDir] = nextCost;
                pq.push({ next_x, next_y, nextCost, nextDir });
            }
        }
    }

    answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
    return answer;
}