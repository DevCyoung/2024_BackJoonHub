#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool check(int a, int b)
{
    int alens[3] = {a * 2, a * 3, a * 4};    
    int blens[3] = {b * 2, b * 3, b * 4};
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (alens[i] == blens[j])
                return true;
        }
    }
        
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    long long weight_counts[1001] = {0,};
    for (long long i = 0; i < weights.size(); ++i)
        ++weight_counts[weights[i]];
    
    for (int i = 0; i < 1001; ++i)
    {
        if (weight_counts[i] == 0)        
            continue;        
        else if (weight_counts[i] > 1)
            answer += (weight_counts[i] * (weight_counts[i] -1)) / 2;        
        for (int j = i + 1; j < 1001; ++j)
        {
            if (weight_counts[j] == 0)
                continue;            
            if (check(i, j))
                answer += weight_counts[i] * weight_counts[j];
        }
    }
    return answer;
}