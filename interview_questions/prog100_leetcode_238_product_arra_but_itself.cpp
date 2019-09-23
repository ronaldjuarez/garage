#include <iostream>
#include <vector>
#include "helper.h"
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	int size = nums.size();
	vector<int> prods(size, 1);
	for (int i = 0; i < size - 1; i++) {
		prods[i + 1] = prods[i] * nums[i];
	}

    
	int prod = 1;
	for (int i = size - 1; i >= 0; i--) {
		prods[i] *= prod;
        prod *= nums[i];
	}
	return prods;
}

int main() {
	vector<int> nums{ 1,2,3,4 };
	print1D(productExceptSelf(nums));
	return 0;
}