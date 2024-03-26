#include <string>
#include <vector>

using namespace std;

unsigned long long get_mul_min(long long num)
{                     
    long long ret = 1;
    for (long long i = 2; i * i <= num; ++i)
    {        
        if (0 == num % i)
        {
            ret = i;
            
            if (num / i <= 10000000)
            {
                return num / i;
            }                        
        }
    }
    return ret;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    answer.reserve(end - begin + 1);
    if (begin == 1)
    {
        answer.push_back(0);
        ++begin;
    }
    for (; begin <= end; ++begin)
    {
        answer.push_back(get_mul_min(begin));   
    }
    return answer;
}