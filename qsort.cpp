#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void qsort(vector<int>& data) {
	function<void(vector<int>&, int, int)> _sort = [&_sort](vector<int>& data, int start, int end) {
		if (start >= end) return;
		
		int cur = start, target = data[start];
		for (int i=start; i<end+1; i++) {
			if (data[i] < target) 
				swap(data[i], data[cur++]);
		}
		if (cur == start) cur++;

		_sort(data, start, cur - 1);
		_sort(data, cur, end);
	};
	_sort(data, 0, data.size() - 1);
}


void test(const vector<int>& data) {
	auto temp1 = data;
	qsort(temp1);
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

