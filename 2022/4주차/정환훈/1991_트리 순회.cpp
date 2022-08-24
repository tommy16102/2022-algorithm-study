#include <bits/stdc++.h>
using namespace std;
int n;
class Node {
public:
	char data;
	Node* left;
	Node* right;
	Node() {
		left = NULL; right = NULL; data = ' ';
	}
	Node(Node* l, Node* r, char d) {
		left = l; right = r; data = d;
	}
	void print() {
		cout << data;
	}
};

Node nodes[30];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		nodes[i].data = 'A' + i;
	}

	for (int i = 0; i < n; i++) {
		char p;
		char l;
		char r;
		cin >> p >> l >> r;
		int now = p - 'A';
		int left = l - 'A';
		int right = r - 'A';
		Node* lnode = NULL;
		Node* rnode = NULL;
		if (l != '.')
			lnode = &nodes[left];
		if (r != '.')
			rnode = &nodes[right];
		nodes[now] = Node(lnode, rnode, p);
	}
}

void preorder(Node* node) {
	// 자신
	if (node != NULL) {
		node->print();
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node* node) {
	if (node != NULL) {
		inorder(node->left);
		node->print();
		inorder(node->right);
	}
}
void postorder(Node* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		node->print();
	}
}

void solve() {
	Node* root = &nodes[0];
	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}