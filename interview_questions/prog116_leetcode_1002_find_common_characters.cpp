#include <vector>
#include <string>
#include <iostream>
#include "helper.h"

std::vector<std::string> 
commonChars(std::vector<std::string>& A)
{
    std::vector<int> cnt(26, INT_MAX);
    std::vector<std::string> res;

    for (auto& s: A)
    {
        std::vector<int> cnt1(26, 0);
        for (auto c : s) ++cnt1[c - 'a'];
        for (int i = 0 ; i < 26 ; i++) cnt[i] = std::min(cnt[i], cnt1[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            res.push_back(std::string(1, i + 'a'));
        }
    }

    return res;
}

int main()
{
    std::vector<std::string> A 
        {"bella", "label", "roller"};


    print1D(commonChars(A));

    return 0;
}