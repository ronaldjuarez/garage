#include <iostream>
#include <vector>
#include "helper.h"

void reverseString(std::vector<char>& s) {
    size_t n = s.size();
    for (size_t i = 0 ; i < n / 2 ; i++)
    {
        std::swap(s[i], s[n - 1 - i]);
    }
}
int main()
{
    std::vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    Helper::print1D<char>(s);
    return 0;
}