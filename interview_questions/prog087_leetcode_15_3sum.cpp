#include <iostream>
#include <vector>
#include "helper.h"

using namespace std;



vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++){
        int j,k;
        if (twoSum(nums,i,j,k){
            
        }
    }
}

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int> > res = threeSum(nums);
    print2D(res);
    return 0;
}