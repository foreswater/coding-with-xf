#include<iostream>
#include<map>
using namespace std;
string s1 = "abcde";
string s2 = "def";
map<pair<int, int>, int>memo;
int dp(int m, int n) {
	int** f = new int* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		f[i] = new int[n + 1]();
	}
	f[0][0] = 0;
	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n ; j++) {
			if (s1[i] == s2[j]) {
				f[i + 1][j + 1] = f[i][j] + 1;
			}
			else {
				f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
			}
		}
	}
	return f[m][n];
}
int dfs(int i, int j) {
	if (i < 0 || j < 0) {
		return 0;
	}
	if (memo[{i, j}] != 0) {
		return memo[{i, j}];
	}
	if (s1[i] == s2[j]) {
		int res = dfs(i - 1, j - 1) + 1;
		memo[{i, j}] = res;
		return res;
	}
	int res = max(dfs(i - 1, j), dfs(i, j - 1));
	memo[{i, j}] = res;
	return res;
}
int Find_public_substr() {
	if (!s1.size() || !s2.size()) {
		return 0;
	}
	int m = s1.size();
	int n = s2.size();
	//return dfs(m - 1, n - 1);
	return dp(m, n);
}
string s = "horse";
string t = "ros";
int dp1(int m, int n) {
	int** f = new int* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		f[i] = new int[n + 1]();
	}
	for (int i = 0; i < m ; i++) {
		f[i + 1][0] = i + 1;
	}
	for (int j = 0; j < n ; j++) {
		f[0][j + 1] = j + 1;
	}
	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] == t[j]) {
				f[i + 1][j + 1] = f[i][j];
			}
			else {
				f[i + 1][j + 1] = min(min(f[i][j], f[i][j + 1]), f[i + 1][j]) + 1;
			}
		}
	}
	return f[m][n];
}
map<pair<int, int>, int>cache;
int dfs1(int i, int j) {
	if (i < 0) {
		return j + 1;
	}
	if (j < 0) {
		return i + 1;
	}
	if (cache[{i, j}] != 0) {
		return cache[{i, j}];
	}
	if (s[i] == t[j]) {
		int res = dfs1(i - 1, j - 1);
		cache[{i, j}] = res;
		return res;
	}
	int res = min(min(dfs1(i - 1, j - 1), dfs1(i - 1, j)), dfs1(i, j - 1)) + 1;
	cache[{i, j}] = res;
	return res;
}
int Count_Op() {
	if (!s.size() || !t.size()) {
		return s.size() ? s.size() : t.size();
	}
	int m = s.size();
	int n = t.size();
	//return dfs1(m - 1, n - 1);
	return dp1(m, n);
}
int main() {
	cout << Find_public_substr() << endl;
	cout << Count_Op() << endl;
	return 0;
}
