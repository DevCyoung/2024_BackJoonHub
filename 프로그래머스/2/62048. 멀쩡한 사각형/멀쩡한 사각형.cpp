#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return gcd(b % a, a);
}
long long solution(int w,int h) 
{
    long long size = (long long)w + (long long)h - gcd(w, h);
    return (long long)w * (long long)h - size;
}