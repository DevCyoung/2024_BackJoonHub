#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int w,int h) 
{
    long long scale = (long long)w * (long long)h;
    double inclination = (double)max(w, h) / (double)min(w,h);
    long long step = (long long)inclination;    
    if (floor(inclination) > 0)
    {
        ++step;        
    }
    return scale - step * min(w, h);
}