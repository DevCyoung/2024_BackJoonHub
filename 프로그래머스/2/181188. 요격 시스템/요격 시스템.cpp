#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(std::vector<int>& a, std::vector<int>& b)
{
    if (a[0] < b[0])
    {
        return true;
    }    
    else if (a[0] == b[0] && a[1] < b[1])
    {        
        return true;
    }
    
    return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    
    // for (auto& item : targets)
    // {
    //     std::cout << item[0] << "," << item[1] << " ";
    // }
    // std::cout << std::endl;
    
    int idx = 0;
    while (idx < targets.size())
    {
        vector<int> pick = targets[idx++];
        ++answer;
        for (int i = idx; i < targets.size(); ++i)
        {
            if (pick[1] <= targets[i][0])
            {
                break;
            }
            
            pick[1] = std::min(pick[1], targets[i][1]);            
            //pick = targets[i];
            ++idx;
        }        
    }
    
    return answer;
}