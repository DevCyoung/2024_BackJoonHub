#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int s, e;                
        std::cin >> s >> e;
        
        float range = e - s;
        float fmax = std::sqrt(range);
        float imax = (float)((int)fmax);

        if (imax == fmax)
        {
            std::cout << ((int)imax) * 2 - 1<< std::endl;
        }                        
        else if (range <= imax * imax + imax)
        {
            std::cout << ((int)imax) * 2 << std::endl;
        }
        else
        {
            std::cout << ((int)imax) * 2 + 1 << std::endl;
        }
    }
}