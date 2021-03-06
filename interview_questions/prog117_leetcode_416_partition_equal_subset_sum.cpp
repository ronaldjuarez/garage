#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>

#include "helper.h"


bool dfs1(std::vector<int>& nums,
        const int total_sum,
        int curr_sum,
	    std::vector<bool>& visited)
{
	if (curr_sum == total_sum / 2) return true;

	if (curr_sum >= total_sum / 2) return false;

	bool result = false;
	int i = 0;
	for (auto e : nums)
	{
		if (visited[i])
		{
			i++;
			continue;
		}
		visited[i] = true;
		bool partialResult = dfs1(nums, total_sum, curr_sum + e, visited);

		if (partialResult == true) return true;

		result = result || partialResult;
		visited[i] = false;
		i++;
	}
	return result;
}


// pure recursion
bool canPartition1(std::vector<int>& nums)
{
	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	std::vector<bool> visited(nums.size(), false);
	if (total_sum % 2 != 0) return false;

	return dfs1(nums, total_sum, 0, visited);
}

bool dfs2(std::vector<int>& nums, int idx, int sum)
{
    if (sum == 0) return true;
    if (sum < 0 || idx >= nums.size()) return false;

    return dfs2(nums, idx + 1 , sum - nums[idx]) || dfs2(nums, idx + 1, sum);
}

// pure recursion 
bool canPartition2(std::vector<int>& nums)
{
    int total_sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (total_sum % 2 != 0 ) return false;

    return dfs2(nums, 0, total_sum / 2);
}


int dfs3(std::vector<int>& nums, int idx, int sum,
	std::vector<std::vector<int>>& memo)
{
	if (sum < 0 || idx >= nums.size()) return 0;

	if (memo[idx][sum] != -1) return memo[idx][sum];

	memo[idx][sum] = dfs3(nums, idx + 1, sum - nums[idx], memo) ||
		dfs3(nums, idx + 1, sum, memo);

	return memo[idx][sum];
}

// recursion with memo 2D , Time Complexity O(n^2), Space Complexity O(n*m)
bool canPartition3(std::vector<int>& nums)
{
	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (total_sum % 2 != 0) return false;

	std::vector<std::vector<int>> memo(nums.size() + 1,
		std::vector<int>(total_sum / 2 + 1, -1));

	for (int j = 0; j <= total_sum / 2; j++)
	{
		memo[nums.size()][j] = 0;
	}

	for (int i = 0; i <= nums.size(); i++)
	{
		memo[i][0] = 1;
	}


	return dfs3(nums, 0, total_sum / 2, memo);
}

// Iterative Time Complexity O(n^2), Space Complexity O(nm)
bool canPartition4(std::vector<int>& nums)
{
	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (total_sum % 2 != 0) return false;

	int n = nums.size();
	int sum = total_sum / 2;

	std::vector<std::vector<int>> dp(n + 1,
		std::vector<int>(sum + 1, -1));

	for (int j = 0; j <= sum; j++)
	{
		dp[n][j] = 0;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}


	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j < nums[i]) dp[i][j] = dp[i + 1][j];
			else dp[i][j] = dp[i + 1][j - nums[i]] || dp[i + 1][j];
		}
	}

	//print2D(dp);

	return dp[0][sum];
}

bool canPartition5(std::vector<int>& nums)
{
	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (total_sum % 2 != 0) return false;

	int n = nums.size();
	int sum = total_sum / 2;

	std::vector<std::vector<bool>> dp(2,
		std::vector<bool>(sum + 1, false));

	for (int i = 0; i < 2; i++)
	{
		dp[i][0] = true;
	}


	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j < nums[i]) dp[i % 2][j] = dp[(i + 1) % 2][j];
			else dp[i % 2][j] = dp[(i + 1) % 2][j - nums[i]] || dp[(i + 1) % 2][j];
		}
	}
	//print2D(dp);

	return dp[0][sum];
}

bool canPartition6(std::vector<int>& nums)
{
	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (total_sum % 2 != 0) return false;

	int n = nums.size();
	int sum = total_sum / 2;

	std::vector<bool> dp(sum + 1, false);

	dp[0] = true;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = sum; j >= 0; j--)
		{
			if (j >= nums[i]) dp[j] = dp[j - nums[i]] || dp[j];
		}
	}
	//print2D(dp);

	return dp[sum];
}

bool canPartition7(std::vector<int>& nums)
{
        const int MAX = 200 * 100;
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2 != 0) return false;

        int n = nums.size();
        int sum = total_sum / 2;

        //std::vector<bool> dp(sum + 1, false);
        std::bitset<MAX + 1> dp;
        dp.reset();
        dp.set(0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j >= nums[i]) dp[j] = dp[j - nums[i]] || dp[j];
            }
        }
        //print2D(dp);

        return dp[sum];
}

int main()
{
    std::vector<int> nums1{1, 5, 11, 5};
    std::vector<int> nums2{1, 2 , 3, 4};
    std::vector<int> nums3{1, 5, 11, 9};
    std::vector<int> nums4{100,100,100,100,100,100,100,100};
    std::cout << canPartition1(nums1) << " ";
    std::cout << canPartition1(nums2) << " ";
    std::cout << canPartition1(nums3) << " ";
    std::cout << canPartition1(nums4) << std::endl;
    std::cout << canPartition2(nums1) << " ";
    std::cout << canPartition2(nums2) << " ";
    std::cout << canPartition2(nums3) << " ";
    std::cout << canPartition2(nums4) << std::endl;
    std::cout << canPartition3(nums1) << " ";
    std::cout << canPartition3(nums2) << " ";
    std::cout << canPartition3(nums3) << " ";
    std::cout << canPartition3(nums4) << std::endl;
    std::cout << canPartition4(nums1) << " ";
    std::cout << canPartition4(nums2) << " ";
    std::cout << canPartition4(nums3) << " ";
    std::cout << canPartition4(nums4) << std::endl;
    std::cout << canPartition5(nums1) << " ";
    std::cout << canPartition5(nums2) << " ";
    std::cout << canPartition5(nums3) << " ";
    std::cout << canPartition5(nums4) << std::endl;
    std::cout << canPartition6(nums1) << " ";
    std::cout << canPartition6(nums2) << " ";
    std::cout << canPartition6(nums3) << " ";
    std::cout << canPartition6(nums4) << std::endl;
    std::cout << canPartition7(nums1) << " ";
    std::cout << canPartition7(nums2) << " ";
    std::cout << canPartition7(nums3) << " ";
    std::cout << canPartition7(nums4) << std::endl;

    int a = 1 & 1;
    int b = 2 & 1;
    int c = 3 & 1;
    int d = 12, e = 25;
    int f = d & e;
    std::bitset<16> x(d);
    std::bitset<16> y(e);
    std::bitset<16> z(f);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << f << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::bitset<40> xx;
    std::vector<bool> xxx(40,true);

    xxx[64999] = false;

    std::cout << "Size bitset: " << sizeof(xx) << std::endl;
    std::cout << "Size array bool: " << sizeof(xxx) << std::endl;
    std::cout << " bool: " << sizeof(bool) << std::endl;
    xx.reset();

    std::cout << xx << std::endl;
    xx.set(39);

    std::cout << xx << std::endl;
    
    xx = xx >> 2;
    std::cout << xx << std::endl;
    return 0;
}