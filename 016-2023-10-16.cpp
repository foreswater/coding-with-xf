#include<iostream>
#include<vector>
using namespace std;
int arr[] = { 1,2,3 };
vector<vector<int>> ans;
vector<int> path;
bool is_in_path[4] = { 0 };
void dfs(int i) {
	if (path.size() == sizeof(arr) / sizeof(int)) {
		ans.push_back(path);
		return;
	}
	for (int j = 0; j < sizeof(arr) / sizeof(int); j++) {
		if (is_in_path[arr[j]])continue;
		path.push_back(arr[j]);
		is_in_path[arr[j]] = 1;
		dfs(i + 1);
		path.pop_back();
		is_in_path[arr[j]] = 0;
	}
}
void permute() {
	if (!arr) {
		return;
	}
	dfs(0);
}
int N = 8;
int cnt = 0;
vector<string> board;
vector<int> col(0,N);
vector<int> se;
void Aboard() {
	string s;
	for (int r = 0; r < N; r++) {
		for (int i = 0; i < col[r]; i++) {
			s += "*";
		}
		s += "Q";
		for (int i = s.size(); i < N; i++) {
			s += "*";
		}
		board.push_back(s);
		s = "";
	}
}
void Sboard() {
	for (auto i : board) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool is_Valid(int r, int c) {
	for (int i = 0; i < r; i++) {
		if (col[i] == c)return 0;
	}
	for (int R = 0; R < r; R++) {
		int C = col[R];
		if (r - c == R - C || r + c == R + C) {
			return 0;
		}
	}
	return 1;
}
void dfsQ(int r) {
	if (r == N) {
		cnt++;
		cout << cnt << endl;
		Aboard();
		Sboard();
		board.clear();
		return;
	}
	for (int c = 0; c < N; c++) {
		if (is_Valid(r, c)) {
			col[r] = c;
			dfsQ(r + 1);
			col[r] = 0;
		}
	}
}
void QueenN() {
	if (!N) {
		return;
	}
	dfsQ(0);
}
int main() {
	//permute();
	col.resize(N);
	col[2] = 0;
	QueenN();
	
	return 0;
}