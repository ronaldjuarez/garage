#include <iostream>
#include <string>
#include <stack>
#include <cctype>

bool isOperator(char c)
{
    return c == '*' || c == '/' || c == '+' || c == '-';
}

int calculate(std::string s)
{
    s += "+";
    std::stack<int> stk_numbers;

    size_t len = s.size();

    char currChar, currOperator = '+';
    std::string currNumber = "";
    for (size_t i = 0; i < len; i++)
    {
        currChar = s[i];

        if (currChar == ' ') continue;

        if (isOperator(currChar))
        {
            if (currOperator == '+')
            {
                stk_numbers.push(1 * std::stoi(currNumber));
            }
            else if (currOperator == '-')
            {
                stk_numbers.push(-1 * std::stoi(currNumber));
            }
            else if (currOperator == '*')
            {
                int lastNumber = stk_numbers.top();
                stk_numbers.pop();
                stk_numbers.push(lastNumber * std::stoi(currNumber));
            }
            else if (currOperator == '/')
            {

                int lastNumber = stk_numbers.top();
                stk_numbers.pop();
                stk_numbers.push(lastNumber / std::stoi(currNumber));
            }

            currNumber = "";
            currOperator = currChar;
        }
        else if (isdigit(currChar))
        {
            currNumber += currChar;
        }
        else
        {
            // if it is other character we just skip
            // but it would be better to throw exception
            throw std::runtime_error("not valid character");
        }

    }

    int result = 0;

    while (!stk_numbers.empty())
    {
        result += stk_numbers.top();
        stk_numbers.pop();
    }
    return result;
}

int main()
{
    std::cout << calculate("3+2*2") << std::endl;
    std::cout << calculate(" 3/2 ") << std::endl;
    std::cout << calculate(" 3+5 / 2 ") << std::endl;
}