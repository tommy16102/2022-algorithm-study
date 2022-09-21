#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct NODE{
    int key; int y; int x;
    NODE* left; NODE* right;
    NODE(int K, int Y, int X) : key(K), y(Y), x(X), left(NULL), right(NULL) {}
}NODE;

void make_tree(NODE* root, NODE* node){
    if(root->x > node->x){
        if(root->left == NULL){
            root->left = node;
            return;
        }
        make_tree(root->left, node);
    }
    else{
        if(root->right == NULL){
            root->right = node;
            return;
        }
        make_tree(root->right, node);
    }
}

bool cmp(const NODE& n1, const NODE& n2){
    if(n1.y == n2.y){
        return n1.x < n2.x;
    }
    return n1.y > n2.y;
}

vector<int> pre;
void preorder(NODE* root){
    if(root == NULL)
        return;
    pre.push_back(root->key);
    preorder(root->left);
    preorder(root->right);
}
vector<int> post;
void postorder(NODE* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->key);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<NODE> nodes;
    for(int i=0;i<nodeinfo.size();i++){
        vector<int> node = nodeinfo[i];
        nodes.push_back(NODE(i+1, node[1], node[0]));
    }
    sort(nodes.begin(), nodes.end(), cmp);
    
    for(int i=1;i<nodes.size();i++)
        make_tree(&nodes[0], &nodes[i]);    
    
    preorder(&nodes[0]);
    postorder(&nodes[0]);
    
    vector<vector<int>> answer;
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
