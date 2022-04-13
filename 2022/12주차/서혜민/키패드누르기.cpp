#include <string>
#include <vector>

using namespace std;

int X[10] = { 4, 1, 1, 1, 2, 2, 2, 3, 3, 3 };
int Y[10] = { 2, 1, 2, 3, 1, 2, 3, 1, 2, 3 };

int dist(int aX, int aY, int bX, int bY){
    return abs(aX - bX) + abs(aY - bY);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lX = 4, lY = 1, rX = 4, rY = 3, mX, mY;
    for (int n : numbers) {
        if (n % 3 == 1) {
            answer += 'L';
            lX = X[n];
            lY = Y[n];
        }
        else if (!(n % 3) && n) {
            answer += 'R';
            rX = X[n];
            rY = Y[n];
        }
        else {
            mX = X[n];
            mY = Y[n];
            int lDist = dist(lX, lY, mX, mY);
            int rDist = dist(rX, rY, mX, mY);
            if (lDist > rDist) {
                answer += 'R';
                rX = mX;
                rY = mY;
            }
            else if (lDist < rDist) {
                answer += 'L';
                lX = mX;
                lY = mY;
            }
            else {
                if (hand == "left") {
                    answer += 'L';
                    lX = mX;
                    lY = mY;
                }
                else {
                    answer += 'R';
                    rX = mX;
                    rY = mY;
                }
            }
        }
    }
    return answer;
}