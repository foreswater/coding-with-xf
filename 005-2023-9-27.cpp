#include<iostream>
using namespace std;
bool is_blue(int i,int target,int end) {
	if (i > end) {
		return i >= target && target > end;
	}
	else {
		return i >= target || target > end;
	}
}
int find_h(int* arr,int sz) {
	int l = -1;
	int r = sz - 1;
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] > arr[mid+1]) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	return r;
}
int find_h1(int* arr, int sz) {
	int l = -1;
	int r = sz - 2;
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		if (arr[mid]<arr[sz-1]) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	return r;
}
int find_h2(int* arr, int sz,int target) {
	int l = -1;
	int r = sz - 2;
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		if (is_blue(arr[mid], target, arr[sz - 1])) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if (r == sz || arr[r] != target) {
		return -1;
	}
	else {
		return r;
	}
}
int main() {
	int arr[] = { 1,2,3,1 };
	int arr1[] = { 4,5,6,7,0,1,2 };
	int arr2[] = { 4,5,6,7,0,1,2 };
	cout << find_h(arr, sizeof(arr) / sizeof(int)) << endl;
	cout << find_h1(arr1, sizeof(arr1) / sizeof(int)) << endl;
	cout << find_h2(arr2, sizeof(arr2) / sizeof(int), 0);
	return 0;
}