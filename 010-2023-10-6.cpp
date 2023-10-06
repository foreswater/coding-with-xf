#include<iostream>
#include<cmath>
#include<vector>
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
bool issame(node* head1, node* head2) {
	if (!(head1) || !(head2)) {
		return !(head1) && !(head2);
	}
	return head1->val==head2->val && issame(head1->left, head2->left) && issame(head1->right, head2->right);
}
bool f(node* head1,node* head2) {
	if (!(head1) || !(head2)) {
		return !(head1) && !(head2);
	}
	return head1->val == head2->val && f(head1->left, head2->right) && f(head1->right, head2->left);
}
bool issym(node* head) {
	if (!head) {
		return 1;
	}
	return f(head->left, head->right);
}
int depth(node* head) {
	if (!head) {
		return 0;
	}
	return max(depth(head->left), depth(head->right)) + 1;
}
bool isbalance1(node* head) {
	if (!head) {
		return 0;
	}
	return abs(depth(head->left) - depth(head->right)) <= 1;
}
int gethei(node* head) {
	if (!head) {
		return 0;
	}
	int l = gethei(head->left);
	if (l == -1) {
		return -1;
	}
	int r = gethei(head->right);
	if (r == -1 || abs(r - l) > 1) {
		return -1;
	}
	return max(r, l) + 1;
}
bool isbalance2(node* head) {
	if (!head) {
		return 0;
	}
	return !(gethei(head) == -1);
}
void getright(node* head,vector<int>& ans,int depth) {
	if (!head) {
		return;
	}
	if (ans.size() == depth) {
		ans.push_back(head->val);
	}

	getright(head->right, ans, depth + 1);
	getright(head->left, ans, depth + 1);
}
int main() {
	node tree1;
	node* head1 = &tree1;
	head1->left = new node;
	head1->right = new node;
	head1->val = 1;
	head1->left->val = 2;
	head1->right->val = 3;
	node tree2;
	node* head2 = &tree2;
	head2->left = new node;
	head2->right = new node;
	head2->val = 1;
	head2->left->val = 2;
	head2->right->val = 3;
	cout << issame(head1, head2) << endl;
	node tree3;
	node* head3 = &tree3;
	head3->left = new node;
	head3->right = new node;
	head3->left->left = new node;
	head3->left->right = new node;
	head3->right->left = new node;
	head3->right->right = new node;
	head3->val = 1;
	head3->left->val = 2;
	head3->right->val = 2;
	head3->left->left->val = 3;
	head3->right->right->val = 3;
	head3->left->right->val = 4;
	head3->right->left->val = 4;
	cout << issym(head3) << endl;
	node tree4;
	node* head4 = &tree4;
	head4->right = new node;
	head4->left = new node;
	head4->left->left = new node;
	head4->left->right = new node;
	head4->left->left->left = new node;;
	head4->left->left->right = new node;
	head4->val = 1;
	head4->left->val = 2;
	head4->right->val = 2;
	head4->left->left->val = 3;
	head4->left->right->val = 3;
	head4->left->left->left->val = 4;
	head4->left->left->right->val = 4;
	cout << isbalance1(head1) << " " << isbalance1(head2) << " " << isbalance1(head3) << endl;
	cout << isbalance1(head4) << endl;
	vector<int> ans;
	getright(head4, ans, 0);
	for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}