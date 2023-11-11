#include<iostream>
using namespace std;
struct node {
	int val;
	node* left;
	node* right;
	node(int val = 0, node* left = NULL, node* right = NULL) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
};
pair<int,int> dfs(node* i) {
	if (!i) {
		return { 0,0 };
	}
	pair<int, int> L = dfs(i->left);
	pair<int, int> R = dfs(i->right);
	pair<int, int> res;
	res.first = L.second + R.second + i->val;
	res.second = max(L.first, L.second) + max(R.first, R.second);
	return res;
}
int ROB(node* root) {
	if (!root) {
		return 0;
	}
	pair<int,int> res = dfs(root);
	return max(res.first, res.second);
}
int main() {
	node tree;
	node* head = &tree;
	head->left = new node;
	head->right = new node;
	head->left->left = new node;
	head->right->right = new node;
	head->val = 2;
	head->left->val = 1;
	head->left->left->val = 6;
	head->right->val = 6;
	head->right->right->val = 1;
	cout << ROB(head);
	return 0;
}