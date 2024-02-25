#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int w,int h) 
{
    long long answer = 0;
    if (w > h)
    {
        int temp = h;
        h  = w;
        w = temp;
    }
    
    for (long long x = 0; x < w; ++x)        
    {     
        long long ly = x * h / w;
        long long ry = (h*(x+1) + w - 1) / w;
        answer += ry - ly;
    }    
    return (long long)w * (long long)h - answer;
}