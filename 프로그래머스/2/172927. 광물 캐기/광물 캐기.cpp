#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;
int answer = INT_MAX;
int fatigues[3][3] = {
    {1,  1, 1},
    {5,  1, 1},
    {25, 5, 1}
};

bool isValid(const vector<int>& picks)
{
    return picks[0] == 0 && picks[0] == picks[1] && picks[1] == picks[2];
}

void recv(vector<int> picks, vector<int> minerals, int point)
{
    if (minerals.empty() || isValid(picks) || point > answer)
    {        
        if (point < answer)        
            answer = point;        
        return ;
    }
    for (int i = 0; i < picks.size(); ++i)
    {
        if (picks[i] <= 0)        
            continue;        
        vector<int> tm = minerals;
        int tp = point;
        int j = 0;                    
        while (!tm.empty() && j < 5)                
        {            
            tp += fatigues[i][tm.back()];
            tm.pop_back();     
            ++j;
        }        
        --picks[i];
        recv(picks, tm, tp);
        ++picks[i];
    }
}

int solution(vector<int> picks, vector<string> minerals) 
{    
    std::reverse(minerals.begin(), minerals.end());
    vector<int> iminerals;
    iminerals.reserve(minerals.size());    
    for (int i = 0; i < minerals.size(); ++i)
    {
        if (minerals[i][0] == 'd')        
            iminerals.push_back(0);        
        else if (minerals[i][0] == 'i')        
            iminerals.push_back(1);        
        else        
            iminerals.push_back(2);        
    }        
    recv(picks, iminerals, 0);    
    if (answer == INT_MAX)    
        answer = 0;
    return answer;
}