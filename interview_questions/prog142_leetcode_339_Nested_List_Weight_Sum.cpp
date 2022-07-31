#include <iostream>
#include <vector>
#include <queue>

class NestedInteger
{
public:
    NestedInteger();
    NestedInteger(int value);
    bool isInteger() const;
    int getInteger() const;
    void setInteger(int value);
    void add(const NestedInteger&ni);
    const std::vector<NestedInteger>& getList() const;
};

class Solution
{
public:
    int depthSumRec(const std::vector<NestedInteger>& nestedList, int depth)
    {
        if (nestedList.empty()) return 0;
        
        int totalSum = 0;

        for (auto elem :nestedList)
        {
            if (elem.isInteger())
            {
                totalSum += depth * elem.getInteger();
            }
            else 
            {
                totalSum += depthSumRec(elem.getList(), depth + 1);
            }
        }

        return totalSum;
    }

    int depthSum(std::vector<NestedInteger>& nestedList)
    {
        return depthSumRec(nestedList, 1);
    }

    int depthSum2(std::vector<NestedInteger>& nestedList)
    {
        std::queue<std::pair<int, NestedInteger>> nestedIntQueue;

        for (auto nestedInt : nestedList)
        {
            nestedIntQueue.push({1, nestedInt});
        }

        int totalSum = 0;
        
        while (!nestedIntQueue.empty())
        {
            auto currNestedInt = nestedIntQueue.front(); 
            nestedIntQueue.pop();

            if (currNestedInt.second.isInteger())
            {
                totalSum += currNestedInt.first * currNestedInt.second.getInteger();
            }
            else
            {
                for (auto elem: currNestedInt.second.getList())
                {
                    nestedIntQueue.push({currNestedInt.first + 1, elem});
                }
            }
        }
        return totalSum;
    }
};
int main()
{

    return 0;
}