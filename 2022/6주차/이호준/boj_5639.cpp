/*******************************************************************
Algorithm Study
Baekjoon OJ BST
5639 이진 검색 트리
2022/02/22 이호준
# 아이디어
1. Binary Search Tree 성질 이용하여 BST 만들고 PostOrder로 출력하기
*******************************************************************/
#include <iostream>

using namespace std;

struct Node { int key; Node *left, *right; };

Node* makeTree(Node *node, int key) {
	if (node == NULL) {
		node = new Node();
		node->key = key;
		node->left = node->right = NULL;
	}
	else if (key < node->key) node->left = makeTree(node->left, key);
	else node->right = makeTree(node->right, key);
	return node;
}

void printTreePostOrder(Node *node) {
	if (node == NULL) return;
	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->key << '\n';
}

int main() {
	Node *tree = NULL;
	int temp;
	while (cin >> temp)
		tree = makeTree(tree, temp);
	printTreePostOrder(tree);
}