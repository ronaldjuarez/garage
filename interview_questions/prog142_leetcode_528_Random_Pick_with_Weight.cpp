#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:

    template<typename Iter, typename RandomGenerator>
    Iter select_randomly(Iter start, Iter end, RandomGenerator& gen)
    {
        std::uniform_int_distribution<int> uDist(0, std::distance(start, end) - 1);
        std::advance(start, uDist(gen));
        return start;
    }

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }

    std::vector<int> m_w;
    Solution(std::vector<int>& w)
    {
        m_w = std::move(w);
    }

    int pickIndex()
    {
        std::vector<int> cumSumVector(m_w.size(),0);
        int cumSum = 0;
        for (size_t i = 0; i < cumSumVector.size(); i++)
        {
            cumSum += m_w[i];
            cumSumVector[i] = cumSum
        }
    }

    int pickIndex_slow() // out of memory
    {
        int totalSize = std::accumulate(m_w.cbegin(), m_w.cend(), 0);
        std::vector<int> generalVector(totalSize);

        std::vector<int>::iterator generalVectorIt = generalVector.begin();
        for (size_t i = 0; i < m_w.size(); i++)
        {
            for (size_t j = 0; j < m_w[i]; j++)
            {
                *generalVectorIt = static_cast<int>(i);
                generalVectorIt++;
            }
        }

        return *select_randomly(generalVector.begin(), generalVector.end());
    }
};

int main()
{
    std::vector<int> w {1,4};
    Solution sol(w);
    std::cout << sol.pickIndex() << std::endl;
    return 0;
}