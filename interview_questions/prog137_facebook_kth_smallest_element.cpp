#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

struct Compare
{
    bool operator()(const std::pair<int, int> & n1, const std::pair<int, int> & n2)
    {
        return n1.second > n2.second;
    }
};

int getKthSmallestValue(
    const std::vector<std::vector<int>>& arrayOfArrays, 
    int m, int n, int k)
{
    assert(static_cast<int>(arrayOfArrays.size()) == m);
    assert(k <= n);

    std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> qt;
    std::vector<int> indices(m, 1) ;

    for (int i = 0; i < m; i++)
    {
        qt.push(std::pair<int, int>(i, arrayOfArrays[i][0]));
    }

    int counter = 0;
    while (!qt.empty() && counter++ < n - m)
    {
        std::pair<int, int> currentElem = qt.top();
        qt.pop();
        
        if (counter == k) return currentElem.second;

        qt.push(std::pair<int, int>(currentElem.first, arrayOfArrays[currentElem.first][indices[currentElem.first]++]));
    }

    return INT_MAX;
}

int main()
{
    std::vector<std::vector<int>> arrayOfArrays
        {   
            {1, 3, 5, 7},
            {2, 4, 6 },
            {11, 12 }
        };
    int m = 3, n = 9, k = 5;

    std::cout << getKthSmallestValue(arrayOfArrays, m, n, k) << std::endl;
}