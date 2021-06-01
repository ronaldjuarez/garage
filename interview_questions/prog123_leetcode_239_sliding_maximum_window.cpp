#include <iostream>
#include <vector>
#include <queue>
#include "helper.h"

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) 
{
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<int> res;

    for (int i = 0 ; i < k ; i++)
    {
        pq.push(std::make_pair(nums[i], i));
    }
    
    res.push_back(pq.top().first);

    for (int i = k ; i < nums.size() ; i++)
    {
        pq.push(std::make_pair(nums[i], i));    

        while (!pq.empty() &&
                i - pq.top().second >= k )
        {
            pq.pop();
        }

        res.push_back(pq.top().first);
    }
    return std::move(res);
}

int main()
{
    auto result = maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3);
    Helper::print1D<int>(result);
    
    auto result2 = maxSlidingWindow({1, -1}, 1);
    Helper::print1D<int>(result2);
    result2 = maxSlidingWindow({9, 10, 9, -7, -4, -8, 2, -6}, 5);
    Helper::print1D<int>(result2);
    return 0;
}