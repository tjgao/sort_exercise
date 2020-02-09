#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

using cmp=function<bool(int,int)>;
void heapify(vector<int>& data, int i, int len, cmp f=greater<int>()) {
	int m = i;
	int c1 = 2*i + 1, c2 = 2*i + 2;
	if (c1 < len && f(data[c1], data[m])) 
		m = c1;

	if (c2 < len && f(data[c2], data[m]))
		m = c2;

	if (m != i) {
		swap(data[i], data[m]);
		heapify(data, m, len, f);
	}
}

void create_heap(vector<int>& data, cmp f=greater<int>()) {
	int p = (data.size() - 1) / 2;
	for (int i=p; i>=0; i--)
		heapify(data, i, data.size(), f);
}

void heap_sort(vector<int>& data) {
	create_heap(data);
	for (int i=data.size()-1; i>=0; i--) {
		swap(data[i], data[0]);
		heapify(data, 0, i);
	}
}

void test(const vector<int>& data) {
	auto temp1 = data;
	heap_sort(temp1);
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

