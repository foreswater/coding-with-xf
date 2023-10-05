#include<iostream>
using namespace std;
int ans = 0;
struct node {
	int val;
	node* left;
	node* right;
	node(int val=0, node* left=NULL, node* right=NULL) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
};
int depth(node* head) {
	if (!head) {
		return 0;
	}
	int l = depth(head->left);
	int r = depth(head->right);
	return max(l, r) + 1;
}
void depth2(node* head,int cnt) {
	if (!head) {
		return;
	}
	cnt++;
	ans = cnt > ans ? cnt : ans;
	depth2(head->left, cnt);
	depth2(head->right, cnt);
}
int main() {
	node tree;
	node* head = &tree;
	head->val = 3;
	head->left = new node;
	head->right = new node;
	head->right->left = new node;
	head->right->right = new node;
	head->left->val = 9;
	head->right->val = 20;
	head->right->left->val = 15;
	head->right->right->val = 7;
	head->left->left = NULL;
	head->left->right = NULL;
	head->right->left->left = NULL;
	head->right->left->right = NULL;
	head->right->right->left = NULL;
	head->right->right->right = NULL;
	cout << depth(head)<<endl;
	depth2(head, 0);
	cout << ans << endl;
	return 0;
}