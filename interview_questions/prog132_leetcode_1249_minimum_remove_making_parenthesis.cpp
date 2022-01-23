#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

std::string minRemoveToMakeValid(std::string s)
{

    int balanced = 0;
    const char TOKEN_CHAR = '*';
    std::stack<int> st;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            balanced++;
            st.push(i);
        }
        else if (s[i] == ')')
        {
            balanced--;
            if (!st.empty())
            {
                st.pop();
            }
        }

        if (balanced < 0)
        {
            s[i] = TOKEN_CHAR;
            balanced = 0;
        }
    }

    while (!st.empty())
    {
        s[st.top()] = '*';
        st.pop();
    }

    s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
    return s;
}

int main()
{
    std::cout << minRemoveToMakeValid("lee(t(c)o)de)") << std::endl;
    std::cout << minRemoveToMakeValid("a)b(c)d") << std::endl;
    std::cout << minRemoveToMakeValid("))((") << std::endl;
    return 0;
}