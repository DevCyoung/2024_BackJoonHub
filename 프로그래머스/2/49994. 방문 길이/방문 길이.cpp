#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string dirs) {
    int answer = 0;    
    int x = 0;
    int y = 0;            
    map<string, bool> visited;    

    for (char dir : dirs)
    {
        int nx = x;
        int ny = y;
        
        switch (dir)
        {
        case 'U':
            ++ny;
            break;
        case 'D':
            --ny;
            break;
        case 'R':
            ++nx;                
            break;
        case 'L':
            --nx;
            break;
        }
        
        if (nx > 5 || nx < -5 || ny > 5 || ny < -5)
        {
            continue;
        }

        pair<int, int> p1 = {x, y};
        pair<int, int> p2 = {nx, ny};
        x = nx;
        y = ny;

        string temp = "";        
        if (p1.first > p2.first || p1.second > p2.second)
        {
            pair<int, int> temp = p1;
            p1 = p2;
            p2 = temp;
        }
        temp += to_string(p1.first);
        temp += to_string(p1.second);
        temp += to_string(p2.first);
        temp += to_string(p2.second);
        if (visited[temp] == false)
        {
            ++answer;
            visited[temp] = true;
        }        
    }
    
    return answer;
}