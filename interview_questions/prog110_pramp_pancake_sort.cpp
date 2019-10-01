#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "helper.h"

using namespace std;

void flip(vector<int>& arr, int k) {
	for (int i = 0; i < k / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[k - 1 - i];
		arr[k - 1 - i] = temp;
	}
}


// pramp
vector<int> pancakeSort(const vector<int>& arr)
{

	int size = arr.size();

	vector<int> ans = arr;

	for (int i = size - 1; i >= 0; i--) {
		// find the curr max
		int currMax = INT_MIN;
		int idxMax = -1;
		for (int j = 0; j < i; j++) {
			if (currMax < ans[j]) {
				idxMax = j;
				currMax = ans[j];
			}
		}
		flip(ans, idxMax + 1);
		flip(ans, i + 1);
	}
	return ans;
}

int main() {
	vector<int> v1{ 1 };
	vector<int> v2{ 1, 5, 4, 2, 3 };
	print1D(pancakeSort(v1));
	print1D(pancakeSort(v2));
	return 0;
}
