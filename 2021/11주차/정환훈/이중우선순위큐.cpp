vector<int> solution(vector<string> operations) {
    
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    int num = 0;

    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int operand = stoi(operations[i].substr(2));

        if (op == 'D') {
            if (num == 0) { // 아무것도 없으면 그냥 무시
                continue;
            }
            else if (min_heap.empty()) { // max만 존재
                
                if (operand == 1) { // 최댓값 구할 때는 그냥
                    max_heap.pop(); // max 하나 없앰
                    num--;
                }
                else if (operand == -1) { // 최솟값 구할 때는 마지막 친구 빼야 함
                    priority_queue<int, vector<int>, less<int>> temp;
                    while (max_heap.size() > 1) {
                        temp.push(max_heap.top());
                        max_heap.pop();
                    }
                    max_heap = temp;
                    num--;
                }

            }
            else if (max_heap.empty()) { // min만 존재
                if (operand == -1) { // 최솟값 구할때는 그냥
                    min_heap.pop();
                    num--;
                }
                else if (operand == 1) { // 최댓값 구할 때는 마지막 친구를 빼야함
                    priority_queue<int, vector<int>, greater<int>> temp;
                    while (min_heap.size() > 1) {
                        temp.push(min_heap.top());
                        min_heap.pop();
                    }
                    min_heap = temp;
                    num--;
                }
            }
            else { // 둘다 존재
                if (operand == -1) { // 최솟값 없애래
                    min_heap.pop();
                    num--;
                }
                else if (operand == 1) { // 최댓값 없애래
                    max_heap.pop();
                    num--;
                }
            }

        }
        else if (op == 'I') { // 추가
            if (operand >= 0) { // 양수 추가
                max_heap.push(operand); // max heap
            }
            else {
                min_heap.push(operand);
            }
            num++;
        }
    }

    if (num == 0) { // 모든 큐가 비어잇음
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (min_heap.empty() && !max_heap.empty()) { // max heap만 존재
        int max = max_heap.top(); // 첫번째 값이 최대
        while (max_heap.size() > 1) {
            max_heap.pop();
        }
        int min = max_heap.top(); // 마지막 값이 최소
        answer.push_back(max);
        answer.push_back(min);
    }

    else if (max_heap.empty() && !min_heap.empty()) { // min heap만 존재
        int min = min_heap.top(); // 첫번째 값이 최소
        while (min_heap.size() > 1) {
            min_heap.pop();
        }
        int max = min_heap.top(); // 마지막 값이 최대
        answer.push_back(max);
        answer.push_back(min);
    }

    else { // 둘다 존재
        answer.push_back(max_heap.top()); // 최대
        answer.push_back(min_heap.top()); // 최소
    }

    return answer;
}