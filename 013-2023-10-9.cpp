#include<iostream>
#include<vector>
#include<deque>
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
void pro1(node* head, vector<int>& ans) {
	if (!head) {
		return;
	}
	vector<node*> arr1, arr2;
	arr1.push_back(head);
	ans.push_back(head->val);
	while (arr1.size()) {
		for (vector<node*>::iterator i = arr1.begin(); i != arr1.end(); i++) {
			if ((*i)->left) {
				arr2.push_back((*i)->left);
				ans.push_back((*i)->left->val);
			}
			if ((*i)->right) {
				arr2.push_back((*i)->right);
				ans.push_back((*i)->right->val);
			}
		}
		arr1 = arr2;
		arr2.clear();
	}
}
void pro2(node* head, vector<int>& ans) {
	if (!head) {
		return;
	}
	deque<node*> arr;
	arr.push_back(head);
	ans.push_back(head->val);
	while (arr.size()) {
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->left) {
				arr.push_back(arr[i]->left);
				ans.push_back(arr[i]->left->val);
			}
			if (arr[i]->right) {
				arr.push_back(arr[i]->right);
				ans.push_back(arr[i]->right->val);
			}
			cnt++;
		}
		while (cnt--) {
			arr.pop_front();
		}
	}
}
void pro3(node* head, vector<int>& ans) {
	if (!head) {
		return;
	}
	deque<node*> arr;
	arr.push_back(head);
	ans.push_back(head->val);
	bool even = 0;
	while (arr.size()) {
		int cnt = 0;
		int sz = arr.size();
		for (int i = 0; i < sz; i++) {
			if (arr[i]->left) {
				arr.push_back(arr[i]->left);
			}
			if (arr[i]->right) {
				arr.push_back(arr[i]->right);
			}
			cnt++;
		}
		while (cnt--) {
			arr.pop_front();
		}
		if (even)
			for (int i = 0; i < arr.size(); i++) {
				ans.push_back(arr[i]->val);
			}
		else {
			for (int i = arr.size()-1; i >= 0; i--) {
				ans.push_back(arr[i]->val);
			}
		}
		even = !even;
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
	root->left->right->left = new node;
	root->right->left->left = new node;
	root->right->left->right = new node;
	root->val = 1;
	root->left->val = 2;
	root->right->val = 3;
	root->left->left->val = 4;
	root->left->right->val = 5;
	root->right->left->val = 6;
	root->left->right->left->val = 7;
	root->right->left->left->val = 8;
	root->right->left->right->val = 9;
	vector<int> ans;
	pro1(root, ans);
	for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	vector<int> ans1;
	pro2(root, ans1);
	for (vector<int>::iterator i = ans1.begin(); i != ans1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	ans1.clear();
	pro3(root, ans1);
	for (vector<int>::iterator i = ans1.begin(); i != ans1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}