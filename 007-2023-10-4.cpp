#include<iostream>
using namespace std;
struct node {
	int value;
	node* next;
	node(int val = 0, node* next = NULL) {
		this->value = val;
		this->next = next;
	}
};
void loadlist(node* head,int* arr,int sz) {
	head->value = arr[0];
	node* pre = head;
	for (int i = 1; i < sz; i++) {
		node* cur = new node;
		cur->value = arr[i];
		pre->next = cur;
		pre = cur;
	}
	pre->next = NULL;
}
void showlist(node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
node* getmid(node* head) {
	node* fast = head;
	node* slow = head;
	while (fast&&fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
node* reverse(node* head) {
	node* pre = NULL;
	node* cur = head;
	while (cur) {
		node* nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	return pre;
}
node* merge(node* head) {
	node* mid = getmid(head);
	node* h2 = reverse(mid);
	node* h1 = head;
	node* h11 = head->next;
	node* h22 = h2->next;
	while (h22) {
		h1->next = h2;
		h2->next = h11;
		h2 = h22;
		h1 = h11;
		h22 = h2->next;
		h11 = h1->next;
	}
	return head;
}
bool isloop(node* head) {
	node* fast = head;
	node* slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return 1;
		}
	}
	return 0;
}
int findin(node* head) {
	node* fast = head;
	node* slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}
	while (!(head == slow)) {
		head = head->next;
		slow = slow->next;
	}
	return slow->value;
}
int main() {
	int arr[] = { 1,2,3,4,5 };
	node lis1;
	loadlist(&lis1, arr, sizeof(arr) / sizeof(int));
	showlist(&lis1);
	//node* mid = getmid(&lis1);
	//cout << mid->value;
	//showlist(reverse(&lis1));
	//showlist(merge(&lis1));
	lis1.next->next->next->next->next = lis1.next->next->next;
	cout << isloop(&lis1)<<endl;
	cout << findin(&lis1) << endl;
	return 0;
}