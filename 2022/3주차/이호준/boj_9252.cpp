//// @reference https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence
//// @refrenece https://dailylifeofdeveloper.tistory.com/98
//#include <vector>
//#include <iostream>
//#include <string>
//#include <algorithm>
//
// std::vector<std::vector<int> > dp;
// std::vector<char> answer;
// std::string str1, str2;
//
// void preset()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//}
//
// void init() {
//	std::cin >> str1 >> str2;
//	dp.resize(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));
//}
//
// void solution() {
//	//fill dp
//	for (int i = 1; i <= str1.length(); i++) {
//		for (int j = 1; j <= str2.length(); j++) {
//			if (str1[i - 1] == str2[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	//fill answer
//	int k = str1.length();
//	for (int j = str2.length(); j >= 0; j--) {
//		if (dp[i][j] == 0)
//			break;
//		for (int i = k; i >= 0; i--) {
//			if (dp[i][j] == dp[i][j - 1])
//				break;
//			else if (dp[i][j] == dp[i - 1][j])
//				continue;
//			else {
//				answer.push_back(str1[i - 1]);
//				k = i - 1;
//				break;
//			}
//		}
//	}
//}
//
// void output() {
//	std::cout << answer.size() << std::endl;
//	while (!answer.empty()) {
//		std::cout << answer.back();
//		answer.pop_back();
//	}
//	std::cout << std::endl;
//}
//
// int main() {
//	preset();
//	init();
//	solution();
//	output();
//	return (0);
//}