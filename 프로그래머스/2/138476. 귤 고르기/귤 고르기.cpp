#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    
    int answer = 0;    
    vector<int> vec;
    map<int, int> tanMap;    
    
    for (int item : tangerine)
    {
        ++tanMap[item];
    }
    
    map<int, int>::iterator iter = tanMap.begin();
    
    for (; iter != tanMap.end(); ++iter)
    {
        vec.push_back(iter->second);
    }
    
    std::sort(vec.begin(), vec.end());
    std::reverse(vec.begin(), vec.end());
    
    for (int item : vec)
    {
        ++answer;
        
        if (k <= item)
        {
            break;
        }
        
        k -= item;
    }

    return answer;
}