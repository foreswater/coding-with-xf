#include<iostream>
using namespace std;
int pre = INT_MIN;
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
struct ans {
	int l;
	int r;
	ans(int l = 0, int r = 0) {
		this->l = l;
		this->r = r;
	}
};
bool isBST(node* head,int left = INT_MIN,int right = INT_MAX) {
	if (!head) {
		return 1;
	}
	int x = head->val;
	return left<x && right>x && isBST(head->left, left, x) && isBST(head->right, x, right);
}
void f(node* head) {
	if (!head) {
		return;
	}
	f(head->left);
	int val = head->val;
	if (pre < val) {
		pre = val;
	}
	else {
		pre = INT_MAX;
	}
	f(head->right);
}
bool isBST2(node* head) {
	if (!head) {
		return 0;
	}
	f(head);
	return pre != INT_MAX;
}
ans f2(node* head) {
	if (!head) {
		ans b(INT_MAX, INT_MIN);
		return b;
	}
	ans le = f2(head->left);
	ans ri = f2(head->right);
	if (head->val > le.r && head->val < ri.l) {
		ans a(min(le.l, head->val), max(ri.r, head->val));
		return a;
	}
	ans b1(INT_MIN, INT_MAX);
	return  b1;
}
bool isBST3(node* head) {
	if (!head) {
		return 0;
	}
	return f2(head).r != INT_MAX;
}
int main() {
	node tree;
	node* head = &tree;
	head->left = new node;
	head->right = new node;
	head->left->left = new node;
	head->left->right = new node;
	head->left->right->left = new node;
	head->val = 5;
	head->left->val = 2;
	head->right->val = 6;
	head->left->left->val = 1;
	head->left->right->val = 4;
	head->left->right->left->val = 3;
	cout << isBST(head) << endl;
	cout << isBST2(head) << endl;
	cout << isBST3(head) << endl;
	return 0;
}