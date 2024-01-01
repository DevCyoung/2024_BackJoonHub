#include <iostream>

int strlen(const char* str)
{
    int len = 0;
    
    while (*str)
    {
        ++len;
        ++str;
    }
    
    return len;
}

int isPalindrom(const char* const str)
{
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[101];    
    std::cin >> str;    
    std::cout << isPalindrom(str) << std::endl;
    return 0;
}