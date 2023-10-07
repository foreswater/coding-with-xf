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
node* pro(node* head,node* p,node* q) {
	if ((!head) || (head == p) || (head == q)) {
		return head;
	}
	node* le = pro(head->left, p, q);
	node* ri = pro(head->right, p, q);
	if (le && ri) {
		return head;
	}
	else if (le) {
		return le;
	}
	else if (ri) {
		return ri;
	}
	else {
		return NULL;
	}
}
node* pro1(node* head, node* p, node* q) {
	if (head->val > p->val && head->val > q->val) {
		return pro1(head->left, p, q);
	}
	if (head->val < p->val && head->val < q->val) {
		return pro1(head->right, p, q);
	}
	return head;
}
node* path(node* head, node* q,vector<node>& pat) {
	if (head == NULL) {
		return head;
	}
	if (head == q) {
		pat.push_back(*head);
		return head;
	}
	node* le = path(head->left, q, pat);
	node* ri = path(head->right, q, pat);
	if (le||ri) {
		pat.push_back(*head);
		return q;
	}
	else {
		return NULL;
	}
}
int main() {
	node tree;
	node* root = &tree;
	root->left = new node;
	root->right = new node;
	root->left->left = new node;
	root->left->right = new node;
	root->right->left = new node;
	root->right->right = new node;
	root->left->right->left = new node;
	root->left->right->right = new node;
	root->val = 3;
	root->left->val = 5;
	root->right->val = 1;
	root->left->left->val = 6;
	root->left->right->val = 2;
	root->right->left->val = 0;
	root->right->right->val = 8;
	root->left->right->left->val = 7;
	root->left->right->right->val = 4;
	cout << pro(root, root->left->left, root->right->right)->val << endl;
	node tree1;
	node* root1 = &tree1;
	root1->left = new node;
	root1->right = new node;
	root1->left->left = new node;
	root1->left->right = new node;
	root1->right->left = new node;
	root1->right->right = new node;
	root1->left->right->left = new node;
	root1->left->right->right = new node;
	root1->val = 6;
	root1->left->val = 2;
	root1->right->val = 8;
	root1->left->left->val = 0;
	root1->left->right->val = 4;
	root1->right->left->val = 7;
	root1->right->right->val = 9;
	root1->left->right->left->val = 3;
	root1->left->right->right->val = 5;
	cout << pro1(root1, root1->left->left, root1->left->right->right)->val;
	return 0;
}
