#include <iostream>
#include <vector>
#include <map>
#include <cassert>

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) 
{
    int numFleets = 0;
    assert(position.size() == speed.size());

    std::map<int , int, std::greater<int>>  carMap;

    for (size_t i {0} ; i < position.size(); i++)
    {
        carMap[position[i]] = speed[i];
    }

    float lastTime = -1.0f;
    float currTime = 0.0f;
    for (const auto& car : carMap)
    {
        currTime = static_cast<float>(target - car.first)
                    / static_cast<float>(car.second);
        if (currTime > lastTime) 
        {
            numFleets++;
            lastTime = currTime;
        }
    }

    return numFleets;
}

int main()
{
    int target = 12;
    std::vector<int> position {10, 8, 0, 5, 3};
    std::vector<int> speed {2, 4, 1, 1, 3};

    std::cout << carFleet(target, position, speed) << std::endl;
}