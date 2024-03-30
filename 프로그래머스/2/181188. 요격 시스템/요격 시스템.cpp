#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(std::vector<int>& a, std::vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int idx = 0;
    sort(targets.begin(), targets.end(), compare);        
    while (idx < targets.size())
    {
        //기준범위선택
        vector<int> range = targets[idx++];
        ++answer;
        for (int i = idx; i < targets.size(); ++i)
        {
            //기준범위 벗어남
            if (range[1] <= targets[i][0])
            {
                break;
            }
            
            //기준범위를 좁혀나간다.
            range[1] = std::min(range[1], targets[i][1]);            
            ++idx;
        }        
    }
    
    return answer;
}