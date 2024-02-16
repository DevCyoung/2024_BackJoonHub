#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        int a;
        int b;
        std::cin >> a >> b;
        
        int temp = 1;
        for (int j = 0; j < b; ++j)
        {
            temp *= a;            
            temp %= 10;
        }
        if (temp == 0)
        {
            temp = 10;
        }
        std::cout << temp << std::endl;
    }
}