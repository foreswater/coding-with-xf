#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>ans;
vector<int> path;
int n = 3;
int m = 4;
void dfs(int i) {
	if (n - path.size() > m - i) {
		return;
	}
	if (path.size() == n) {
		ans.push_back(path);
		return;
	}
	for (int j = i; j < m; j++) {
		path.push_back(j + 1);
		dfs(j + 1);
		path.pop_back();
	}
}
int s = 9;
int k = 3;
int arr[] = { 1,2,3,4,5,6,7,8,9 };
int sum(vector<int>& path) {
	int s = 0;
	for (auto i : path) {
		s += i;
	}
	return s;
}
bool need(vector<int>& path) {
	int su = sum(path);
	if ((su > s) || ((path.size() < k) && su == s))return 1;
	else if (su + 17 < s)return 1;
	else return 0;
}
void dfs2(int i) {
	if (need(path)) {
		return;
	}
	if (path.size() == k) {
		if (sum(path) == s)ans.push_back(path);
		return;
	}
	for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
		path.push_back(arr[j]);
		dfs2(j + 1);
		path.pop_back();
	}
}
void FindCom() {
	if (!s) {
		return;
	}
	dfs2(0);
}
vector<vector<string>>ans2;
vector<string> pat;
bool is_legal(vector<string>& path) {
	int left = 0;
	for (auto i : path) {
		if (i == "(") {
			left++;
		}
		else {
			left--;
		}
		if (left < 0) {
			return 0;
		}
	}
	
	return left == 0;
}
int open = 0;
void dfs3(int i) {
	if (pat.size() == 2 * n) {
		if (is_legal(pat))ans2.push_back(pat);
		return;
	}
	if (open < n) {
		pat.push_back("(");
		open++;
		dfs3(i + 1);
		pat.pop_back();
		open--;
	}
	if (i - open < open) {
		pat.push_back(")");
		dfs3(i + 1);
		pat.pop_back();
	}
}
void Findlegal() {
	if (!n) {
		return;
	}
	dfs3(0);
}
int main() {
	/*dfs(0);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	for (auto i : ans) {
		i.clear();
	}
	path.clear();*/
	Findlegal();
	for (auto i : ans2) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}