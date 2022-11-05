#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <tuple>

int racecar_dfs
(
    int currPos,
    int currSpeed,
    int target,
    std::unordered_map<int, int>& memo
)
{
    if (memo.find(target) != memo.end())
    {
        return memo[target];
    }

    if (target == 0)
    {
        return 0;
    }

    int numStepsLeft = racecar_dfs(currPos + currSpeed, currSpeed*2, target - currSpeed, memo);
    int numStepsRight = racecar_dfs(currPos, -1, target, memo);

    int numSteps = 1 + std::min(numStepsLeft, numStepsRight);
    memo[target] = numSteps;
    return numSteps;
}
int racecar2(int target)
{
    int currPos = 0;
    int currSpeed = 1;
    std::unordered_map<int, int> memo;
    return racecar_dfs(currPos, currSpeed, target, memo);
}

struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator()(std::pair<T1, T2> const& pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

int racecar(int target)
{
    // create queue of tuples (moves, position, speed)
    std::queue<std::tuple<int, int, int>> queueSteps;
    std::unordered_set<std::pair<int, int>, pair_hash> visited;

    queueSteps.push({ 0, 0, 1 });

    while (!queueSteps.empty())
    {
        auto [moves, position, speed] = queueSteps.front();
        queueSteps.pop();

        if (target == position)
        {
            return moves;
        }

        if (visited.find({ position, speed }) != visited.end())
        {
            continue;
        }

        visited.insert({ position, speed });

        queueSteps.push({ moves + 1, position + speed, speed * 2 });

        if ((position + speed > target && speed > 0) ||
            (position + speed < target && speed < 0))
        {
            speed = speed > 0 ? -1 : 1;
            queueSteps.push({ moves + 1, position, speed });
        }

    }

    return 0;
}
int main()
{
    return 0;
}