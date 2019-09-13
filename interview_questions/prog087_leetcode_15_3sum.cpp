#include <iostream>
#include <vector>
#include "helper.h"
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	int size = nums.size();
	vector<vector<int> > result;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < size - 2; i++) {
		int left = i + 1;
		int right = size - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				left++;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				vector<int> elem{ nums[i], nums[left], nums[right] };
				result.push_back(elem);
				int leftValue = nums[left];
				while (left < size && nums[left] == leftValue)
					left++;
				int rightValue = nums[right];
				while (right > left && nums[right] == rightValue)
					right--;
			}
		}

		while (i + 1 < size && nums[i] == nums[i + 1])
			i++;
	}
	return result;
}

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int> > res = threeSum(nums);
    print2D(res);
    return 0;
}