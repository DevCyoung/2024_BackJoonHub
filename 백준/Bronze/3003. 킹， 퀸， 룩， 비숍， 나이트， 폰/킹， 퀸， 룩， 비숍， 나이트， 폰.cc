#include <iostream>

int main()
{
    int chess[6] = {1, 1, 2, 2, 2, 8};
    
    for (int i = 0; i < 6; ++i)
    {        
        int n = 0;
        std::cin >> n;
        chess[i] -= n;
    }
    
    for (int i = 0; i < 6; ++i)
    {
        std::cout << chess[i] << " ";
    }
    
    return 0;
}