#include <iostream>
#include <vector>
using namespace std;

/*

이차배열 arr은 행은 계산 0부터 20이하의 계산 결과인 수, 열은 최대 계산횟수인 100으로 둬서,
N개의 수 중 가장 먼저 입력받은 수를 1로 초기화 한 뒤, 그 다음수부터 덧셈과 뺄셈을 통해 계산 결과가
0~20 사이에 있으면 배열에 [해당 계산의 결과][현재까지 계산 횟수]에 이전 수의 해당 결과가 나온 개수를 의미하는 [이전계산결과][이전까지 계산 횟수]를 더해주는 과정을 반복한다..

*/
long long int arr[21][100];

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0;i < N;i++) {
		cin >> v[i];
	}

	arr[v[0]][0] = 1;

	for (int i = 1;i < N-1;i++) {
		for (int j = 0;j <= 20;j++) {
			if (arr[j][i - 1]>0) {
				int plus = j + v[i];
				int minus = j - v[i];
				if (plus <= 20) {
					arr[plus][i]+=arr[j][i-1];
				}
				if (minus >= 0) {
					arr[minus][i]+=arr[j][i-1];
				}
			}
		}
	}
	cout << arr[v[N - 1]][N - 2] << endl;
}
