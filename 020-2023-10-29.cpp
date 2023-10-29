#include<iostream>
#include<map>
#include<vector>
using namespace std;
int arr[] = { 10,9,2,5,3,7,101,18 };
map<int, int> cache;
int dp(int n) {
	int* f = new int[n]();
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				res = max(f[j], res);
			}
		}
		f[i] = res + 1;
	}
	int M = 0;
	for (int i = 0; i < n; i++) {
		M = max(f[i], M);
	}
	return M;
}
int dfs(int i) {
	if (i < 0) {
		return 0;
	}
	int res = 0;
	for (int j = i; j >= 0; j--) {
		if (arr[j] < arr[i]) {
			res = max(dfs(j), res);
		}
	}
	return res + 1;
}
int Find_longest_subarry() {
	if (!arr) {
		return 0;
	}
	/*int M = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		M = max(dfs(i), M);
	}*/

	return dp(sizeof(arr) / sizeof(int));
}
int LengthofLIS() {
	vector<int> g;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		auto x = lower_bound(g.begin(), g.end(), arr[i]);
		if (x == g.end()) {
			g.push_back(arr[i]);
		}
		else {
			*x = arr[i];
		}
	}
	return g.size();
}
int main() {
	cout << Find_longest_subarry() << endl;
	cout << LengthofLIS();
	return 0;
}