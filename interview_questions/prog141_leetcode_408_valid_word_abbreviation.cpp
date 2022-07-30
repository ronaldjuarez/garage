#include <iostream>
#include <string>
#include <ctype.h>

bool validWordAbbreviation(std::string word, std::string abbr)
{
    size_t abbrPos = 0, wordPos = 0;

    size_t abbrLength = abbr.length();
    size_t wordLength = word.length();


    while (abbrPos < abbrLength && wordPos < wordLength)
    {
        if (abbr[abbrPos] == word[wordPos])
        {
            abbrPos++;
            wordPos++;
        }
        else
        {
            std::string currString = "";


            while (abbrPos < abbrLength && isdigit(abbr[abbrPos]))
            {
                if (currString.empty())
                {
                    if (abbr[abbrPos] == '0') return false;
                    else
                    {
                        currString += abbr[abbrPos];
                    }
                }
                else
                {
                    currString += abbr[abbrPos];
                }
                abbrPos++;
            }

            if (abbrPos >= abbrLength)
            {
                if (!currString.empty())
                {
                    int numSteps = std::stoi(currString);
                    wordPos += numSteps;
                }

                return wordPos == wordLength;

            }
            else
            {
                if (isalpha(abbr[abbrPos]))
                {
                    if (!currString.empty())
                    {
                        int numSteps = std::stoi(currString);
                        wordPos += numSteps;
                    }
                    else {
                        return false;
                    }
                }
                else
                {
                    //throw error
                }
            }
        }


    }

    return abbrPos == abbrLength && wordPos == wordLength;
}

int main()
{
    std::string word = "internationalization";
    std::string abbr = "i5a11o1";



    std::cout << validWordAbbreviation(word, abbr) << std::endl;

    return 0;
}