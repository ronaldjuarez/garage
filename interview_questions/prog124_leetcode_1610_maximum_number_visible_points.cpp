#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) 
{
    if (angle < 0) return -1;

    const double PI = 3.14159265;
    const double MARGIN = 1e-9;
    int originOverlap = 0;
    
    // computing angle for each points;
    std::vector<double> angles;

    // changing coordinate system to location as (0,0)
    for (auto& point: points)
    {
        point[0] -= location[0];
        point[1] -= location[1];
        
        if (point[0] == 0 &&
            point[1] == 0)
        {
            originOverlap++;
        }
        else
        {
            double angle = std::atan2(point[1], point[0]) * 180.0 / PI;

            if ( angle < 0)
            {
                angle += 360;
            }
            angles.push_back(angle);
        }
    }

    std::sort(angles.begin(), angles.end());
 
    //std::vector<double> a = angles;
    angles.insert(angles.end(), angles.begin(), angles.end());
    
    for (size_t i = angles.size() / 2 ; i < angles.size() ; i++)
    {
        angles[i] += 360;
    }

    int res = 0;

    for (int i = 0, j = 0; i < angles.size() ; i++)
    {
        while ( j < angles.size() &&
                angles[j] - angles[i] <= angle + MARGIN)
        {
            j++;
        }

        res = std::max(res, j - i);
    }
    
    return res + originOverlap;

}

int main()
{
    //std::vector<std::vector<int>> points = {{-1,-1}, {2, -1}, {-1, 1}, {2, 1},{2,2},{3,3}};
    std::vector<std::vector<int>> points = { {2, 1},{2,2},{3,4}, {1,1}};
    int angle = 90;
    std::vector<int> location = {1,1};

    std::cout << visiblePoints(points, angle, location) << std::endl;

    return 0;
}