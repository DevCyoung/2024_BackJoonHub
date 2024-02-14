#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> GetFactors(int num)
{
    vector<int> result;
    
    for (int i = 1; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            result.push_back(i);
            if (i != (num / i))
            {
                result.push_back(num / i);
            }            
        }
    }
    
    return result;
}

int vec_min(const vector<int>& array)
{
    int result = INT_MAX;
    
    for (int item : array)
    {
        if (item < result)
        {
            result = item;
        }
    }
    
    return result;
}

int IsPerfactNum(int num, const vector<int>& mul, const vector<int>& nmul)
{        
    for (int item : mul)
    {
        if (item % num)
        {
            return 0;
        }
    }        
    
    for (int item : nmul)
    {
        if (item % num == 0)
        {
            return 0;            
        }
    }
    
    return num;
}

int GetAnswer(int minNum, const vector<int>& mul, const vector<int>& nmul)
{
    int answer = 0; 
    vector<int> factors = GetFactors(minNum);
    
    for (int item : factors)
    {
        int temp = IsPerfactNum(item, mul, nmul);
        answer = temp > answer ? temp : answer;
    }
    
    return answer;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;    
    int minA = vec_min(arrayA);
    int minB = vec_min(arrayB);
    
    int answer1 = GetAnswer(minA, arrayA, arrayB);    
    int answer2 = GetAnswer(minB, arrayB, arrayA);
    
    answer = answer1 > answer2 ? answer1 : answer2;
    
    
    return answer;
}