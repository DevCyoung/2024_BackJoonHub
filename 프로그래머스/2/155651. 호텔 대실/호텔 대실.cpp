#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int toMinute(const string& str)
{
    int hour   = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());    
    vector<int> rooms;

    for (auto& times : book_time)
    {                
        bool find_room = false;
        int start_time = toMinute(times[0]);
        int end_time = toMinute(times[1]);
        for (int i = 0; i < rooms.size(); ++i)
        {
            if (rooms[i] + 10 <= start_time)
            {
                find_room = true;
                rooms[i] = end_time;
                break;
            }
        }

        if (!find_room)
        {
            rooms.push_back(end_time);
        }
    }

    return rooms.size();
}