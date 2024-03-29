#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int get_min_move(const int step_dir, const int back_dir, const string& name)
{
    int cursor = 0;
    int move_count = 0;
    int min = INT_MAX;    
    string hi_score_name(name.size(), 'A');

    while (hi_score_name != name)
    {   
        if (hi_score_name[cursor] != name[cursor])
        {            
            hi_score_name[cursor] = name[cursor];
        }                
        string temp = hi_score_name;
        int move_count_temp = move_count;
        int temp_cursor = cursor;        
        while (temp != name)
        {
            temp_cursor += back_dir;
            ++move_count_temp;
            
            if (temp_cursor < 0)
            {
                temp_cursor = name.size() - 1;
            }
            else if (temp_cursor >= name.size())
            {
                temp_cursor = 0;
            }
            
            temp[temp_cursor] = name[temp_cursor];
        }
        
        if (move_count_temp < min)
        {
            min = move_count_temp;
        }
                
        cursor += step_dir;
        ++move_count;
        
        if (cursor < 0)
        {
            cursor = name.size() - 1;
        }
        else if (cursor >= name.size())
        {
            cursor = 0;
        }                
    }   
    
    
    if (min == INT_MAX)
    {
        min = 0;
    }
    
    return min;
}

int solution(string name) {
    int answer = 0;
    
    for (char item : name)
    {
        answer += min(item - 'A' , 'Z' - item + 1);
    }

    answer += min(get_min_move(1, -1, name), get_min_move(-1, 1, name));
    return answer;
}