#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cassert>

int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) 
{
    //time exceed limit
    assert(points[0].size() == 2);
    std::multimap<int,int> pointsMap;

    for (size_t i = 0; i < points.size(); i++)
    {
        pointsMap.insert({points[i][0], points[i][1]});
    }

    size_t i = 0, j = 1;
    std::multimap<int, int>::iterator it;
    std::multimap<int, int>::iterator it2;
    int globalMax = INT_MIN;
    for (it = pointsMap.begin() ; it != std::prev(pointsMap.cend()); it++ )
    {
        for (it2 = std::next(it) ; it2 != pointsMap.end(); it2++)
        {
            if (std::abs( (*it).first - (*it2).first) > k ) break;
            
            int val = (*it).second + (*it2).second + ::abs( (*it).first - (*it2).first) ;
            globalMax = std::max(globalMax, val);
        }
    }

    return globalMax;
}

int findMaxValueOfEquation2(std::vector<std::vector<int>>& points, int k) 
{
    std::priority_queue<std::pair<int, int>> pq; // max_heap

    int ans = INT_MIN;
    
    pq.push(std::make_pair(points[0][1] - points[0][0], points[0][0]));

    for (size_t i = 1; i < points.size() ; i++)
    {
        int sum = points[i][0] + points[i][1];
        
        while (!pq.empty() &&
                points[i][0] - pq.top().second > k)
        {
            pq.pop();
        }
        
        if (!pq.empty())
        {
            ans = std::max(ans, sum + pq.top().first);
        }

        pq.push(std::make_pair(points[i][1] - points[i][0], points[i][0]));

    }

    return ans;
}

int main()
{
    std::vector<std::vector<int>> points
        {{1,3}, {2, 0}, {5, 10}, {6,-10}};
    int k = 1;

    std::cout << findMaxValueOfEquation2(points, k) << std::endl;
    std::vector<std::vector<int>> points2 = {{0,0},{3,0},{9,2}};
    std::cout << findMaxValueOfEquation2(points2, 3) << std::endl;

    return 0;
}