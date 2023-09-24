#include<iostream>
#include<map>
using namespace std;
int slide(int* arr, int sz,int target)
{
	int l = 0;
	int ans = sz+1;
	int s = 0;
	for (int r = 0; r < sz; r++) {
		s += arr[r];
		while (s - arr[l] >= target) {
			s -= arr[l];
			l++;
		}
		if (s >= target) {
			ans = ans > r-l+1 ? r-l+1 : ans;
		}
	}
	return ans <= sz + 1 ? ans : 0;
}
int slide1(int* arr, int sz, int k) {
	if (k <= 1) {
		return 0;
	}
	int l = 0;
	int s = 1;
	int ans = 0;
	for (int r = 0; r < sz; r++) {
		s *= arr[r];
		while (s >= k) {
			s /= arr[l];
			l++;
		}
		ans += r - l + 1;
	}
	return ans;
}
int slide2(const char* s) {
	int ans = 0;
	int l = 0;
	map<char, int> abc;
	for (int r = 0; r < strlen(s); r++) {
		abc[s[r]] ++;
		while (abc[s[r]] > 1) {
			abc[s[l]]--;
			l++;
		}
		ans = ans > r - l + 1 ? ans : r - l + 1;
	}
	return ans;
}
int main() {
	int arr[] = { 2,3,1,2,4,3 };
	int arr1[] = { 10,5,2,6 };
	const char* s =  "abcabcbb" ;
	int k = 100;
	int target = 7;
	cout << slide(arr, 6, target) << endl;
	cout << slide1(arr1, 4, k) << endl;
	cout << slide2(s) << endl;
	return 0;
}