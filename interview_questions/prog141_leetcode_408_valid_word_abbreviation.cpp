#include <iostream>
#include <string>
#include <ctype.h>

bool validWordAbbreviation(std::string word, std::string abbr)
{
    size_t pos = 0;
    
    size_t abbrLength = abbr.length();
    std::string currString = "";
    while (pos < abbrLength)
    {
        if (isdigit(abbr[pos]))
        {
            if (currString.length() == 0 && abbr[pos] == '0' ) return false;
            currString += abbr[pos];
        }
        pos++;
    }    
}

int main()
{


    return 0;
}