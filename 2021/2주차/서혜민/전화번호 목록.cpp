#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*

2021.07.19 서혜민

sort를 통해서 정렬이 될 때 벡터 내의 각 숫자들은
앞에서부터 각각 비교하여 더 큰 수가 뒤에 위치하게 되는 과정을 거치게 된다.
결국 이를 통해서 어떤 수의 옆에 위치한 수는 다른 위치에 있는 수들보다
앞에서부터 차이가 덜 나는 비슷한 숫자를 가지게 된다.

그래서 한 숫자가 그 숫자의 옆에 있는 숫자에서 발견된 시작된 위치가 0이라면
이 숫자는 접두어가 되므로 false를 리턴한다.

*/

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0;i < phone_book.size();i++) {
        cout << phone_book[i] << endl;
    }
    for (int i=0;i<phone_book.size()-1;i++)
    {
        if (phone_book[i + 1].find(phone_book[i]) == 0) return false;
    }
    return true;
}

int main() {
    cout << solution({ {"123"},{"12"},{"125"},{"567"},{"88"}});
}

