#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
map<string, int> table;
int cosMax[50];

void recv(const string order, int d, string str)
{
    for (int i = d; i < order.size(); ++i)
    {
        string temp = str + order[i];        
        ++table[temp];
        if (cosMax[temp.length()] < table[temp])
        {
            cosMax[temp.length()] = table[temp];
        }
        recv(order, i + 1, temp);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    memset(cosMax, 0, sizeof(cosMax));

    for (string order : orders)
    {
        std::sort(order.begin(), order.end());
        recv(order, 0, "");
    }
    
    vector<pair<string, int>> temps[50];
    for (auto& p : table)
    {
        temps[p.first.length()].push_back(p);
    }
    
    for (int item : course)
    {
        for (auto& p : temps[item])
        {
            if (p.second > 1 && cosMax[item] == p.second)
            {
                answer.push_back(p.first);
            }
        }
    }
    
    std::sort(answer.begin(), answer.end());
    return answer;
}