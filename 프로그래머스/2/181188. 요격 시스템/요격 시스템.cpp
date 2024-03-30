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
    sort(targets.begin(), targets.end(), compare);
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
            ++idx;
        }        
    }
    return answer;
}