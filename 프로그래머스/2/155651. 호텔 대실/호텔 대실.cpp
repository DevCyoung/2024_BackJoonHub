#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int toMinute(const string& str)
{
    int minute = 0;
    
    minute = str[0] - '0';
    minute = minute * 10 + (str[1] - '0');
    minute *= 60;
    
    minute += (str[3] - '0') * 10;
    minute += (str[4] - '0');

    return minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> time_table;
    
    for (const vector<string>& books : book_time)
    {
        time_table.push_back({toMinute(books[0]), toMinute(books[1])});
    }
    
    sort(time_table.begin(), time_table.end());    
    vector<int> rooms;
    
    for (auto& times : time_table)
    {                
        bool flag = true;
        for (int i = 0; i < rooms.size(); ++i)
        {
            if (rooms[i] + 10 <= times.first)
            {
                flag = false;
                rooms[i] = times.second;
                break;
            }
        }
        
        if (flag)
        {
            rooms.push_back(times.second);            
        }
    }

    return rooms.size();
}