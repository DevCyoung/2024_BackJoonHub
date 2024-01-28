#include <iostream>
#include <string>

int main()
{
    std::string str;
    
    str.reserve(1000);
    
    std::cin >> str;
    
    int cnt;
    
    std::cin >> cnt;
    
    std::cout << str[cnt - 1] << std::endl;
    
    return 0;
}