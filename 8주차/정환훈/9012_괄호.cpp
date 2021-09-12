//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//using namespace std;
//stack<char> test;
//string s;
//int a = 0;
//long long result = 0;
//void input() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> s;
//}
//
//bool is_valid() {
//	for (int i = 0; i < s.size(); i++) {
//		if (test.empty()) {
//			test.push(s[a]);
//			a++;
//			continue;
//		}
//
//		if (test.top() == '(') {
//			if (s[a] == ')') {
//				test.pop();
//			}
//			else if (s[a] == '(') {
//				test.push(s[a]);
//			}
//		}
//
//		else if (test.top() == ')') {
//			test.push(s[a]);
//		}
//
//		else if (test.top() == '[') {
//			if (s[a] == ']') {
//				test.pop();
//			}
//			else if (s[a] == '[') {
//				test.push(s[a]);
//			}
//		}
//
//		else if (test.top() == ']') {
//			test.push(s[a]);
//		}
//
//		a++;
//	}
//
//	if (test.empty()) {
//		//cout << "valid";
//		return true;
//	}
//	else
//		//cout << "not valid";
//		return false;
//}
//
//void solve() {
//	if (!is_valid()) {
//		cout << 0;
//		return;
//	}
//	
//	stack<char> st;
//
//	int temp = 1;
//	bool impossible = false;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '(') {
//			temp *= 2;
//			st.push(s[i]);
//		}
//
//		else if (s[i] == '[') {
//			temp *= 3;
//			st.push(s[i]);
//		}
//
//		else if (s[i] == ')' && (s.empty() || st.top() != '(')) {
//			impossible = true;
//			break;
//		}
//
//		else if (s[i] == ']' && (s.empty() || st.top() != '['))
//		{
//			impossible = true;
//			break;
//
//		}
//
//
//		else if (s[i] == ')') {
//			if (s[i - 1] == '(') {
//				result += temp;
//			}
//			st.pop();
//			temp /= 2;
//		}
//
//		else if (s[i] == ']') {
//			if (s[i-1] == '[') {
//				result += temp;
//			}
//			st.pop();
//			temp /= 3;
//		}
//	}
//
//	if (impossible || !st.empty())
//		result = 0;
//	cout << result;
//}
//
//int main() {
//
//	input();
//	solve();
//	return 0;
//}




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n;
long long result = 0;

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
}

bool is_valid(string str) {

	stack<char> test;
	int a = 0;
	for (int i = 0; i < str.size(); i++) {
		if (test.empty()) {
			test.push(str[a]);
			a++;
			continue;
		}

		if (test.top() == '(') {
			if (str[a] == ')') {
				test.pop();
			}
			else if (str[a] == '(') {
				test.push(str[a]);
			}
		}
		a++;
	}

	if (test.empty()) {
		return true;
	}

	else
		return false;
}

int main() {

	input();

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (is_valid(s))
			cout << "YES";
		else cout << "NO";
	}
	return 0;
}










