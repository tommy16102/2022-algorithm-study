// https://ssungkang.tistory.com/entry/Algorithm-%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9CUnion-Find 알고리즘 참고
#include <iostream>
#include <vector>

#define MAX_SIZE 1000001

using namespace std;

int sets[MAX_SIZE];

int find(int x)
{
    if (sets[x] < 0)
        return x;
    else
    {
        int y = find(sets[x]);
        sets[x] = y;
        return y;
    }
}

// 양수, 부모위치
// 음시 루트(자식개수 의미)
void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    // sets 음수
    if (sets[x] < sets[y])
    {
        sets[x] += sets[y];
        sets[y] = x;
    }
    else
    {
        sets[y] += sets[x];
        sets[x] = y;
    }
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count;

    cin >> n >> count;

    for (int i = 0; i < MAX_SIZE; i++)
        sets[i] = -1;

    for (int i = 0; i < count; i++)
    {
        int command, x, y;
        cin >> command >> x >> y;
        if (command == 0)
            union_sets(x, y);
        else
        {
            cout << (find(x) == find(y) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}

//int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	unordered_map<int, int> map;
//
//	int n, count;
//
//	cin >> n >> count;
//
//	for (int i = 1; i <= n; i++)
//		map.insert({ i, i });
//	for (int i = 0; i < count; i++) {
//		int command, a, b;
//
//		cin >> command >> a >> b;
//
//		if (command == 1) {
//			if (map.find(a)->second == map.find(b)->second)
//				cout << "YES\n";
//			else
//				cout << "NO\n";
//		}
//		else {
//			int current = map.find(a)->second;
//			int change = map.find(b)->second;
//			for (auto &a : map)
//				if (a.second == change)
//					a.second = current;
//		}
//
//	}
//
//
//	return 0;
//}