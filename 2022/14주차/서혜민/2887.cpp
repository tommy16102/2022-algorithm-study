#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

vector < pair<int, pair<int,int>>> planet;

int findParent(int n) {
	if (n == parent[n]) return n;
	return parent[n] = findParent(parent[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });

		parent[i] = i;
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		planet.push_back({ abs(X[i].first - X[i + 1].first), {X[i].second, X[i + 1].second} });
		planet.push_back({ abs(Y[i].first - Y[i + 1].first), {Y[i].second, Y[i + 1].second} });
		planet.push_back({ abs(Z[i].first - Z[i + 1].first), {Z[i].second, Z[i + 1].second} });
	}

	sort(planet.begin(), planet.end());

	int ans = 0;

	for (int i = 0; i < planet.size(); i++) {
		int dist = planet[i].first;
		int A = planet[i].second.first;
		int B = planet[i].second.second;

		int parentA = findParent(A);
		int parentB = findParent(B);

		if (parentA == parentB) continue;

		parent[parentA] = parentB;
		ans += dist;
	}

	cout << ans << endl;
}