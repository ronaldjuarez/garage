#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <optional>
#include <utility>

class Solution {
public:

    struct pair_hash2
    {
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const
        {
            //std::size_t h1 = std::hash<T1>(pair.first);
            //std::size_t h2 = std::hash<T2>(pair.second);
            //return h1 ^ h2;
            return pair.first ^ pair.second;
        }
    };


    bool canCross_recursive(
        std::unordered_map<int, int>& stonesMap,
        std::unordered_map<std::pair<int, int>, std::optional<bool>, pair_hash2>& memo, // map[pos, jumpsize]
        int currPos,
        int jump_size,
        bool& found
    )
    {

        const std::pair<int, int> currPair = std::make_pair(currPos, jump_size);
        if (memo.find(currPair) != memo.end() && memo[currPair].has_value())
        {
            return memo[currPair].value();
        }

        memo[{ currPos, jump_size }] = std::nullopt;

        if (stonesMap[currPos] == stonesMap.size() - 1)
        {
            memo[{ currPos, jump_size }] = true;
            found = true;
            return true;
        }

        if (found) 
        {
            return true;
        }

        bool jump1 = false, jump2 = false, jump3 = false;

        if (jump_size - 1 > 0 && (stonesMap.find(currPos + jump_size - 1) != stonesMap.end()))
        {
            int nextPos = currPos + jump_size - 1;
            jump1 = canCross_recursive(stonesMap, memo, nextPos, jump_size - 1, found);
        }

        if (!jump1 && stonesMap.find(currPos + jump_size) != stonesMap.end())
        {
            int nextPos = currPos + jump_size;
            jump2 = canCross_recursive(stonesMap, memo, nextPos, jump_size, found);
        }

        if (!jump1 && !jump2 && stonesMap.find(currPos + jump_size + 1) != stonesMap.end() && stonesMap[currPos] > 0)
        {
            int nextPos = currPos + jump_size + 1;
            jump3 = canCross_recursive(stonesMap, memo, nextPos, jump_size + 1, found);
        }

        memo[{ currPos, jump_size }] = jump1 || jump2 || jump3; // might need to change by memo[currStoneIdx] = jump1 || jump2 || jump3
        return jump1 || jump2 || jump3;
    }


    bool canCross(std::vector<int>& stones)
    {

        std::unordered_map<int, int> stonesMap;
        std::unordered_map<std::pair<int, int>, std::optional<bool>, pair_hash2> memo; // {pos, jumpSize}
        bool found = false;
        for (size_t i = 0; i < stones.size(); i++) 
        {
            stonesMap[stones[i]] = i;
        }

        return canCross_recursive(stonesMap, memo, 0 /*curr pos*/, 1 /*jump*/, found);
    }

    bool canCross2(std::vector<int>& stones)
    {
        int N = stones.size();

        // dp[N][N+1] 
        // dp[i][j] : at stone ith , the frog can or not make jump of size j
        std::vector<std::vector<bool>> dp(N,std::vector<bool>(N+1, false))
        dp[0][1] = false;

        
    }
};

int main()
{
    Solution sol;
    std::vector<int> stones{ 0,1,3,5,6,8,12,17 };
    std::vector<int> stones2{ 0,2 };

    std::cout << sol.canCross(stones2) << std::endl;
    std::cout << sol.canCross(stones) << std::endl;
    return 0;
}