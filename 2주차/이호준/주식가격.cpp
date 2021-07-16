/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Stack / Queue / 주식가격
2021/07/17 이호준
# 의도
본래 스택을 이용해 top()보다 크면 넣고 작으면 pop하는 형식을 통해서
오름차순으로 스택에 정리하면서 풀고 싶었으나 잘되지 않아
O(n^2)으로 자신의 값보다 작은 값을 갖는 지점을 찾아 해당 지점까지의
거리를 통해 구하는 것으로 하였다.
하지만 이풀이는 좋지 않은 풀이라고 생각하고
스택을 이용해 푸는 본래의 아이디어로 구현해야한다.

# 본래 의도대로 스택으로 푸는 법
	※ stack에서 pop하는 시점에서 answer의 index와의 관계를 식으로 구하지 못했었다.
	=> stack에 prices value를 넣는것이 아니라 index를 넣음으로써 해결할 수 있었다.

	※ stack과 같은 자료에 넣는 값에 대해서 좀 더 넓은 시점으로 생각해야겠다.
*******************************************************************/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<int> stack;
	for (int i = 0; i < prices.size(); i++) {
		int current = prices[i];
		int j = i + 1;
		stack.push(current);
		while (j < prices.size() && current <= prices[j])
			stack.push(prices[j++]);
		if (stack.size() == prices.size() - i)
			answer.push_back(stack.size() - 1);
		else
			if (i == prices.size() - 1)
				answer.push_back(0);
			else
				answer.push_back(stack.size());
		while (!stack.empty())
			stack.pop();
	}
	return answer;
}

int main(void) {
	vector<int> a = { 1, 2, 3, 2, 3 };
	vector<int> b = { 5, 8, 6, 2, 4, 1 };
	cout << "answer : [4, 3, 1, 1, 0]\t>>  ";
	for (auto & x : solution(a))
		cout << x << "  ";
	cout << "\nanswer : [3, 1, 1, 2, 1, 0]\t>>  ";
	for (auto & x : solution(b))
		cout << x << "  ";
	//[1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
	//[5, 8, 6, 2, 4, 1] [3, 1, 1, 2, 1, 0]
}