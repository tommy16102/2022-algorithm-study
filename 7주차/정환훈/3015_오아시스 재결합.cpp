#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
stack<pair<int, int>> s; //키, 연속 몇 명
int n;
long long result = 0;
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
}

void solve() {

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        //현재 사람의 키가 스택의 top에 있는 사람보다 크다면
        //이 사람은 현재 사람 이후로 쌍을 이루지 못함
        while (!s.empty() && s.top().first < height) {
            result += s.top().second;
            s.pop();
        }
        //맨 앞에 사람을 세운다()
        if (s.empty())
            s.push({ height, 1 });

        else{
            //같은 키의 경우 따로 처리
            if (s.top().first == height){
                pair<int, int> cur = s.top();
                s.pop();
                result += cur.second;
                //스택 내 제일 큰 사람과 쌍을 이룸
                if (!s.empty())
                    result++;
                //연속해서 같은 키가 나오므로

                cur.second++;

                s.push(cur);

            }

            //더 작은 사람이 왔을 경우

            else {
                s.push({ height, 1 });

                //스택 내 제일 큰 사람과 쌍을 이룸

                result++;

            }

        }

    }
    cout << result;
}

int main() {

	input();
	solve();

	return 0;
}