#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool bGroups[101] = {false,};

void get_group(const vector<int>& cards, const int box, vector<int>& outGroup)
{
    if (bGroups[box])
    {                
        return ;
    }
    
    bGroups[box] = true;
    outGroup.push_back(box);
    get_group(cards, cards[box - 1], outGroup);
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> groupCounts;
    groupCounts.reserve(100);
    
    for (int i = 0; i < cards.size(); ++i)
    {
        const int box = cards[i];
        if (bGroups[box])
        {
            continue;
        }
        std::vector<int> group;
        group.reserve(100);
        get_group(cards, box, group);
        groupCounts.push_back(group.size());
    }    
    std::sort(groupCounts.rbegin(), groupCounts.rend());    
    if (groupCounts.size() < 2)
    {
        answer = 0;
    }
    else
    {
        answer = groupCounts[0] * groupCounts[1];
    }    
    return answer;
}