/*******************************************************************
Algorithm Study
Baekjoon 19236 청소년 상어
2023/04/28 이호준
# 아이디어
1. 구현
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAPSIZE 4

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer = 0;

struct Fish {
    int x, y;
    int num;
    int direction;
    bool dead;
};

struct Shark {
    int x, y;
    int direction;
    int eat;
};

struct FishLocation{
    int x, y;
};

bool isSharkLocation(FishLocation fish, Shark shark){
    return fish.x == shark.x && fish.y == shark.y;
}

bool inRange(FishLocation fish){
    return fish.x >= 0 && fish.x < MAPSIZE && fish.y >= 0 && fish.y < MAPSIZE;
}

void visualizeMap(vector<vector<Fish>> graph){
    for(int i = 0 ; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            if(graph[i][j].dead)
                cout << "(dead) ";
            else
                cout << "(" << graph[i][j].num << ", " << graph[i][j].direction <<") ";
        }
        cout <<"\n";
    }
    cout <<"\n\n";
}

vector<vector<Fish>> moveFish(vector<vector<Fish>> graph, map<int, FishLocation> fish_queue, Shark shark){
    for(int i = 1; i <= 16; i++){
        if(fish_queue.find(i) != fish_queue.end()){
            FishLocation current_fish = fish_queue[i];
            int current_fish_direction = graph[current_fish.x][current_fish.y].direction;
            bool isMove = false;
            for(int rotate = 0; rotate < 8; rotate++){
                int direction = (current_fish_direction + rotate) % 8;
                FishLocation next_location = {current_fish.x + dx[direction], current_fish.y + dy[direction]};
                if(isSharkLocation(next_location, shark) || !inRange(next_location))  continue;

                // swap
                Fish target_location_fish = graph[next_location.x][next_location.y];
                graph[next_location.x][next_location.y] = Fish({current_fish.x, current_fish.y, i, direction, false});
                graph[current_fish.x][current_fish.y] = target_location_fish;
                if(fish_queue.find(target_location_fish.num) != fish_queue.end()){
                    fish_queue[target_location_fish.num].x = current_fish.x;
                    fish_queue[target_location_fish.num].y = current_fish.y;
                }
                fish_queue.erase(i);
                isMove = true;
                break;
            }
            if(!isMove)
                graph[current_fish.x][current_fish.y].direction = (graph[current_fish.x][current_fish.y].direction + 7) % 8;
        }
    }

    return graph;
}

void eatFish(Shark shark, vector<vector<Fish>> graph){
    // move fish
    map<int, FishLocation> fish_queue;
    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            if(!graph[i][j].dead)
                fish_queue.insert({graph[i][j].num, FishLocation{i, j}});
        }
    }
    // cout << "Info : " << fish_queue.size() << " " << shark.direction << " " << shark.eat << " (" << shark.x << ", " << shark.y <<")\n";
    graph = moveFish(graph, fish_queue, shark);
    
    // eat fish
    for(int i = 1; i <= 4; i++){
        int next_x = shark.x + dx[shark.direction] * i;
        int next_y = shark.y + dy[shark.direction] * i;
        if(inRange({next_x, next_y})){
            if(!graph[next_x][next_y].dead){
                graph[next_x][next_y].dead = true;
                eatFish(Shark{next_x, next_y, graph[next_x][next_y].direction, shark.eat + graph[next_x][next_y].num}, graph);
                graph[next_x][next_y].dead = false;
            }
        }else{
            if (answer < shark.eat){
                answer = shark.eat;
                return;
            }
        }
    }
    if (answer < shark.eat){
        answer = shark.eat;
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<vector<Fish>> graph(MAPSIZE, vector<Fish>(MAPSIZE, Fish{}));

    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            int num, direction;
            cin >> num >> direction;
            graph[i][j] = Fish{i, j, num, direction - 1, false};
        }
    }

    Shark shark = Shark{0, 0, graph[0][0].direction, graph[0][0].num};
    graph[0][0].dead = true;
    eatFish(shark, graph);

    cout << answer;
    return 0;
}