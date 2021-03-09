#include <iostream>
#include <vector>
#include <numeric>

int maxScore(std::vector<int>& cardPoints, int k) 
{
    int currentMax = 0;
    int globalMax = 0;
    int n = cardPoints.size();

    currentMax = std::accumulate(cardPoints.end() - k, cardPoints.end(), 0);
    

    globalMax = currentMax;
    for (auto i = 1; i <= k; i++)
    {
        currentMax += cardPoints[i-1] - cardPoints[n-k-1+i];
        globalMax = std::max(currentMax, globalMax);
    }


    return globalMax;
}

int main()
{
    std::vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    std::cout << maxScore(cardPoints, k) << std::endl;
}
