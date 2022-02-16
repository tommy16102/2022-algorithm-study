/*******************************************************************
Algorithm Study
Baekjoon OJ 위상정렬
1005 ACM craft
2022/02/16 이호준
# 아이디어
1. 위상정렬 공부!
구글링
*******************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 1010
using namespace std;

int N, K, D, W;
int Time[MAX];
int Result_Time[MAX];
int Entry[MAX];
vector<int> Build[MAX];

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Initialize()
{
	memset(Time, 0, sizeof(Time));
	memset(Result_Time, 0, sizeof(Result_Time));
	memset(Entry, 0, sizeof(Entry));
	for (int i = 0; i < MAX; i++) Build[i].clear();
}

void Input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> Time[i];
	for (int i = 0; i < K; i++)
	{
		int a, b; cin >> a >> b;
		// a->b
		Build[a].push_back(b);
		// in_degree 증가
		Entry[b]++;
	}
	cin >> W;
}

void Solution()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{	
		// indegree = 0 시작지점
		if (Entry[i] == 0)
		{
			q.push(i);
			Result_Time[i] = Time[i];
		}
	}

	while (!q.empty())
	{
		int Cur = q.front();
		q.pop();

		for (int i = 0; i < Build[Cur].size(); i++)
		{
			int Next = Build[Cur][i];
			Result_Time[Next] = Bigger(Result_Time[Next], Result_Time[Cur] + Time[Next]);
			Entry[Next]--;

			if (Entry[Next] == 0) q.push(Next);
		}
	}

	cout << Result_Time[W] << endl;
}

void Solve()
{
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; T++)
	{
		Initialize();
		Input();
		Solution();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//    freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}