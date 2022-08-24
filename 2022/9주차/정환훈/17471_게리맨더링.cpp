#include <bits/stdc++.h>
using namespace std;

int n;
int popul[11];
vector<int> adj[11]; // 인접 노드

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> popul[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}
}

int calc(vector<int> teamA, vector<int> teamB) { // teamA와 teamB 인구차이 계산
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < teamA.size(); i++) {
		sumA += popul[1 + teamA[i]];
	}
	for (int i = 0; i < teamB.size(); i++) {
		sumB += popul[1 + teamB[i]];
	}

	return abs(sumA - sumB);
}

bool verify(vector<int> teamA, vector<int> teamB) { // teamA와 temaB 가능한지 검증
	vector<int> indexA;
	vector<int> indexB;
	for (int i = 0; i < teamA.size(); i++) { // index = team + 1씩.
		indexA.push_back(teamA[i] + 1);
	}
	for (int i = 0; i < teamB.size(); i++) {
		indexB.push_back(teamB[i] + 1);
	}

	int team[11];
	for (int i = 0; i < indexA.size(); i++) { // A팀
		team[indexA[i]] = 1;
	}
	for (int i = 0; i < indexB.size(); i++) { // B팀
		team[indexB[i]] = 2;
	}

	bool v[11];
	for (int i = 0; i < 11; i++) {
		v[i] = false;
	}
	queue<int> qA;
	queue<int> qB;

	if (!indexA.empty()) // A팀 존재
		qA.push(indexA[0]);
	while (!qA.empty()) {
		int now = qA.front();
		v[now] = true; // 방문
		qA.pop();
		for (int i = 0; i < adj[now].size(); i++) { // bfs
			int next = adj[now][i];
			if (team[next] == 1 && !v[next]) {
				qA.push(next);
			}
		}
	}

	if(!indexB.empty())
		qB.push(indexB[0]);
	while (!qB.empty()) {
		int now = qB.front();
		qB.pop();
		v[now] = true;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (team[next] == 2 && !v[next]) {
				qB.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) { // 모든 노드 방문했는지
		if (v[i] == false)
			return false;
	}

	return true;
}

void solve() {

	int m = 9999999; // 더미값
	

	for (int i = 1; i <= n; i++) {
		vector<int> partition(n, 0); // nCi

		for (int j = 1; j <= i; j++) {
			partition[n - j] = 1;
		}
		do {
			vector<int> teamA;
			vector<int> teamB;

			for (int k = 0; k < n; k++) {
				if (partition[k] == 0) { // A팀
					teamA.push_back(k);
				}
				else { // B팀
					teamB.push_back(k);
				}
			}
			if (verify(teamA, teamB)) { // 가능한 조합일시
				m = min(m, calc(teamA, teamB)); // 최솟값 갱신
			}
		} while (next_permutation(partition.begin(), partition.end()));
	}
	if (m == 9999999) // 팀 못만듬
		m = -1;
	
	cout << m;

}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}