#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void _merge(vector<int>& data, int left, int mid, int right) {
	vector<int> buf(right-left+1);
	int p = left, q = mid+1, cur = 0, tmp;
	while (p <= mid || q <= right) {
		if (p > mid) 
			buf[cur++] = data[q++];
		else if (q > right) 
			buf[cur++] = data[p++];
		else {
			if (data[p] < data[q])
				tmp = data[p++];
			else
				tmp = data[q++];
			buf[cur++] = tmp;
		}
	}
	for (int i=0; i<buf.size(); i++)
		data[left+i] = buf[i];
}

void _sort(vector<int>& data, int left, int right) {
	if (left + 1 < right) {
		int mid = left + (right-left) / 2;
		_sort(data, left, mid);
		_sort(data, mid+1, right);
		_merge(data, left, mid, right);
	} else if (left + 1 == right){
		if (data[left] > data[right])
			swap(data[left], data[right]);
	}

}

void merge_sort(vector<int>& data) {
	_sort(data, 0, data.size() -1);
}

void test(const vector<int>& data) {
	auto temp1 = data;
	merge_sort(temp1);
	auto temp2 = data;
	sort(temp2.begin(), temp2.end());
	assert(temp1 == temp2);	
}
int main() {
	vector<int> v1 { 2,4,1,9,198,64,23,167,-1,18 };
	vector<int> v2 { 1 , 0};
	vector<int> v3 { 1};
	vector<int> v4 {};
	vector<int> v5 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	test(v1);
	test(v2);
	test(v3);
	test(v4);
	test(v5);
}
