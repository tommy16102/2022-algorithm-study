#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum;
    int answer = 0;
    cin >> n >> sum;

    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 1; i <= n; i++)
    {
        vector<bool> combination(n, false);
        for (int j = n - i; j < n; j++)
        {
            combination[j] = true;
        }

        do
        {
            int test = 0;
            for (int i = 0; i < n; i++)
            {
                if (combination[i])
                    test += value[i];
            }
            if (test == sum)
                answer++;

        } while (next_permutation(combination.begin(), combination.end()));
    }

    cout << answer;

    return 0;
}