#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
struct reslut {
	int a;
	int b;
	int c;
};
reslut sum_two(int* arr, int target,int sz) {
	int bg = 0;
	int ed = sz - 1;
	while (bg < ed) {
		int sum = arr[bg] + arr[ed];
		if (sum > target) {
			ed--;
		}
		else if (sum < target) {
			bg++;
		}
		else {
			break;
		}
	}
	reslut r;
	r.a = arr[bg];
	r.b = arr[ed];
	return r;
}
list<reslut> sum_three(int* arr, int sz) {
	sort(arr, arr + sz - 1);
	list<reslut> ans;
	reslut r;
	for (int i = 0; i < sz-2; i++) {
		int target = arr[i];
		if (i > 0 && target == arr[i - 1]) {
			continue;
		}
		if (arr[i] + arr[1] + arr[2]>0) {
			break;
		}
		if (arr[i] + arr[sz - 1] + arr[sz - 2] < 0) {
			continue;
		}
		int bg = i + 1;
		int ed = sz - 1;
		while (bg < ed) {
			int sum = arr[bg] + arr[ed] + target;
			if (sum > 0) {
				ed--;
			}
			else if (sum < 0) {
				bg++;
			}
			else{
				r.a = target;
				r.b = arr[bg];
				r.c = arr[ed];
				ans.push_back(r);
				bg++;
				while (bg < ed && arr[bg] == arr[bg - 1])bg++;
				ed--;
				while (bg < ed && arr[ed] == arr[ed + 1])ed--;
			}
		}
	}
	return ans;
}
int main() {
	int arr1[] = { 2,3,4,6,8 };
	int arr2[] = { -1,0,1,2,-1,4 };
	int target = 9;
	reslut r = sum_two(arr1, 9, 5);
	cout << r.a << " " << r.b<<endl;
	list<reslut> ans = sum_three(arr2, 6);
	for (list<reslut>::iterator i = ans.begin(); i != ans.end(); i++) {
		reslut r1 = *i;
		cout << r1.a << " " << r1.b << " " << r1.c << endl;
	}
	return 0;
}