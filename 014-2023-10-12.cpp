#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<string> MAPPING = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
vector<string> ans;
string path;
string num;
void dfs1(int i) {
	if (num.size() == i) {
		ans.push_back(path);
		return;
	}

	for (int j = 0; j < MAPPING[static_cast<int>(num[i]) - 48].size(); j++) {
		path[i] = MAPPING[static_cast<int>(num[i]) - 48][j];
		dfs1(i + 1);
	}
}
int arr[] = { 1,2,4 };
const int sz = sizeof(arr) / sizeof(int);
vector<vector<int>> ans2;
vector<int> ziji;
void dfs2(int i) {
	if (sz == i) {
		ans2.push_back(ziji);
		return;
	}
	dfs2(i + 1);
	ziji.push_back(arr[i]);
	dfs2(i + 1);
	ziji.pop_back();
}
void dfs3(int i) {
	ans2.push_back(ziji);
	if (sz == i) {
		return;
	}
	for (int j = i; j < sz; j++) {
		ziji.push_back(arr[j]);
		dfs3(j + 1);
		ziji.pop_back();
	}
}
string s = "aab";
vector<vector<string>> ans3;
vector<string> pat;
void copy_n(string& a, string& b, int bg, int ed) {
	int j = 0;
	for (int i = bg; i < ed; i++) {
		a[j] = b[i];
		j++;
	}
}
bool is_spiral(string a) {
	if (!a.size()) {
		return 0;
	}
	int bg = 0;
	int ed = a.size() - 1;
	while (bg < ed) {
		if (a[bg] == a[ed]) {
			bg++;
			ed--;
		}
		else {
			return 0;
		}
	}
	return 1;
}
void dfs4(int i) {
	if (i == s.size()) {
		ans3.push_back(pat);
		return;
	}
	for (int j = i; j < s.size(); j++) {
		string t;
		t.resize(j + 1 - i);
		copy_n(t, s, i, j + 1);
		if (is_spiral(t)) {
			pat.push_back(t);
			dfs4(j + 1);
			pat.pop_back();
		}
	}
}

void partition() {
	if (!s.size()) {
		return;
	}
	dfs4(0);
}
int main() {
	num = "27";
	path.resize(num.size());
	dfs1(0);
	for (vector<string>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	dfs3(0);
	for (vector<int> i : ans2) {
		for (vector<int>::iterator j = i.begin(); j != i.end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
	partition();
	for (vector<string> i : ans3) {
		for (vector<string>::iterator j = i.begin(); j != i.end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
	return 0;
}