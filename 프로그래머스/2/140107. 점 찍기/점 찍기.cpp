#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long sd = (long long)d * (long long)d;    
    vector<long long> anums;
    
    for (long long i = 0; i * i <= sd; i += k)
    {
        anums.push_back(i);
    }
    
    vector<long long> bnums = anums;
    for (int i = 0; i < anums.size(); ++i)
    {
        while (!bnums.empty())
        {
            long long len = anums[i] * anums[i] + bnums.back() * bnums.back();
            if (len <= sd)
            {                
                break;
            }
            
            bnums.pop_back();
        }
        
        answer += bnums.size();
    }
    
    return answer;
}