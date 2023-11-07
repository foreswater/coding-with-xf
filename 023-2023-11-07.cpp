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
int ans = 0;
int dfs(node* i) {
	if (!i) {
		return -1;
	}
	int l_len = dfs(i->left);
	int r_len = dfs(i->right);
	ans = max(ans, l_len + r_len + 2);
	return max(l_len, r_len) + 1;
}
void diametorOfTree(node* head) {
	if (!head) {
		return;
	}
	dfs(head);
}
int dfs1(node* i) {
	if (!i) {
		return 0;
	}
	int l_sum = dfs1(i->left);
	int r_sum = dfs1(i->right);
	ans = max(ans, l_sum + r_sum + i->val);
	return max(max(l_sum, r_sum) + i->val, 0);
}
void MaxValTree(node* head) {
	if (!head) {
		return;
	}
	dfs1(head);
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
	head->left->left->val = -1;
	head->left->right->val = -3;
	head->left->right->left->val = 4;
	//iametorOfTree(head);
	MaxValTree(head);
	cout << ans << endl;
	return 0;
}