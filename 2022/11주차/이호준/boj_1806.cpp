#include <iostream>
#include <vector>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, s;

    cin >> n >> s;

    vector<int> inputs(n, 0);
    for(int i = 0; i< n; i++){
        cin >> inputs[i];
    }

    int left = 0; 
    int right = 0;

    int sum = 0;
    int answer = 10000000;

    while(left <= right){
        if(sum >= s){
            if(answer > right-left){
                answer = right - left;
            }
            sum-=inputs[left++];
        }else if (right == n) break;
        else sum+=inputs[right++];
    }

    cout << ((answer == 10000000) ? 0 : answer );

    return 0;
}