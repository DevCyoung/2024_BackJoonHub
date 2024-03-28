#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool bGroups[101] = {false,};

int get_group_size(const vector<int>& cards, const int box)
{
    if (bGroups[box])
        return 0;
    bGroups[box] = true;    
    return get_group_size(cards, cards[box - 1]) + 1;
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> groupCounts;
    groupCounts.reserve(100);
    
    for (int i = 0; i < cards.size(); ++i)
    {
        const int box = cards[i];
        if (bGroups[box])
            continue;
        int group_size = get_group_size(cards, box);
        groupCounts.push_back(group_size);
    }    
    std::sort(groupCounts.rbegin(), groupCounts.rend());    
    if (groupCounts.size() < 2)
        answer = 0;
    else
        answer = groupCounts[0] * groupCounts[1];
    return answer;
}