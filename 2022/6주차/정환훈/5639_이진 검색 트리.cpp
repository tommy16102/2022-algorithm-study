#include <bits/stdc++.h>
using namespace std;

struct node {

	node* left; node* right;
	int data;

};

vector<int> ns;
node* root = new node();
void input() {
	int t;
	while (cin >> t) { // 입력 개같다 정말
		if (t == EOF)
			break;
		ns.push_back(t);
	}
}

void insert(node*& root, int data) {

	if (root == NULL) { // 끝점 도달
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return;
	}
	if (data > root->data) { // 큰경우 우이동
		insert(root->right, data);
	}
	if (data < root->data) { // 작은경우 좌이동
		insert(root->left, data);
	}

}

void print(node* root) {
	if (root == NULL) {
		return;
	}

	if (root->left != NULL) // 왼쪽
		print(root->left);
	if (root->right != NULL) // 오른쪽
		print(root->right);
	cout << root->data << '\n'; // 루트 출력
}

void solve() {
	node* root = NULL;
	//insert(root, 50);
	//insert(root, 30);
	//insert(root, 24);
	//insert(root, 5); 
	//insert(root, 28);
	//insert(root, 45);
	//insert(root, 98);
	//insert(root, 52);
	//insert(root, 60);

	for (int i = 0; i < ns.size(); i++) {
		insert(root, ns[i]);
	}
	print(root);
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}