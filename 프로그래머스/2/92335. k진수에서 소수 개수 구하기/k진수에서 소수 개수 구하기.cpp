#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(unsigned long long n)
{
    if (n <= 1)
    {
        return false;
    }
    
    for (unsigned long long i = 2; i * i <= n; ++i)
    {        
        if (n % i == 0)
        {        
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    while (n)
    {
        num += (n % k) + '0';
        n /= k;
    }

    std::reverse(num.begin(), num.end());
    std::cout << num << std::endl;
    
    int i = 0;
    while (i < num.length())
    {
        unsigned long long temp = 0;
        for (;i < num.length(); ++i)
        {
            if (num[i] == '0')
            {
                break;
            }
            temp = temp * 10 + (num[i] - '0');
        }
        
        for (;i < num.length(); ++i)
        {
            if (num[i] != '0')
            {
                break;
            }
        }
        
        if (isPrime(temp))
        {
            ++answer;
        }
    }
    
    return answer;
}