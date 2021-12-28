#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈
    푼 날짜 : 2021/07/21

    기본 아이디어 : 여자*2 = 남자의 조건에서
    여자가 많을 경우, 남자가 많을 경우, 같을 경우 나눠서 한명씩 빼면서 진행
    

*/


int main() {
		int boy; int girl; int cannot;

		cin >> girl >> boy >> cannot;

		int order = 0; // 0 : 여자가 많다 1: 남자가 많다 2 : 같다
		while (cannot > 0) {

			if (girl > 2 * boy) {
				order = 0;
			}
			else if (girl < 2 * boy) {
				order = 1;
			}
			else order = 2;


			switch (order)
			{
			case 0:
				girl--;
				cannot--;
				break;
			case 1:
				boy--;
				cannot--;
				break;
			case 2:
				boy--;
				cannot--;
				break;
			}
		}

		cout << min(girl / 2, boy) << endl;
	
	return 0;
}
