#include<iostream>
#include<ctime>
#include<map>
using namespace std;
int arr[] = { 17, 92, 42, 73, 56, 8, 19, 61, 84, 33, 79, 11, 9, 3, 72, 47, 50, 58, 44, 37, 6, 32, 15, 4, 20, 91, 63, 26, 64, 74, 13, 23, 31, 2, 96, 85, 87, 69, 30, 21, 66, 25, 78, 46, 18, 65, 53, 77, 22, 68, 60, 10, 88, 70, 55, 54, 36, 59, 38, 29, 75, 1, 41, 71, 7, 12, 27, 28, 89, 76, 16, 5, 24, 98, 80, 34, 83, 99, 14, 52, 40, 45, 49, 95, 51, 97, 43, 86, 35, 94, 39, 81, 62, 90, 82 };
map<int, int> memo;
int dfs(int i) {
	if (i < 0) {
		return 0;
	}
	if (memo[i] != 0) {
		return memo[i];
	}
	int res = max(dfs(i - 1), dfs(i - 2) + arr[i]);
	memo[i] = res;
	return res;
}
int rob1() {
	int n = sizeof(arr) / sizeof(int);
	int* f = new int[n];
	f[n - 1] = arr[n - 1];
	if (n > 1)f[n - 2] = max(arr[n - 1], arr[n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		f[i] = max(f[i + 1], f[i + 2] + arr[i]);
	}
	return f[0];
}
int rob2() {
	int n = sizeof(arr) / sizeof(int);
	int* f = new int[n + 2]();
	for (int i = 0; i < n; i++) {
		f[i + 2] = max(f[i + 1], f[i] + arr[i]);
	}
	return f[n + 1];
}
int main() {
	cout << dfs(sizeof(arr) / sizeof(int) - 1);
	cout << endl;
	cout << rob1();
	cout << endl;
	cout << rob2();
	return 0;
}
