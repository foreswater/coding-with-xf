#include<iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
	Node(int value = 0,Node* next = NULL) {
		this->value = value;
		this->next = next;
	}
	void loadnode(Node* head,int* arr,int sz) {
		for (int i = 0; i < sz-1; i++) {
			head->value = arr[i];
			head->next = new Node;
			head = head->next;
		}
		head->value = arr[sz - 1];
		head->next = NULL;
	}
	void showlist(Node* head) {
		while (head) {
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl;
	}
	static Node* reverse(Node* head) {
		Node* cur = head;
		Node* pre = NULL;
		Node* nex = NULL;
		while (cur) {
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}
	int Nodecount(Node* head) {
		int c = 0;
		while (head) {
			c++;
			head = head->next;
		}
		return c;
	}
};
Node* reversek(Node* head,int l,int r) {
	Node soct;
	soct.next = head;
	Node* soc = &soct;
	Node* h = soc;
	Node* p1 = soc;
	while (soc->value != l) {
		p1 = soc;
		soc = soc->next;
	}
	Node* h1 = soc;
	Node* h2 = h1;
	for (int i = 0; i < r - l;i++) {
		h2 = h2->next;
	}
	Node* p2 = h2->next;
	h2->next = NULL;
	h2 = h1;
	h1 = Node::reverse(h1);
	p1->next = h1;
	h2->next = p2;
	return h->next;
}
Node* reverse_k(Node* head,int k) {
	int num = (*head).Nodecount(head);
	int l = 1;
	int r = l + k - 1;
	while (num >= k) {
		head = reversek(head, l, r);
		l = r + 1;
		r = l + k - 1;
		num -= k;
	}
	return head;
}
int main() {
	int arr[] = { 1,2,3,4,5 };
	Node head;
	Node* lis = &head;
	head.loadnode(&head, arr, sizeof(arr) / sizeof(int));
	head.showlist(&head);
	//lis = head.reverse(&head);
	//head.showlist(lis);
	//lis = reversek(lis, 1, 2);
	//head.showlist(lis);
	//lis = reversek(lis, 3, 4);
	//head.showlist(lis);
	lis = reverse_k(lis, 3);
	head.showlist(lis);

	return 0;
}