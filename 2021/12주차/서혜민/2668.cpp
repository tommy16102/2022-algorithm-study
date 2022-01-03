#include <iostream>
#include <vector>
using namespace std;

/*
arr내 모든 원소별로 사이클이 존재하는 지 확인 후, 사이클이 존재하면 해당 원소를 벡터에 넣어준다.
*/

int arr[101];
bool visited[101];
vector<int> ans;


void dfs(int start, int now) {
	cout << " "<<start << " " << now << " " << ans.size() << endl;
	cout << "  ";for (auto& i : ans) cout << i << ' ';
	cout << endl;
	if (!visited[now]) {
		visited[now] = 1;
		dfs(start, arr[now]);
	}
	else if (now == start) {
		ans.push_back(start);
		return;
	}
	
}

int main() {
	int N;
	cin >> N;

	for (int i = 1;i <= N;i++) cin >> arr[i];

	for (int i = 1;i <= N;i++) {
		memset(visited, 0, sizeof(visited));
		cout << "시작!" << endl;
		dfs(i, i);
	}

	cout << ans.size() << endl;
	for (auto& i : ans) cout << i << endl;
}