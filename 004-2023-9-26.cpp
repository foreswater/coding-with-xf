#include<iostream>
using namespace std;
int div(int* arr, int sz,int target) {
	int l = 0;
	int r = sz - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}
void equal(int* arr, int sz, int target) {
	int l = div(arr, 6, target);
	if (arr[l] != target) {
		return;
	}
	int r = div(arr, 6, target+1) - 1;
	for (int i = l; i <= r; i++) {
		cout << arr[i] << " " ;
	}
}
int main() {
	int arr[] = { 5,7,7,9,9,10 };
	cout << div(arr, 6, 8)<<endl;
	cout << div(arr, 6, 9) - 1 << endl;
	equal(arr, 6, 8);
	return 0;
}