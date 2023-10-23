#include<iostream>
#include<map>
using namespace std;
int arr[] = { 1,1,1,1,1 };
map<pair<int, int>, int> memo;
int dfs(int i, int c) {
	if (i < 0) {
		return c == 0 ? 1 : 0;
	}
	if (memo[{i, c}] != 0) {
		return memo[{i, c}];
	}
	if (c < arr[i]) {
		int res = dfs(i - 1, c);
		memo[{i, c}] = res;
		return res;
	}
	int res = dfs(i - 1, c) + dfs(i - 1, c - arr[i]);
	memo[{i, c}] = res;
	return res;
}
int dp(int n, int target) {
	int** f = new int* [n + 1];
	for (int i = 0; i < n + 1 ; i++) {
		f[i] = new int[target + 1]();
	}
	f[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < target + 1; c++) {
			if (c < arr[i]) {
				f[i + 1][c] = f[i][c];
			}
			else {
				f[i + 1][c] = f[i][c] + f[i][c - arr[i]];
			}
		}
	}
	return f[n][target];
}
int bag(int target) {
	int sum = 0;
	for (auto i : arr) {
		sum += i;
	}
	if ((sum + target) % 2 != 0 || (sum + target) < 0) {
		return 0;
	}
	return dfs(sizeof(arr) / sizeof(int) - 1, (target+sum) / 2);
	//return dp(sizeof(arr) / sizeof(int), (target + sum) / 2);
}
int coins[] = { 1,2,5 };
map<pair<int, int>, long long> cache;
long long dfs1(int i, int c) {
	if (i < 0) {
		return c == 0 ? 0 : static_cast<long long>(INT_MAX);
	}
	if (cache[{i, c}] != 0) {
		return cache[{i, c}];
	}
	if (c < coins[i]) {
		long long res = dfs1(i - 1, c);
		cache[{i, c}] = res;
		return res;
	}
	long long res = min(dfs1(i - 1, c), dfs1(i, c - coins[i]) + 1);
	cache[{i, c}] = res;
	return res;
}
int dp1(int n, int amount) {
	long long** f = new long long* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		f[i] = new long long[amount + 1];
		for (int j = 0; j < amount + 1; j++) {
			f[i][j] = static_cast<long long>(INT_MAX);
		}
		
	}
	f[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < amount + 1; c++) {
			if (c < coins[i]) {
				f[i + 1][c] = f[i][c];
			}
			else {
				f[i + 1][c] = min(f[i][c], f[i + 1][c - coins[i]] + 1);
			}
		}
	}
	return f[n][amount];
}
int charge(int amount) {
	if (!amount) {
		return -1;
	}
	//int res = dfs1(sizeof(coins) / sizeof(int) - 1, amount);
	int res = dp1(sizeof(coins) / sizeof(int), amount);
	if (abs(res) != INT_MAX)return res;
	else return -1;
}
int main() {
	//p s-p p-(s-p)=t p=(s+t)/2
	//cout << bag(3) << endl;
	cout << charge(11) << endl;
	return 0;
}