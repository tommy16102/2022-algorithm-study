#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*

2022.01.10

(,)로 이루어진 문자열을 앞에서부터 '('일때는 스택에 집어넣고,
')'일때는 스택에서 하날 꺼낸 뒤, 문자열 내 바로 앞이 '('이면 레이저이므로, 
스택에 저장된 '('의 개수만큼 잘려지고, 그렇지 않으면, 해당 쇠막대기의 끝이므로,
끝부분 하나만 더 잘리게 된다.

*/

int main() {
	string str;
	cin >> str;

	stack<char> stack;

	int answer = 0;
	for (int i = 0;i < str.length();i++) {
		char c = str[i];
		if (c == '(') stack.push(c);
		else {
			stack.pop();
			if (str[i - 1] == '(') answer += stack.size();
			else answer += 1;
		}
	}
	cout << answer << '\n';
}
