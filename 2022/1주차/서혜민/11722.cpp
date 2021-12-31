#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.12.31 서혜민

수열의 길이를 저장하는 answers 배열 내 요소를 자기 자신만을 수열로 가지는 1로 초기화 한 뒤, 
이중 for문을 통해서 특정 요소를 기준으로 했을 때 감소하는 수열이 나올 때마다 max 함수를 통해 기존의
answers 배열 내 값과 기준으로 한 요소의 answer 배열 내 값에 1을 더한 값 중 더 큰 값을 answers 배열에 저장한다.

이후, answer 배열 내 요소들 중 가장 큰 값이 정답이 된다.

*/
int numbers[1000];
int answers[1000];

int main() {
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
		answers[i] = 1;
	}

	int count = 0;
	for (int i = 0;i < N;i++) {
		int num = numbers[i];
		for (int j = i + 1;j < N;j++) {
			if ( numbers[j] < num) answers[j] = max(answers[j], answers[i] + 1);
		}
		if (answers[i] > count) count = answers[i];
	}
	cout << count << '\n';
}
