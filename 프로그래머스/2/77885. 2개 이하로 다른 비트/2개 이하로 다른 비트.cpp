#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
            
    for(long long item : numbers)
    {                   
        for (int i = 0; i < 64; ++i)
        {
            if ((item & ((long long)1 << i)) == 0)
            {
                item |= ((long long)1 << i);
                
                if (i != 0)
                {
                    item &= ~((long long)1 << (i - 1));
                }

                answer.push_back(item);
                break;
            }                        
        }                
    }
    
    
    return answer;
}