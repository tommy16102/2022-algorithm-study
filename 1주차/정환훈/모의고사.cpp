#include <string>
#include <vector>

using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : 정말로 a, b, c의 답안을 작성한 후 채점한다.
    마지막에 줄세우기.

*/

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> a(10000, 0);
    vector<int> b(10000, 0);
    vector<int> c(10000, 0);

    int i = 0;
    int k = 1;
    while (true) {

        a[i] = k;
        i++;
        k++;

        if (k % 6 == 0)
            k = 1;

        if (answers.size() == i)
            break;

    }

    i = 0; k = 1;

    while (true) {

        if (i % 2 == 0)
            b[i] = 2;
        else {
            if (k == 2) {
                k++; continue;
            }
            b[i] = k;
            k++;
            if (k % 6 == 0)
                k = 1;
        }
        i++;
        if (answers.size() == i)
            break;
    }

    i = 0; k = 1;
    while (true) {
        if (i % 2 == 1)
            c[i] = c[i - 1];
        else {
            if (k == 6) k = 1;

            switch (k) {
            case 1:
                c[i] = 3;
                k++;
                break;
            case 2:
                c[i] = 1;
                k++;
                break;
            case 3:
                c[i] = 2;
                k++;
                break;
            case 4:
                c[i] = 4;
                k++;
                break;
            case 5:
                c[i] = 5;
                k++;
                break;
            }
        }
        i++;
        if (answers.size() == i)
            break;

    }
    int a_correct = 0;
    int b_correct = 0;
    int c_correct = 0;


    for (int i = 0; i < answers.size(); i++) {
        if (a[i] == answers[i])
            a_correct++;
        if (b[i] == answers[i])
            b_correct++;
        if (c[i] == answers[i])
            c_correct++;
    }

    int max = -1;

    if (max < a_correct)
        max = a_correct;
    if (max < b_correct)
        max = b_correct;
    if (max < c_correct)
        max = c_correct;

    if (max == a_correct)
        answer.push_back(1);
    if (max == b_correct)
        answer.push_back(2);
    if (max == c_correct)
        answer.push_back(3);

    return answer;
}