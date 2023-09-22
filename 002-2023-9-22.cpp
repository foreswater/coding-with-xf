#include<iostream>
#include<algorithm>
using namespace std;
int max_rain(int* arr, int sz) {
	int bg = 0;
	int ed = sz - 1;
	int rain = min(arr[bg], arr[ed]) * (ed - bg);
	while (bg < ed) {
		int rain1 = min(arr[bg], arr[ed]) * (ed - bg);
		if (rain1 >= rain)
			rain = rain1;
		arr[bg] > arr[ed] ? ed-- : bg++;
	}
	return rain;
}
int max_rain1(int* arr, int sz) {
	int* l_hei = new int[sz];
	int* r_hei = new int[sz];
	int sum = 0;
	l_hei[0] = arr[0];
	r_hei[sz - 1] = arr[sz - 1];
	for (int i = 0; i < sz-1; i++) {
		l_hei[i + 1] = l_hei[i] > arr[i + 1] ? l_hei[i] : arr[i + 1];
	}
	for (int i = sz-1; i >0; i--) {
		r_hei[i - 1] = r_hei[i] > arr[i - 1] ? r_hei[i] : arr[i - 1];
	}
	for (int i = 0; i < sz; i++) {
		sum += min(l_hei[i], r_hei[i]) - arr[i];
	}
	delete[]l_hei;
	delete[]r_hei;
	return sum;
}
int max_rain2(int* arr, int sz) {
	int l = 0;
	int r = sz - 1;
	int sum = 0;
	int pre_max = 0;
	int suf_max = 0;
	while (l<=r)
	{
		pre_max = pre_max > arr[l] ? pre_max : arr[l];
		suf_max = suf_max > arr[r] ? suf_max : arr[r];
		if (pre_max < suf_max) {
			sum += pre_max - arr[l];
			l++;
		}
		else {
			sum += suf_max - arr[r];
			r--;
		}
	}
	return  sum;
}
int main() {
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	int arr1[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int max_r = max_rain(arr, 9);
	cout << max_r << endl;
	cout << max_rain1(arr1, sizeof(arr1) / sizeof(int)) << endl;
	cout << max_rain2(arr1, sizeof(arr1) / sizeof(int)) << endl;
	return 0;
}