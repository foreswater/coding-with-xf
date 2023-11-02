#include<iostream>
using namespace std;
namespace Find_Spral_Substr {
	const char* s = "eacbba";
	int dp(int n) {
		int** f = new int* [n];
		for (int i = 0; i < n; i++) {
			f[i] = new int[n]();
		}
		for (int i = 0; i < n; i++) {
			f[i][i] = 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					f[i][j] = f[i + 1][j - 1] + 2;
				}
				else {
					f[i][j] = max(f[i + 1][j], f[i][j - 1]);
				}
			}
		}
		return f[0][n - 1];
	}
	int dfs(int i, int j) {
		if (i == j) {
			return 1;
		}
		if (i > j) {
			return 0;
		}
		if (s[i] == s[j]) {
			return dfs(i + 1, j - 1) + 2;
		}
		return max(dfs(i + 1, j), dfs(i, j - 1));
	}
	int Find_Spral_Substr() {
		if (!s) {
			return 0;
		}
		//return dfs(0, strlen(s) - 1);
		return dp(strlen(s));
	}
}
namespace Find_Min_Triangle {
	int value[] = { 1,2,3 };
	int dp(int n) {
		int** f = new int* [n];
		for (int i = 0; i < n; i++) {
			f[i] = new int[n]();
		}
		for (int i = n - 3; i >= 0; i--) {
			for (int j = i + 2; j < n; j++) {
				int res = INT_MAX;
				for (int k = i + 1; k < j; k++) {
					res = min(res, f[i][k] + f[k][j] + value[i] * value[j] * value[k]);
				}
				f[i][j] = res;
			}
		}
		return f[0][n - 1];
	}
	int dfs(int i, int j) {
		if (i + 1 == j) {
			return 0;
		}
		int res = INT_MAX;
		for (int k = i + 1; k < j; k++) {
			res = min(res, dfs(i, k) + dfs(k, j) + value[i] * value[j] * value[k]);
		}
		return res;
	}
	int Find_Min_Triangle() {
		if (!value) {
			return 0;
		}
		int n = sizeof(value) / sizeof(int);
		//return dfs(0, n - 1);
		return dp(n);
	}
}
int main() {
	cout << Find_Spral_Substr::Find_Spral_Substr() << endl;
	cout << Find_Min_Triangle::Find_Min_Triangle() << endl;
	return 0;
}