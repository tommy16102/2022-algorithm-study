#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// bool comapre(string & a, string &b){
//     if(a.size())
// }

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        vector<string> inputs(n, "");

        for(int i =0 ;i<n; i++){
            cin >> inputs[i];
        }

        sort(inputs.begin(), inputs.end());
        // for(auto a : inputs){
        //     cout << a << " \n";
        // }

        bool isThere = false;
        
        for(int i = 0; i< n-1; i++){
            int index = inputs[i+1].find(inputs[i]);
            if( index != string::npos && index == 0){
                isThere = true;
                break;
            }
        }
        cout << ((isThere ? "NO" : "YES")) << "\n";
    }


    return 0;
}