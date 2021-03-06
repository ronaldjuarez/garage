#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

using Vector2I = std::vector<std::vector<int>> ;

int getMax(const std::vector<int>& jobDifficulty, int idx)
{
    return *std::max_element(jobDifficulty.begin() + idx, 
                                jobDifficulty.end());
}

int dfs(const std::vector<int>& jobDifficulty,
    Vector2I& minDifDP,
    int numPartitions,
    int idx)
{
    if (numPartitions == 1)
    {
        return minDifDP[numPartitions][idx] = getMax(jobDifficulty,idx);
    }

    if (minDifDP[numPartitions][idx] != -1)
    {
        return minDifDP[numPartitions][idx];
    }

    int minDif = INT_MAX;
    int maxDif = 0;
    
    for (int i = idx ; i < jobDifficulty.size() - numPartitions  + 1; i++)
    {
        maxDif = std::max(maxDif, jobDifficulty[i]);
        minDif = std::min(minDif, maxDif + dfs(jobDifficulty, minDifDP, numPartitions-1, i + 1));
    }

    return minDifDP[numPartitions][idx] = minDif;
}

int minDifficulty(std::vector<int>& jobDifficulty, int d)
{
    size_t numJobs = jobDifficulty.size();
    if (numJobs < d ) return -1;
    std::vector<std::vector<int>> minDifficultyDP 
                    (d+1, std::vector<int>(jobDifficulty.size(),-1));
    return dfs(jobDifficulty, minDifficultyDP, d, 0);
}

int main(){
    std::vector<int> jobDifficulty{6,5,4,3,2,1};
    int d = 2;
    std::cout << "Input:\nJobDifficulty: " ;
    print1D(jobDifficulty);
    std::cout << "d: " << d << "\n\n";
    std::cout << minDifficulty(jobDifficulty, d) << std::endl;
}