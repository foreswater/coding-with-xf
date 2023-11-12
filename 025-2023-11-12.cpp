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
struct res {
	long long set_moti;
	long long moti_by_fa;
	long long moti_by_chi;
};
res dfs(node* i) {
	if (!i) {
		res N;
		N.set_moti = INT_MAX;
		N.moti_by_chi = 0;
		N.moti_by_fa = 0;
		return N;
	}
	res L, R, Res;
	L = dfs(i->left);
	R = dfs(i->right);
	Res.set_moti = min(L.set_moti, min(L.moti_by_chi, L.moti_by_fa)) + min(R.set_moti, min(R.moti_by_chi, R.moti_by_fa)) + 1;
	Res.moti_by_fa = min(L.moti_by_chi, L.set_moti) + min(R.moti_by_chi, R.set_moti);
	Res.moti_by_chi = min(L.set_moti + R.set_moti, min(L.set_moti + R.moti_by_chi, L.moti_by_chi + R.set_moti));
	return Res;
}
int Find_MIN_Motion(node* root) {
	if (!root) {
		return 0;
	}
	res R = dfs(root);
	return min(R.set_moti, R.moti_by_chi);
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
	cout << Find_MIN_Motion(head);
	return 0;
}