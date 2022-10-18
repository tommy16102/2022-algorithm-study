#include <iostream>
#include <vector>
using namespace std;

/**
union find => 친구비 더 낮은 사람이 부모
부모 친구비 합 <= k => O
**/

int N, M, K;
int price[10001];
int parent[10001];

int getParent(int now) {
	if (parent[now] == now) return now;
	return parent[now] = getParent(parent[now]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		cin >> price[i];
	}

	for (int i = 1; i <= M; i++) {
		int v, w;
		cin >> v >> w;
		int pV = getParent(v);
		int pW = getParent(w);
		if (pV == pW) continue;
		if (price[pV] < price[pW]) parent[pW] = pV;
		else parent[pV] = pW;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) ans += price[i];
	}

	if (ans <= K) cout << ans;
	else cout << "Oh no";

}
