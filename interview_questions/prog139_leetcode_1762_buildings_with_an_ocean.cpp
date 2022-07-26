#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

std::vector<int> findBuildings(std::vector<int>& heights)\
{
    int n = static_cast<int>(heights.size()); //vector size
    if (n == 0) return {};
    int currMaxIdx = n-1;
    std::vector<int> sol;
    sol.push_back(currMaxIdx);
    for (auto i = n-2; i>=0; i--)
    {
        if (heights[i] > heights[currMaxIdx])
        {
            currMaxIdx = i;
            sol.push_back(currMaxIdx);
        }
    }

    std::sort(sol.begin(), sol.end());

    return sol;
}

int main()
{
    std::vector<int> heights{4,2,3,1};
    
    Helper::print1D(findBuildings(heights));

    return 0;

}