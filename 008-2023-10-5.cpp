#include<iostream>
using namespace std;
struct node {
	int value;
	node* next;
	node(int value = 0, node* next = NULL) {
		this->value = value;
		this->next = next;
	}
};
node* loadlist(node* head,int* arr,int sz) {
	head->value = arr[0];
	head->next = NULL;
	node* h1 = head;
	for (int i = 1; i < sz; i++) {
		node* cur = new node;
		cur->value = arr[i];
		h1->next = cur;
		h1 = h1->next;
	}
	return head;
}
void showlist(node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
node* delenode(node* head,node* dele) {
	if (!(dele->next)) {
		while (!(head->next==dele)) {
			head = head->next;
		}
		head->next = NULL;
		delete dele;
		return head;
	}
	node* need = dele->next;
	dele->value = need->value;
	dele->next = dele->next->next;
	return head;
}
node* delenode_n(node* head, int n) {
	node du;
	node* dummy = &du;
	dummy->next = head;
	node* l = dummy;
	node* r = dummy;
	for (int i = 0; i < n; i++) {
		r = r->next;
	}
	while (r->next) {
		l = l->next;
		r = r->next;
	}
	l->next = l->next->next;
	return dummy->next;
}
void del2(node* head) {
	node* cur = head;
	node* nex = head;
	while (cur && cur->next) {
		while (nex->next && nex->value == nex->next->value) {
			nex = nex->next;
		}
		cur->next = nex->next;
		cur = cur->next;
		nex = cur;
	}
}
node* del3(node* head) {
	node du;
	node* dummy = &du;
	dummy->next = head;
	node* cur = dummy;
	while (cur->next && cur->next->next) {
		int val = cur->next->value;
		if (val == cur->next->next->value) {
			while (cur->next && cur->next->value == val) {
				cur->next = cur->next->next;
			}
		}
		else {
			cur = cur->next;
		}
	}
	return dummy->next;
}
int main() {
	int arr[] = { 1,1,1,2,3,3,4,5,5 };
	node head;
	node* lis1 = &head;
	lis1 = loadlist(lis1, arr, sizeof(arr) / sizeof(int));
	showlist(lis1);
	//lis1 = delenode(lis1, lis1->next->next);
	//showlist(lis1);
	//lis1 = delenode_n(lis1, 5);
	//showlist(lis1);
	//del2(lis1);
	//showlist(lis1);
	lis1 = del3(lis1);
	showlist(lis1);
	return 0;
}