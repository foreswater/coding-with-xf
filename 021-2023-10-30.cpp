#include<iostream>
using namespace std;
namespace get_max_profit {
	int price[] = { 1,2,3,0,2 };
	int price_frozen[] = { 1,2,3,0,2 };
	int dp(int n) {
		int** f = new int* [n + 2];
		for (int i = 0; i < n + 2; i++) {
			f[i] = new int[2]();
		}
		f[1][1] = -INT_MAX;
		for (int i = 0; i < n; i++) {
			f[i + 2][1] = max(f[i + 1][1], f[i][0] - price[i]);
			f[i + 2][0] = max(f[i + 1][0], f[i + 1][1] + price[i]);
		}
		return f[n + 1][0];
	}
	int dfs(int i, bool hold) {
		if (i < 0) {
			if (hold) {
				return -INT_MAX;
			}
			else {
				return 0;
			}
		}
		if (hold) {
			return max(dfs(i - 1, 1), dfs(i - 2, 0) - price[i]);
		}
		else {
			return max(dfs(i - 1, 0), dfs(i - 1, 1) + price[i]);
		}
	}
	int Get_Max_Profit() {
		if (!price) {
			return 0;
		}
		int n = sizeof(price) / sizeof(int);
		//return dfs(n - 1, 0);
		return dp(n);
	}
}
namespace get_max_profit_k {
	int k = 2;
	int prices[] = { 3,2,6,5,0,3 };
	int dp(int n) {
		int*** f = new int** [n + 1];
		for (int i = 0; i < n + 1; i++) {
			f[i] = new int* [k + 2];
		}
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < k + 2; j++) {
				f[i][j] = new int[2]();
			}
		}
		for (int i = 0; i < n + 1; i++) {
			f[i][0][1] = -INT_MAX;
			f[i][0][0] = -INT_MAX;
		}
		for (int j = 0; j < k + 2; j++) {
			f[0][j][0] = 0;
			f[0][j][1] = -INT_MAX;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < k + 2; j++) {
				f[i + 1][j][1] = max(f[i][j][1], f[i][j][0] - prices[i]);
				f[i + 1][j][0] = max(f[i][j][0], f[i][j - 1][1] + prices[i]);
			}
		}
		return f[n][k + 1][0];
	}
	int dfs(int i, int j, bool hold) {
		if (j < 0) {
			return -INT_MAX;
		}
		if (i < 0) {
			if (hold) {
				return -INT_MAX;
			}
			else {
				return 0;
			}
		}
		if (hold) {
			return max(dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i]);
		}
		else {
			return max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i]);
		}
	}
	int Get_Max_Profit() {
		if (!prices) {
			return 0;
		}
		int n = sizeof(prices) / sizeof(int);
		//return dfs(n - 1, k, 0);
		return dp(n);
	}
}
int main() {
	cout << get_max_profit::Get_Max_Profit() << endl;
	cout << get_max_profit_k::Get_Max_Profit() << endl;
	return 0;
}