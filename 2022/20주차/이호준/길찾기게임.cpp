/*******************************************************************
Algorithm Study
2019 Kakao Blind
길 찾기 게임 level 3
2022/09/21 이호준
# 아이디어
1. BST 구현
오랜만에 Tree 구현과 Tree retrieve를 구핸혀봤다.
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Node {
public:
    int index;
    int x;
    int y;
    Node* left;
    Node* right;
    Node(int index, int x, int y, Node* left, Node* right){
        this->index = index;
        this->x = x;
        this->y = y;
        this->left = left;
        this->right = right;
    }
};

bool compare(Node& a, Node& b){
    if(a.y == b.y){
        return a.x < b.x;
    }else{
        return a.y > b.y;
    }
}

void makeTree(Node* root, Node* node){
    if(root->x > node->x){
        if(root->left == NULL){
            root->left = node;
            return;
        }else{
            makeTree(root->left, node);
        }
    }else{
        if(root->right == NULL){
            root->right = node;
            return;
        }else{
            makeTree(root->right, node);
        }
    }
}

void preOrderRetrieve(Node* tree, vector<int>& print){
    if(tree == NULL){
        return;
    }
    print.push_back(tree->index);
    preOrderRetrieve(tree->left, print);
    preOrderRetrieve(tree->right, print);
}

void postOrderRetrieve(Node* tree, vector<int>& print){
    if(tree == NULL){
        return;
    }
    postOrderRetrieve(tree->left, print);
    postOrderRetrieve(tree->right, print);
    print.push_back(tree->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;

    for (int i = 0 ; i < nodeinfo.size(); i++){
        nodes.push_back(Node(i + 1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL));
    }
    
    sort(nodes.begin(), nodes.end(), compare);
    
    for(int i = 1 ; i< nodes.size(); i++){
        makeTree(&nodes[0], &nodes[i]);
    }
    
    vector<int> preOrder;
    vector<int> postOrder;
    
    preOrderRetrieve(&nodes[0], preOrder);
    postOrderRetrieve(&nodes[0], postOrder);
    
    answer.push_back(preOrder);
    answer.push_back(postOrder);
    
    return answer;
}