#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int array[200001] = {0,};
    int answer = nums.size() / 2;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        int index = nums[i];        
        ++array[index];
    }
    
    int size = 0;
    for (int i = 0; i < 200000; ++i)
    {
        if (array[i])
        {
            ++size;
        }
    }
    
    if (size < answer)
    {
        answer = size;
    }
    
    return answer;
}