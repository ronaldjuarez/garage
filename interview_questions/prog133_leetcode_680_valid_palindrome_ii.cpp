#include <iostream>

bool isValidPalindrome(std::string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(std::string s) 
{
    if (s.empty()) return true;

    // i -> starting at left-most index
    // j -> starting at right-most index 
    size_t  i = 0, j = s.size() - 1;

    // flag to see if we remove at least one element
    // already
    int totalRemoved = 0;

    while (i < j)
    {
        // if current indices have the same value
        // we increase/decrease index values accordingly
        if (s[i] == s[j])
        {
            i++; j--;
        }
        else 
        {
            return isValidPalindrome(s, i + 1, j) || isValidPalindrome(s, i, j-1);
        }
    }

    return true;
}

int main()
{
    std::cout << validPalindrome("abca") << std::endl;
    std::cout << validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << std::endl;
    return 0;
}