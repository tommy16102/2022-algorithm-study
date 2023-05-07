/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT
2023/05/02 이호준
# 아이디어
1. 구현
숫자 -> 2진수로 만들고 포화 이진트리로 만든다.
트리 탐색해서 표현가능한지 확인

어려운 점
* 문제의 명확한 이해가 필요하다.
* 결국 자신보다 조상의 루트 노드에 0이 존재했을 때 아래에서 1이 존재하면 안된다.
* 조상까지와의 관계를 생각했어야했다.
* 단순히 부모와 자식만의 관계만을 체크해서 이진트리를 만들 수 있냐여부를 판단하면 안된다.

// 111
//0101010
// 32  8  2 

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// 0 1 2 3 4 5 6 
// 0 1 2
// 0
*******************************************************************/
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeInfo{
    int depth;
    int size;
};

vector<int> convertToBinary(long long num){
    vector<int> binary;
    while(num > 0){
        if(num % 2 == 0){
            binary.push_back(0);
        }else{
            binary.push_back(1);
        }
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

TreeInfo calculateFullBinaryTreeSize(int size){
    int start = 0;
    int sum = 0;
    while(sum < size){
        sum += pow(2, start);
        start += 1;
    }
    
    return TreeInfo{start , sum};
}

vector<int> converToFullBinaryTree(vector<int> binary, int fullBinarySize){
    vector<int> fullBinaryTree(fullBinarySize, 0);
    for(int i = fullBinarySize - binary.size(), j = 0; i < fullBinarySize; i++, j++){
        fullBinaryTree[i] = binary[j];
    }
    return fullBinaryTree;
}


void isOkay(vector<int> tree, int rootNode, int depth, bool& answer, bool parentZero){

    if(parentZero && tree[rootNode]){
        answer = false;
        return;
    }
    
    if(depth == 0 || !answer) return;
    
    int leftNode = rootNode - depth;
    int rightNode = rootNode + depth;

    if (!tree[rootNode])
        parentZero = true;
    if(leftNode >= 0 && rightNode < tree.size()){
        isOkay(tree, leftNode, depth / 2, answer, parentZero);
        isOkay(tree, rightNode, depth / 2, answer, parentZero);
    }
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number : numbers){
        vector<int> binary = convertToBinary(number);
        TreeInfo treeInfo = calculateFullBinaryTreeSize(binary.size());
        vector<int> fullBinaryTree = converToFullBinaryTree(binary, treeInfo.size);
        bool flag = true;
        isOkay(fullBinaryTree, fullBinaryTree.size() / 2, pow(2,treeInfo.depth - 2), flag, !fullBinaryTree[fullBinaryTree.size() / 2]);
        if(flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}
