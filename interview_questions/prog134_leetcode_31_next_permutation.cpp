#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

void nextPermutation(std::vector<int>& nums) 
{
    int n = static_cast<int>(nums.size());
    int lastInc = n - 2;
    int swapIndx = n - 1;

    for (; lastInc >= 0; lastInc--)
    {
        if (nums[lastInc] < nums[lastInc + 1])
        {
            break;
        }
    }

    if (lastInc < 0)
    {
        for (size_t j = 0; j < n / 2; j++)
        {
            std::swap(nums[j], nums[n - 1 - j]);
        }
        return; 
    }

    for (; swapIndx > lastInc; swapIndx--)
    {
        if (nums[swapIndx] > nums[lastInc])
        {
            break;
        }
    }

    std::swap(nums[swapIndx], nums[lastInc]);
    std::reverse(nums.begin() + lastInc + 1, nums.end());
}

int main()
{
    std::vector<int> v1 {1, 2, 3};
    std::vector<int> v2 {3, 2, 1};
    std::vector<int> v3 {1, 1, 5};

    nextPermutation(v1);
    nextPermutation(v2);
    nextPermutation(v3);

    Helper::print1D<int>(v1);
    Helper::print1D<int>(v2);
    Helper::print1D<int>(v3);
}