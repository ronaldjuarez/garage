#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum4(std::vector<int>& nums, int k) {
    // sliding window fails it does not work 
    // for negative elements

    if (nums.size() == 0) return 0;

    size_t i = 0, j = 1;
    size_t n = nums.size();

    int currSum = nums[i];
    int count = 0;

    while (i < n && j <= n && i<=j)
    {
        if (currSum == k)
        {
            count++;
            currSum -= nums[i];
            i++;
        }

        while (currSum > k)
        {
            currSum -= nums[i];
            i++;
        }

        if (i > j)
        {
            j = i;
            continue;
        }

        while (currSum < k )
        {
            if (j < n)
            {
                currSum += nums[j];
            }
            if (j > n) break;
            j++;
        }
    }
    return count;
    
}

int subarraySum3(std::vector<int>& nums, int k) {
    //times out
    size_t n = nums.size();
    if (n == 0) return 0;

    std::vector<int> cumSum(n +1);

    cumSum[0] = 0;

    for(size_t i = 1; i <= nums.size(); i++)
    {
        cumSum[i] = cumSum[i-1] + nums[i-1];
    }

    int count = 0;
    for(size_t start = 0; start < nums.size(); start++)
    {
        for (size_t end = start+1; end <= nums.size(); end++)
        {   
             if (cumSum[end] - cumSum[start] == k)
             {
                 count++;
             }
        }
    }
    return count;

}

int subarraySum2(std::vector<int>& nums, int k) {
    
    size_t n = nums.size();

    if (n == 0) return 0;

    int count = 0;

    for(size_t start = 0; start < n ; start++)
    {
        int sum = 0;
        for(size_t end = start; end < n; end++)
        {
            sum += nums[end];
            if ( sum == k)
            {
                count++;
            }
        }
    }

    return count;

}

bool exist(const std::unordered_map<int,int>& map, int key)
{
    return map.find(key) != map.end();
}

int subarraySum(std::vector<int>& nums, int k) {
    
    size_t n = nums.size();
    if (n == 0) return 0;

    std::unordered_map<int,int> map;
    
    int cumSum = 0;
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        cumSum += nums[i];
        
        if (cumSum == k)
        {
            count++;
        }

        if (exist(map, cumSum-k))
        {
            count += map[cumSum-k];
        }

        map[cumSum]++;

    }
    return count;
}

int main()
{
    std::vector<int> nums = {1,1,1};
    std::cout << subarraySum(nums, 2) << std::endl;

    std::vector<int> nums2 = {1,2,3};
    std::cout << subarraySum(nums2, 3) << std::endl;

    std::vector<int> nums3 = {1};
    std::cout << subarraySum(nums3, 0) << std::endl;
    return 0;
}