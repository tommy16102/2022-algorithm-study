#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define SHEEP 0
#define WOLF 1

using namespace std;

vector<int> node_info;
vector<vector<int>> map;

int max_value = 0;

void dfs(int sheep, int wolf, vector<int> reserved, int current_node) {
	for (int i = 0; i < map[current_node].size(); i++) {
		if (i == 0 && map[current_node].size() > 1) {
				reserved.push_back(map[current_node][1]);
		}
		else {
				reserved.push_back(map[current_node][0]);
		}
	}

	bool end = true;
	for (int a = 0; a < reserved.size(); a++) {
		int next_res_node = reserved[a];
		if (node_info[next_res_node] == SHEEP) {
			reserved.erase(reserved.begin() + a);
			a--;
			end = false;
			dfs(sheep + 1, wolf, reserved, next_res_node);
		}
		else {
			if (sheep > wolf + 1) {
				reserved.erase(reserved.begin() + a);
				end = false;
				dfs(sheep, wolf + 1, reserved, next_res_node);
				reserved.insert(reserved.begin() + a, next_res_node);
			}
		}
	}
	if (end) {
		if (sheep > max_value) {
			max_value = sheep;
		}
	}
	
	for (int i = 0; i < map[current_node].size(); i++) {
		int next_node = map[current_node][i];
		if (node_info[next_node] == SHEEP) {
			reserved.erase(remove(reserved.begin(), reserved.end(), next_node), reserved.end());
			dfs(sheep + 1, wolf, reserved, next_node);
		}
		else {
			if (sheep > wolf + 1) {
				reserved.erase(remove(reserved.begin(), reserved.end(), next_node), reserved.end());
				dfs(sheep, wolf + 1, reserved, next_node);
			}
			// 가지 않고 나머지들 확인.
			bool end = true;
			for (int a = 0; a < reserved.size(); a++) {
				int next_res_node = reserved[a];
				if (node_info[next_res_node] == SHEEP) {
					reserved.erase(reserved.begin() + a);
					a--;
					end = false;
					dfs(sheep + 1, wolf, reserved, next_res_node);
				}
				else {
					if (sheep > wolf + 1) {
						reserved.erase(reserved.begin() + a);
						end = false;
						dfs(sheep, wolf + 1, reserved, next_res_node);
						reserved.insert(reserved.begin() + a, next_res_node);
					}
				}
			}
			if (end) {
				if (sheep > max_value) {
					max_value = sheep;
				}
			}
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;
	node_info = info;
	sort(edges.begin(), edges.end());
	vector<vector<int>> maps(info.size() + 1);
	for (int i = 0; i < edges.size(); i++) {
		maps[edges[i][0]].push_back(edges[i][1]);
	}
	map = maps;
	vector<int> reserved;

	dfs(1, 0, reserved, 0);

	answer = max_value;

	return answer;
}