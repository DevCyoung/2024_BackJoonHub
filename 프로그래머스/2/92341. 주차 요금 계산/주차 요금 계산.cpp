#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int getTime(string time)
{
    int hour = std::atoi(time.substr(0, 2).c_str());
    int miniute = std::atoi(time.substr(3, 2).c_str());

    return hour * 60 + miniute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int base_time = fees[0];
    int base_fee = fees[1];
    int per_miniute = fees[2];
    int per_fee = fees[3];
    map<string, string> record_table;
    map<string, int> time_table;
    for (const string& record : records)
    {
        string time = record.substr(0, 5);        
        string id = record.substr(6, 4);
        map<string, string>::iterator iter = record_table.find(id);

        if (iter == record_table.end())
        {
            record_table.insert(make_pair(id, time));
            continue;
        }
        record_table.erase(iter);        
        time_table[id] += getTime(time) - getTime(iter->second);
    }

    for (auto& p : record_table)
    {
        time_table[p.first] += getTime("23:59") - getTime(p.second);
    }

    for (auto& p : time_table)
    {
        int price = base_fee;
        if (p.second > base_time)
        {
            int per_time = (p.second - base_time + per_miniute - 1) / per_miniute;
            price += per_time * per_fee;            
        }
        answer.push_back(price);        
    }
    return answer;
}