#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_global, max_current;
    max_global = nums[0];
    max_current = nums[0];

    for ( int i = 1; i < nums.size(); i ++){
        max_current = max(max_current + nums[i], nums[i]);
        max_global = max(max_current, max_global);
    }

    global
    return max_global;
}

int maxSubArray_rec_helper(vector<int>& nums, int n, int &result) {
    if (n == nums.size()) return nums[n-1];
    result = max(result, max(a[n], a[n] + maxSubArray_rec_helper(nums, n + 1, result )));
}
int maxSubArray_rec(vector<int>& nums) {
    int result;
    return maxSubArray_rec_helper(nums, 0, result);
}

int main() {
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    cout << maxSubArray_rec(nums) << endl;
    return 0;
}